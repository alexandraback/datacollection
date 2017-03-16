#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <string>
#include <set>

using namespace std;

const int N = 32, J = 500;
const int P = 10000;

int primes[P], prime_list[P], pcnt;

void init_primes()
{
    primes[0] = 0;
    primes[1] = 0;
    pcnt = 0;
    for(int i = 2; i < P; ++i)
        primes[i] = 1;
    for(int i = 2; i < P; ++i)
    {
        if(!primes[i])
            continue;
        prime_list[pcnt++] = i;
        for(int j = i + i; j < P; j += i)
            primes[j] = 0;
    }
}

const int NPRIM = 1300;
// pcnt roughly 10k
// i,j,k : i^j mod prime_list[k]
int modules[11][N][NPRIM] = {0};
void init_modules()
{
    for(int k = 0; k < pcnt; ++k)
    {
        int MOD = prime_list[k];
        for(int i = 2; i <= 10; ++i)
        {
            modules[i][0][k] = 1 % MOD;
            for(int j = 1; j < N; ++j)
            {
                modules[i][j][k] = modules[i][j-1][k] * i;
                modules[i][j][k] %= MOD;
            }
        }
    }
}

set<string> db;

int digits[1000] = {0}; // 0 for LEAST significant

void dfs(int pos)
{
    if(pos == N)
    {
        int divisors[20] = {0};
        for(int i = 2; i <= 10; ++i)
        {
            bool valid = false;
            for(int k = 0; k < pcnt; ++k)
            {
                int mod = 0;
                for(int j = 0; j < N; ++j)
                {
                    mod += modules[i][j][k] * digits[j];
                    mod %= prime_list[k];
                }
                if(mod == 0)
                {
                    valid = true;
                    divisors[i] = prime_list[k];
                    break;
                }
            }
            if(!valid)
                return;
        }
        string ret = "";
        for(int i = N-1; i >= 0; --i)
            ret += digits[i] ? "1" : "0";
        if(db.find(ret) == db.end())
        {
            db.insert(ret);
            printf("%s", ret.c_str());
            for(int i = 2; i <= 10; ++i)
                printf(" %d", divisors[i]);
            printf("\n");
        }
        return;

    }
    int dig = rand() % 2;
    if(pos == 0 || pos == N-1)
        dig = 1;
    digits[pos] = dig;
    dfs(pos + 1);
}


int main()
{
    srand( time(0) );
    init_primes();
    init_modules();
    puts("Case #1:");
    while( db.size() != J )
        dfs(0);
    return 0;
}
