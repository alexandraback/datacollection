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
int main()
{
    int T;
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&T);
    For(ca,T)
    {
        int n;
        int x=0;
        int s[250];
        scanf("%d",&n);
        For(i,n)
        {
            scanf("%d",s+i);
            x+=s[i];
        }
        printf("Case #%d:",1+ca);
        For(i,n)
        {
            double low = 0,high = 1;
            double rate;
            while(high-low>eps)
            {
                rate = (low+high)/2;
                double sc = s[i] + x*rate;
                double left = 1 -rate ;
                For(j,n){
                    if(i==j)continue;
                    if(s[j]>sc) continue;
                    left -= (sc - s[j])/x;
                }
                if(left < 0)
                    high = rate;
                else
                    low =rate;

            }
            printf(" %.8lf",rate*100);
        }
        printf("\n");
    }
}
