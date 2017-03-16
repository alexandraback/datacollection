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
char ss[maxn];
int main()
{
         freopen("A-small-attempt0.in","r",stdin);
         freopen("A-small-attempt0.out","w",stdout);
         int T,ca=0;
         scanf("%d",&T);
         while(T--){
                  int S;
                  scanf("%d %s",&S,ss);
                  int sum=ss[0]-'0',ans=0;
                  for(int i=1;i<=S;i++){
                           if(i<=sum) {
                                    sum+=ss[i]-'0';
                           }
                           else ans+=(i-sum),sum=i+ss[i]-'0';
                  }
                  printf("Case #%d: %d\n",++ca,ans);
         }
         return 0;
}
