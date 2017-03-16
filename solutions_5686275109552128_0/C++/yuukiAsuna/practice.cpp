#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#define PB push_back
#define MP make_pair
#define INF 0x7fffffff
using namespace std;
typedef long long LL;
const int maxn=1005;
int a[maxn];
int main()
{
         freopen("B-small-attempt1.in","r",stdin);
         freopen("B-small-attempt1.out","w",stdout);
         int T,ca=0;
         scanf("%d",&T);
         while(T--){
                   int n,_max=-1;
                   scanf("%d",&n);
                   for(int i=0;i<n;i++){
                           scanf("%d",&a[i]);
                           _max=max(_max,a[i]);
                   }
                   sort(a,a+n);
                   /*
                   printf("%d\n",n);
                   for(int i=0;i<n;i++){
                           printf("%d ",a[i]);
                   }
                   puts("");
                   */
                   int ans=_max;
                   for(int low=1;low<=_max;low++){
                           int pos=upper_bound(a,a+n,low)-a;
                           int now=low;
                           for(int i=pos;i<n;i++){
                                    now+=(a[i]%low)?(a[i]/low):(a[i]/low-1);
                           }
                           ans=min(ans,now);
                   }
                   printf("Case #%d: %d\n",++ca,ans);
         }
         return 0;
}
