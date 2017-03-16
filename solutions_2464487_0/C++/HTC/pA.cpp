#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<math.h>
using namespace std;
int main (){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("Asamll.txt","w",stdout);
    //freopen("A-large.in","r",stdin);
    //freopen("Alarge.txt","w",stdout);
    int ca,T,ans;
    long long r,t,area;
    scanf("%d",&T);
    for(ca = 1;ca <= T;ca++){
        scanf("%lld%lld",&r,&t);
        ans = 0;
        while(t > 0){
            area = 2*r+1;
            if(t - area >= 0)ans++;
            t -= area;
            r+=2;
            //printf("r = %lld\n",r);
        }
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}
