#include<iostream>
#include<cstdio>
using namespace std;

bool sepuede(long long int r, long long int t, long long int p){
    long long int q=(p*(2*r+2*p-1));
    return (q<=t);
}

int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int T,q=1;
    long long int r,t,x,m,y;
    scanf("%d",&T);
    while(T--){
        scanf("%lld %lld",&r,&t);
        x=0;
        y=100000LL;
        while(x<y){
            m=x+(1+y-x)/2;
            if(sepuede(r,t,m)){
                x=m;
            }
            else{
                y=m-1;
            }
        }
        printf("Case #%d: %lld\n",q++,x);
    }
}
