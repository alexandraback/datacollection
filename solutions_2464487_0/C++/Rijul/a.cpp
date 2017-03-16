#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define inf (1<<29)
#define maxm 110010

#define ii __int64

ii gcd(ii a,ii b){
    if(!a) return b;
    if(!b) return a;
    return gcd(b,a%b);
}
ii mini(ii a,ii b){
    if(a<b) return a; return b;
}
ii maxi(ii a,ii b){
    if(a>b) return a; return b;
}


int main(){

    int i,j,k,l,test,t=1;

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&test);

    while(test--){

        int rem,r;
        scanf("%d %d",&r,&rem);

        ii now=r;
        ii now1=r+1;
        ii remm=rem;
        int ans=0;

        while(1){
            ii curr=(now1*now1)-(now*now);
            if(curr>remm) break;
            ans++;
            remm-=curr;
            now+=2; now1+=2;
            if(!remm) break;
        }

        printf("Case #%d: %d\n",t++,ans);

    }

    return 0;
}
