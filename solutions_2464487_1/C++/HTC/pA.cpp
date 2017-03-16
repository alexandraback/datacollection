#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<math.h>
using namespace std;
long long MIN(long long a,long long b){
    if(a < b)return a;
    return b;
}
int main (){
    //freopen("A-small-attempt0.in","r",stdin);
    //freopen("Asamll.txt","w",stdout);
    freopen("A-large.in","r",stdin);
    freopen("Alarge.txt","w",stdout);
    int ca,T,ans;
    long long r,t,area;
    long long mid,left,right,a,b;
    scanf("%d",&T);
    for(ca = 1;ca <= T;ca++){
        scanf("%lld%lld",&r,&t);
        ans = 0;
        left = 0;
        right = MIN(t/r,6600000000);
        while(right - left > 1){
            mid = (left+right)/2;
            if(t > mid*(r+1+(r+2*(mid-1))))left = mid;
            else right = mid;
        }
        for(long long i = left-1; i < left + 2;i++){
            a = i*(r+1+(r+2*(i-1)));
            b = (i+1)*(r+1+(r+2*((i+1)-1)));
            if(a <= t && b > t){
                ans = i;
                break;
            }
        }
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}
