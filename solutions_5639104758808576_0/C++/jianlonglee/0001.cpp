#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>

#define ll long long
#define maxn 1005
#define inf 0x3f3f3f3f
#define bug puts("here")

using namespace std;

int T,n,m,a[maxn];
char ch[maxn];

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small.out","w",stdout);
   cin>>T;
   int kase=1;
   while(T--){
    scanf("%d %s",&n,ch);
    for(int i=0;i<=n;++i)
        a[i]=ch[i]-'0';
    int t=0;
    for(int i=1;i<=n;++i)
        if(a[i-1]>=i)
            a[i]+=a[i-1];
        else t+=i-a[i-1],a[i]+=i;
    printf("Case #%d: %d\n",kase++,t);
   }
}
