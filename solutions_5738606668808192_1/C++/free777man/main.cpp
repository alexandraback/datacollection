#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define FOR(i,s,n) for(int i=(s);i<(n);++i)
#define REP(i,n) FOR(i,0,(n))
#define PB(x) push_back((x))
#define CLR(a,v) memset((a),(v),sizeof((a)))
typedef long long ll;

int const MXN = 105419256, MXP=6055429;
char p[MXN];
int primes[MXP], pc;
ll p2[MXP];

void solve()
{
    CLR(p,1);
    p[0]=p[1]=0;
    for(int i=2;i*i<MXN;++i)if(p[i])
        for(int j=i*i;j<MXN;j+=i)p[j]=0;

    pc=0;
    REP(i,MXN)if(p[i])primes[pc++]=i;
    REP(i,pc)p2[i]=primes[i]*1LL*primes[i];

    int n,m,d[11];
    scanf("%d %d",&n,&m);

    n /= 2;

    int mx = 1<<(n-1), cnt=0;
    printf("\n");
    for(int mask = 1; mask < mx; mask += 2)
    {
        FOR(base,2,11)
        {
            ll x = 1;
            for(int i=n-2;i>=0;--i)
            {
                x*=base;
                if(mask&(1<<i))x+=1;
            }

            for(int i = 0; i < pc && p2[i] <= x; ++i)if(x%primes[i]==0)
            {
                d[base] = primes[i];
                goto nextbase;
            }

            goto nextmask;
            nextbase:;
        }

        REP(tt,2)
        {
            printf("1");
            for(int i=n-2;i>=0;--i)printf((mask&(1<<i))?"1":"0");
        }

        REP(i,9)printf(" %d",d[i+2]);
        printf("\n");
        --m;
        if(m==0)return;

        nextmask:;
    }
}


int main()
{
    //freopen("../input.txt", "r", stdin);
    freopen("../data/C-large.in", "r", stdin);
    freopen("../output.txt", "w+", stdout);

    int T;
    scanf("%d", &T);
    REP(i, T)
    {
        printf("Case #%d: ", i+1);
        solve();
    }

    return 0;
}
