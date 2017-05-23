#include <cstdio>
#include <algorithm>
#include <set>
#include <ctime>
#define SZE (16)

using namespace std;

set <long long> vals;

long long primes[100005];
int cntpr;

bool testprime(long long val)
{
    for (int i=0; i<cntpr; i++)
        if (primes[i]!=val && val%primes[i]==0)
            return false;
    return true;
}

int main()
{
    freopen("D:/out.txt","w",stdout);
    printf("Case #1:\n");
    for (int i=2; i<(1<<16)+1000; i++)
        if (testprime(i))
        {
            primes[cntpr]=i;
            cntpr++;
        }
    FILE *save;
    save=fopen("D:/outsave.txt","w");
    srand(time(0));
    while (vals.size()<50)
    {
        long long tr=rand();
        tr|=1;
        tr|=1ll<<15;
        if (vals.find(tr)!=vals.end())
            continue;
        int ok=1;
        for (int bs=2; bs<=10; bs++)
        {
            long long val=0;
            long long ex=1;
            for (int bit=0; bit<SZE; bit++)
            {
                if (tr&(1ll<<bit))
                    val+=ex;
                ex*=bs;
            }
            if (testprime(val))
            {
                ok=0;
                break;
            }
        }
        if (ok)
        {
            vals.insert(tr);
            for (int i=SZE-1; i>=0; i--)
                printf(tr&(1<<i)?"1":"0");
            printf(" ");
            for (int bs=2; bs<=10; bs++)
            {
                long long val=0;
                long long ex=1;
                for (int bit=0; bit<SZE; bit++)
                {
                    if (tr&(1ll<<bit))
                        val+=ex;
                    ex*=bs;
                }
                for (int i=0; i<cntpr; i++)
                    if (val%primes[i]==0)
                    {
                        printf("%lld ",primes[i]);
                        break;
                    }
            }
            printf("\n");
            fprintf(save,"%lld\n",tr);
            fflush(save);
        }
    }
}
