#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
using namespace std;

#define NUM_PRIMES 100000
bool sieve[NUM_PRIMES];
vector<long long int> primes;
vector<long long int> jamcoins;
vector<long long int*> proof;

long long int powers[11][32];

string binaryString(long long int x)
{
    string s;
    while(x)
    {
        s.insert(s.begin(), (x&1)?'1':'0');
        x>>=1;
    }
    return s;
}
long long int composite(long long int x)
{
    for(vector<long long int>::iterator it = primes.begin(); it < primes.end(); it++)
    {
        if(x%*it==0) return *it;
    }
    return 0;
}
int main()
{
    memset(sieve, true, sizeof(sieve));
    sieve[1] = false;
    for(long long int i = 2; i < sqrt(NUM_PRIMES)+2; i++)
    {
        if(sieve[i])
        {
            primes.push_back(i);
            for(long long int j = i+i; j < NUM_PRIMES; j+=i)
            {
                sieve[j] = false;
            }
        }
    }
    for(long long int i = 2; i <= 10; i++)
    {
        powers[i][0] = 1;
        for(int j = 1; j < 32; j++)
            powers[i][j] = powers[i][j-1]*i;
    }
    int T, N, J;
    cin >> T >> N >> J;
    
    long long int *factors = new long long int[9];
    for(long long int x = (1 << (N-1)) + 1; jamcoins.size() < J; x+=2)
    {
        if(factors[0] = composite(x))
        {
            for(int i = 3; i <= 10; i++)
            {
                long long int val = 0;
                for(int j = 0; j < 16; j++) 
                {
                    if(x&(1<<j))
                        val+=powers[i][j];
                }

                if(!(factors[i-2] = composite(val)))
                    goto notcomposite;
            }
            jamcoins.push_back(x);
            proof.push_back(factors);
            factors = new long long int[9];
//            cout << "got one" << endl;
        }
notcomposite:;
    }

    cout << "Case #1:" << endl;
    for(int i = 0; i < J; i++)
    {
        cout << binaryString(jamcoins[i]);
        for(int j = 0; j < 9; j++)
            cout << ' ' << proof[i][j];
        cout << endl;
        /*
        printf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld\n",
                jamcoins[i], proof[i][0], proof[i][1], proof[i][2], 
                proof[i][3], proof[i][4], proof[i][5], proof[i][6], proof[i][7], proof[i][8]);
                */
    }

    while(!proof.empty())
    {
        delete proof.back();
        proof.pop_back();
    }
}
