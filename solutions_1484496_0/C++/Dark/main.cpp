#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <string>
#include <set>
#include <cstring>
using namespace std;
#define For(i,n) for(int i=0;i<n;i++)
#define sz(i) int(i.size())
#define mst(i,n) memset(i,n,sizeof(i))
#define eps 1e-9
#define INF 1e20
#define MOD 1000000007
#define LL long long
#define pi acos(-1)
LL gcd(LL a,LL b)
{
    if(a==0)return b;
    return gcd(b%a,a);
}
int mem[3000000];
int main()
{
    int T;
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&T);
    For(ca,T)
    {
        int n;
        scanf("%d",&n);
        int s[22];
        mst(mem,-1);
        For(i,n)
        {
            scanf("%d",s+i);
        }
        bool fg = 0;
        printf("Case #%d:\n",1+ca);
        For(i,1<<n){
            int t = 0;
            For(j,n)
                if((i>>j)&1)
                    t += s[j];
            if(mem[t]>0&&(mem[t]&i)==0){
                fg  = 1;
                int g=0;
                For(k,n)
                    if( (mem[t]>>k)&1 )
                        printf("%s%d",g++?" ":"",s[k]);
                printf("\n");
                g=0;
                For(k,n)
                    if( (i>>k)&1 )
                        printf("%s%d",g++?" ":"",s[k]);
                printf("\n");
                break;
            }
            mem[t]=i;
        }
        if(!fg)
            printf("Impossible\n");
    }
}
