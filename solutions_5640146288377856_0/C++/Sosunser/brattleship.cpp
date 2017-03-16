#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int t,r,c,w;

int main(){
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    scanf("%d",&t);
    for(int j = 1; j <= t; j++){
        scanf("%d%d%d",&r,&c,&w);
        int ans = (r-1)*(c/w);
        ans += (c-w)/(w);
        if(c%w == 0) ans += w;
        else ans += w+1;
        printf("Case #%d: %d\n",j,ans);
    }
}