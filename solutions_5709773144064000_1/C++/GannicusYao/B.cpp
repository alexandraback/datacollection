#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int _;
double C,F,X;

int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&_);
    int cas=0;
    while (_--){
        scanf("%lf%lf%lf",&C,&F,&X);
        double V=2.0,times=0.0,ans=1e9;
        for (int i=0;i<=X;i++){
            ans=min(ans,times+X/V) ;
            times+=C/V;
            V+=F ;
        }
        printf("Case #%d: %.7f\n",++cas,ans);
    }
    return 0;
}
