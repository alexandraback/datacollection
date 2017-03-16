#include <iostream>
#include <stdio.h>
#include <map>
#include <cstdlib>
#include <vector>
using namespace std;

map< vector<int>,vector<int> > mymap;;
map< vector<int>,vector<int> >::iterator myit;

vector<int> seq;
vector<int> proof;

int N=16;
int J=50;

vector<int> Primes;

bool IsPrime(int k)
{
    int i;

    for (i=2;i*i<=k;i++)
    {
        if (k%i==0)
        return false;
    }

    return true;
}

bool PrimeCheck()
{
    int i,j;
    int multi;
    int ans;
    int p;

    proof.clear();

    for (i=2;i<=10;i++)
    {
        for (p=0;p<Primes.size();p++)
        {
            multi=1;
            ans=0;

            for (j=(int)seq.size()-1;j>=0;j--)
            {
                ans+=multi*seq[j];
                ans%=Primes[p];

                multi*=i;
                multi%=Primes[p];
            }

            if (ans==0)
            break;
        }

        if (p==Primes.size())
        {
            return true;
        }

        proof.push_back(Primes[p]);
    }

    return false;
}

vector<int> cp;

int main()
{
    freopen("C-output.out","w",stdout);

    int i,j;

    for (i=2;i<=10000;i++)
    {
        if (IsPrime(i))
        {
            Primes.push_back(i);
        }
    }

    while(mymap.size()<J)
    {
        seq.clear();

        seq.push_back(1);

        for (i=1;i<=N-2;i++)
        {
            seq.push_back(rand()%2);
        }

        seq.push_back(1);

        if (!PrimeCheck())
        {
            mymap.insert( make_pair(seq,proof) );
        }
    }

    printf("Case #1:\n");

    for (myit=mymap.begin();myit!=mymap.end();myit++)
    {
        cp=(*myit).first;

        for (i=0;i<cp.size();i++)
        {
            printf("%d",cp[i]);
        }

        cp=(*myit).second;

        for (i=0;i<cp.size();i++)
        {
            printf(" %d",cp[i]);
        }
        printf("\n");
    }

    return 0;
}
