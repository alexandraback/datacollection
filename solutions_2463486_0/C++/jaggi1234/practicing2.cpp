#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<utility>
#include<cassert>
#include<ctime>
#define debug(i) cout<<#i" = "<<i<<"\n";system("pause");
#define SET(p) memset(p,-1,sizeof(p))
#define CLR(p) memset(p,0,sizeof(p))
#define S(n) scanf("%d",&n)
#define P(n) printf("%d\n",n)
#define Sl(n) scanf("%lld",&n)
#define Pl(n) printf("%lld\n",n)
#define Sf(n) scanf("%lf",&n)
#define Ss(n) scanf("%s",n)
#define LL long long
#define ULL unsigned long long
#define pb push_back
using namespace std;
vector<bool> sieve(1001,0);
void createsieve()
{
    sieve[1]=sieve[4]=sieve[9]=sieve[121]=sieve[484]=1;
}
int main()
{
    register int i;
    int t,low,high,counter=1;
    scanf("%d",&t);
    createsieve();
    while(t--)
    {
        int count=0;
        scanf("%d%d",&low,&high);
        cout<<"Case #"<<counter++<<": ";
        for(i=low;i<=high;i++)
        {
            if(sieve[i])
                count++;
        }
        cout<<count<<"\n";
    }
}
