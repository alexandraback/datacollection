#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define INF 0x3f3f3f3f
#define DINF 1e100
#define EPS 1e-15
#define PII acos(-1)
#define LL long long
#define Pii pair<int,int>
#define For(i,n) for(int i=0;i<n;i++)
#define ileer(n) scanf("%d",&n)
#define fleer(n) scanf("%f",&n)
#define MK make_pair
#define PB push_back
#define llenar(arr,val) memset(arr,val,sizeof(arr))
#define maxn 10000

using namespace std;

int main() {
    freopen("in2.txt", "r", stdin);
  freopen("2.txt", "w", stdout);
    
 int a[maxn];
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        int max_x=0,n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            max_x=max(max_x,a[i]);
        }
        int ans=max_x;
        for(int i=1;i<=max_x;i++)
        {
            int now=0,maxx=0;
            for(int j=1;j<=n;j++)
            {
                if(a[j]>i)
                {
                    now += (a[j] / i)+((a[j]%i==0)?0:1)-1;
                    maxx=max(maxx,i);
                }
                else maxx=max(maxx,a[j]);
            }
            now+=maxx;
            if(now<ans)ans=now;
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
