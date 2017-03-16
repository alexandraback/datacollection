//#include <QtCore>
#include <stdio.h>
#include <gmp.h>
#include <string.h>
// It's actually the first time ever that I use GMP ! :p (looks great though)

static char buffer[256];
static char buffer2[256];

inline bool isDigit(const char &c)
{
    return (c >= '0') && (c <= '9');
}

void fillBuffer()
{
    char *c = buffer;
    while (!isDigit(*c = getchar()));
    while (isDigit(*(++c) = getchar()));
    *c = 0;
}

inline bool isBufferPalindrome(const char *my_buffer, const int &len)
{
    int len_1 = len - 1;
    int max_i = (len + 1) / 2;
    for (int i = 0; i < max_i; ++i)
    {
        if (my_buffer[i] != my_buffer[len_1 - i]) return false;
    }
    return true;
}

bool isPalindrome(const mpz_t &N)
{
    mpz_get_str(buffer2, 10, N);
    return isBufferPalindrome(buffer2, strlen(buffer2));
}

void getNextPalindromeFromP(mpz_t &N)
{
    int i, j, len = strlen(buffer);
    if ((len % 2) && (buffer[len / 2] < '9'))
    {
        ++buffer[len / 2];
        mpz_set_str(N, buffer, 10);
        return;
    }
    for (i = (len / 2) - 1; i >= 0; --i)
    {
        if (buffer[i] < '9')
        {
            ++buffer[i];
            buffer[j = len - 1 - i] = buffer[i];
            while (--j > i) buffer[j] = '0';
            mpz_set_str(N, buffer, 10);
            return;
        }
    }
    buffer[0] = '1';
    for (i = 1; i < len; ++i)
        buffer[i] = '0';
    buffer[len] = '1';
    buffer[len + 1] = 0;
    mpz_set_str(N, buffer, 10);
}

void getNextPalindrome(mpz_t &N)
{
    int len, len_1;
    mpz_get_str(buffer, 10, N);
    len = strlen(buffer);
    if (isBufferPalindrome(buffer, len))
    {
        getNextPalindromeFromP(N);
        return;
    }
    len_1 = len - 1;
    for (int i = (len + 1) / 2; i < len; ++i)
        buffer[i] = buffer[len_1 - i];
    {
        mpz_t N2;
        mpz_init_set_str(N2, buffer, 10);
        if (mpz_cmp(N, N2) < 0)
        {
            mpz_set(N, N2);
            mpz_clear(N2);
            return;
        }
        mpz_clear(N2);
        getNextPalindromeFromP(N);
    }
}

void run()
{
    mpz_t A, B, I, result;
    mpz_init(result);
    fillBuffer();
    mpz_init_set_str(A, buffer, 10);
    fillBuffer();
    mpz_init_set_str(B, buffer, 10);
    mpz_init(I);
    mpz_sqrtrem(A, I, A);
    if (mpz_sgn(I) == 0) mpz_sub_ui(A, A, 1);
    mpz_sqrt(B, B);
    mpz_get_str(buffer, 10, A);
    // Let's look at all the palindromes between A and B, A excluded and B included
    getNextPalindrome(A);
    while (mpz_cmp(A, B) <= 0)
    {
        // Is the square A*A a palindrome ?
        mpz_mul(I, A, A);
        if (isPalindrome(I))
        {
            //printf("Found : %s\n", buffer);
            mpz_add_ui(result, result, 1);
        }
        getNextPalindromeFromP(A);
    }
    mpz_clear(A);
    mpz_clear(B);
    mpz_clear(I);
    mpz_get_str(buffer, 10, result);
    mpz_clear(result);
}

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i)
    {
        run();
        printf("Case #%d: %s\n", i, buffer);
    }
    return 0;
}
