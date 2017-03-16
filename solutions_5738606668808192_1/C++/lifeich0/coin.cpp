#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <set>
using namespace std;

const int sep = 10000;
const int n = 32, K = 500, PL = 1000;
typedef unsigned int uint;

int rec[11],pr[1013];
int cnt;

bool isprime(int i)
{
    for (int j = 2; j * j <= i; ++j)
        if ((i % j) == 0) return false;
    return true;
}

uint geto()
{
    uint x = 1;
    for (int i = 2; i < n; ++i)
        x = (x << 1) + (rand() & 1);
    x = (x << 1) + 1;
    return x;
}

bool check(uint x, int base, int p)
{
    int res = 0;
    for (int m = 1; x > 0; x >>= 1, m = (m * base) % p)
        if (x & 1)
            res = (res + m) % p;
    if (res == 0) 
        rec[base] = p;
    return res == 0;
}

char* show2(uint x)
{
    static char s[35];
    for (int i = 1; i <= n; ++i, x >>= 1)
        s[n - i] = '0' + (x & 1);
    return s;
}

int main()
{
    FILE *fou = fopen("data2.txt", "a");
    srand(time(0));
    for (int i = 3; i < PL; ++i)
        if (isprime(i)) pr[cnt++] = i;

    set<uint> U;
    for (int co = 1; U.size() < K; ++ co)
    {
        uint x = geto();
        if (U.find(x) != U.end()) continue;
        int flag = 1;
        for (int base = 2; base <= 10 && flag; ++base)
        {
            int permit = 0;
            for (int i = 0; i < cnt; ++i)
                if (check(x, base, pr[i])) 
                {
                    permit = 1;
                    break;
                }
            if (!permit) flag = 0;
        }
        if (flag)
        {
            U.insert(x);
            printf("<%s> (%u) flag: %c  #%d\n", show2(x), x, 'Y', co);
            fprintf(fou, "%s", show2(x));
            for (int i = 2; i <= 10; ++i)
                fprintf(fou, " %d", rec[i]);
            fprintf(fou, "\n");
        }
        else if (co % sep == 0)
        {
            printf("<%s> (%u) flag: %c  #%d\n", show2(x), x, 'N', co);
        }
    }
    return 0;
}
