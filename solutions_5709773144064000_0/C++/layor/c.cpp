#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define inf 1e18
double ans;
double c,f,x;
int t,ca;

inline void dfs(int n,double sum){
    double now_sum=sum+x/(2+f*(n-1));
    if(now_sum>ans)
        return;
    ans=now_sum;

    dfs(n+1,sum+c/(2+f*(n-1)));
}
int main(){
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B.out","w",stdout);
    scanf("%d",&t);
    ca=1;
    while(t--){
        scanf("%lf%lf%lf",&c,&f,&x);
        ans=inf;
        dfs(1,0);
        printf("case #%d: %lf\n",ca++,ans);
    }
    return 0;
}
