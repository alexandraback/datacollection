#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
using namespace std;
#define inf 0x3fffffff
double ans;
double C,F,X;

int main(){
    freopen("B-large.in","r",stdin);
    freopen("BL.out","w",stdout);
    int T,cas=0; scanf("%d",&T);
    while(T--){
        scanf("%lf%lf%lf",&C,&F,&X);
        ans=inf;
        int n=max(0,(int)((X*F-2*C)/(C*F)));
        ans=0;
        for(int i=0;i<n;i++){
            ans+=C/(2+i*F);
        }
        ans+=X/(2+n*F);
        ans=min(ans,X/2);
        printf("Case #%d: %lf\n",++cas,ans);
    }
    return 0;
}
