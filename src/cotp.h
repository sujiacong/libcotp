#pragma once
#include <gcrypt.h>

#define SHA1 GCRY_MD_SHA1
#define SHA256 GCRY_MD_SHA256
#define SHA512 GCRY_MD_SHA512

typedef enum _cotp_errno {
    VALID = 0,
    GCRYPT_VERSION_MISMATCH = 1,
    INVALID_B32_INPUT = 2,
    INVALID_ALGO = 3,
    INVALID_OTP = 4
} cotp_error_t;


char *get_hotp (const char *base32_encoded_secret, long counter, int digits, int sha_algo, cotp_error_t *err_code);
char *get_totp (const char *base32_encoded_secret, int digits, int sha_algo, cotp_error_t *err_code);
char *get_totp_at (const char *base32_encoded_secret, long time, int digits, int sha_algo, cotp_error_t *err_code);
int totp_verify (const char *base32_encoded_secret, int digits, const char *user_totp, int sha_algo);
int hotp_verify (const char *base32_encoded_secret, long counter, int digits, const char *user_hotp, int sha_algo);