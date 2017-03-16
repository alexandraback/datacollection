#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <thread>

const int PTS = (1 << 13);
const int TB = 2;
const int TS = (1 << TB);
const int N = 16;
const int J = 50;

using namespace std;

bool isPrime[PTS];
int primeArr[PTS], pc = 0;
unsigned int h[11][1100][32];

void initPrime()
{
    memset(isPrime, 0, sizeof(isPrime));
    for (int i = 2; i < PTS; ++i)   if (!isPrime[i])
    {
        primeArr[pc++] = i;
        for (int j = i + i; j < PTS; j += i)
            isPrime[j] = 1;
    }
}

vector<int> result[TS];

int getReusltSum()
{
    int ret = 0;
    for (int i = 0; i < TS; ++i)
        ret += result[i].size();
    return ret;
}

void solve(int id, int beg, int end)
{
    bool v[N];
    v[N - 1] = v[0] = 1;

    for (int i = beg; i < end; ++i)
    {
        if (getReusltSum() >= J)
            break;

        int num = ((i << TB) | id);
        for (int j = 0; j < N - 2; ++j)
            v[j + 1] = (num & (1 << j)) != 0;

        bool pass = true;
        for (int base = 2; base <= 10; ++base)
        {
            bool ok = false;
            for (int j = 0; !ok && j < pc; ++j)
            {
                int prime = primeArr[j];
                unsigned int sum = 0;
                for (int k = 0; k < N; ++k) if (v[k])
                    sum = (sum + h[base][j][k]) % prime;
                if (sum == 0)
                    ok = true;
            }
            if (ok == false)
                pass = false;
        }

        if (pass)
            result[id].push_back(num);
    }
}

int main()
{
    //freopen("gcj\\B-large.in", "r", stdin);
    freopen("gcj\\C-small.out", "w", stdout);
    
    initPrime();
    for (int i = 1; i < 11; ++i)
    {
        for (int j = 0; j < pc; ++j)
        {
            int prime = primeArr[j];
            h[i][j][0] = 1;
            for (int k = 1; k < 32; ++k)
                h[i][j][k] = (h[i][j][k - 1] * i) % prime;
        }
    }

    thread threads[TS];
    for (int i = 0; i < TS; ++i)
    {
        int a = 0, b = (1 << (N - TB - 2));
        result[i].clear();
        threads[i] = thread(solve, i, a, b);
    }

    for (int i = 0; i < TS; ++i)
        threads[i].join();

    vector<int> res;
    for (int i = 0; i < TS; ++i)
        res.insert(res.end(), result[i].begin(), result[i].end());

    puts("Case #1:");
    for (int i = 0; i < J; ++i)
    {
        bool v[N];
        v[N - 1] = v[0] = 1;

        int num = res[i];
        for (int j = 0; j < N - 2; ++j)
            v[j + 1] = (num & (1 << j)) != 0;

        for (int j = 0; j < N; ++j)
            printf("%d", v[N - j - 1] == 0 ? 0 : 1);
        
        for (int base = 2; base <= 10; ++base)
        {
            bool ok = false;
            for (int j = 0; !ok && j < pc; ++j)
            {
                int prime = primeArr[j];
                unsigned int sum = 0;
                for (int k = 0; k < N; ++k) if (v[k])
                    sum = (sum + h[base][j][k]) % prime;
                if (sum == 0)
                {
                    ok = true;
                    printf(" %d", prime);
                }
            }
        }

        puts("");
    }

    return 0;
}