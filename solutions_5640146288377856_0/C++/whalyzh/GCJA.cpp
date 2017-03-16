#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#define ll long long
#define db double
using namespace std;

int t,n,m,w;
int main()
{
#ifdef Haha
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out","w",stdout);
#endif // Haha
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++){
        scanf("%d%d%d",&n,&m,&w);
        int p=m/w;
        int ans=(n-1)*p;
        if(m%w==0){
            ans+=p-2;
            ans+=w+1;
        }
        else{
            ans+=p-1;
            ans+=w+1;
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
