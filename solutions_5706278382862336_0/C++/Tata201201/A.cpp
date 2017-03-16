#include<stdio.h>
#include<math.h>
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

long long int gcd(long long int a, long long int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int t;
    cin >> t;
    for(int zz=1;zz<=t;zz++){
        bool ans = true;
        long long int p,q;
        scanf("%lld/%lld",&p,&q);
        long long int g = gcd(p,q);
        p = p/g;
        q = q/g;

        //printf("%lld\n",gcd(p,q));
        long long int temp = q;
        while(temp>1){
            if(temp%2) break;
            temp = temp/2;
        }
        //printf("XXX");

        long long int count=0;
        if(temp!=1) ans = false;
        else{
            while(q>p){
                q = q/2;
                count++;
            }
        }

        if(ans) printf("Case #%d: %lld\n",zz,count);
        else printf("Case #%d: impossible\n",zz);
    }

    return 0;
}
