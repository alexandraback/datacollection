//#include <QtCore>
#include <stdio.h>
#include <gmp.h>
#include <string.h>
// (second time ever that I use GMP :p )

static char buffer[1000001];
static int L, n;

inline bool isConsonant(const char &letter)
{
    return (letter != 'a') && (letter != 'e') && (letter != 'i') && (letter != 'o') && (letter != 'u');
}

void run()
{
    mpz_t res, temp;
    {
        char *reader = buffer;
        L = 0;
        while (*reader = (char) getchar(), (*reader >= 'z') && (*reader <= 'a'));
        while (*reader = (char) getchar(), (*reader <= 'z') && (*reader >= 'a'))
        {
            ++reader;
            ++L;
        }
    }
    scanf("%d", &n);
    mpz_init(res);
    mpz_init(temp);
    int begin_from = 0, has = 0;
    for (int i = 0; i < L; ++i)
    {
        if (isConsonant(buffer[i]))
        {
            if (++has >= n)
            {
                mpz_set_ui(temp, (unsigned long) (i + 2 - begin_from - n));
                mpz_addmul_ui(res, temp, (unsigned long) (L - i));
                begin_from = i + 2 - n;
            }
        } else {
            has = 0;
        }
    }
    mpz_clear(temp);
    mpz_get_str(buffer, 10, res);
    mpz_clear(res);
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
