#include <cstdio>
#include <algorithm>
#include <vector>

#define PB push_back

using namespace std;

typedef long long ll;

const int LIMIT = 1000*1000*100;
int crible[LIMIT];

vector<int> ls_primes;

int main()
{
    freopen("output.txt", "w", stdout);

    for(ll i = 2; i <= LIMIT; i++)
        if(!crible[i])
        {
            ls_primes.PB((int)i);
            for(ll k = i; k*i <= LIMIT; k++)
                crible[k*i] = (int)i;
        }

    int N = 16, J = 50;
    printf("Case #1:\n");
    for(ll i = (1 << (N-1)) + 1; (i < (1 << N)) && J; i += 2)
    {
        vector<int> d;
        ll k = i;
        while(k)
        {
            d.PB((int)(k%2));
            k /= 2;
        }
        reverse(d.begin(), d.end());

        vector<ll> ls_div;
        for(int b = 2; b <= 10; b++)
        {
            ll act = 0;
            for(int j = 0; j < (int)d.size(); j++)
                act = b*act + d[j];

            if(act <= LIMIT)
            {
                if(!crible[act])
                    break;
                ls_div.PB(crible[act]);
            }
            else
            {
                bool ok = true;
                for(int j = 0; j < (int)ls_primes.size(); j++)
                {
                    if(ls_primes[j]*ls_primes[j] > act)
                    {
                        ok = false;
                        break;
                    }
                    if(act%ls_primes[j] == 0)
                    {
                        ls_div.PB(ls_primes[j]);
                        break;
                    }
                }

                if(!ok)
                    break;
            }
        }

        if(ls_div.size() == 9)
        {
            J--;
            for(int j = 0; j < N; j++)
                printf("%c", d[j] + '0');

            for(int j = 0; j < 9; j++)
                printf(" %lld", ls_div[j]);
            printf("\n");
        }
    }

    return 0;
}
