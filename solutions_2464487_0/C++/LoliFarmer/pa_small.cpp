#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
long long int odd_from_one(long long int p){
   long long int n = (p + 1) / 2;
   return n * 4 * ( n  * 2 + 1 ) * ( n + 1 ) / 6 - n * 4 * ( n + 1 ) / 4 + n;
}
int main(){
    int T, f=0;
    scanf("%d",&T);
    long long int R,total;
    long long int ans;
    while(T--){
        scanf("%lld%lld",&R,&total);
        ans = 0;
        while(1){
            if( total < (R+1)*(R+1) - R*R ) break;
            ans++;
            total -= (R+1)*(R+1) - R*R;
            R+=2;
        }
        printf("Case #%d: %lld\n",++f,ans);
    }


    return 0;
}
