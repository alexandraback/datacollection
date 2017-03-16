#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

#define BM 10000005

long long a,b;
int t;
int d[BM];

int pali(long long x){
    long long c=x,l=0;
    for(;c;c/=10)l=l*10+c%10;
    if(l==x)return 1;
    return 0;
}

int main (){
    int l,ra,rb;
    long long i;
    double aa,bb;
    //freopen("l.in","r",stdin);
    //freopen("l.out","w",stdout);
    scanf("%d",&t);
    for(i=1;i<=BM-5;++i){
        d[i]=d[i-1];
        if(pali(i)&&pali(i*i)){
            //printf("%lld ",i);
            ++d[i];
        }
    }
    for(l=1;l<=t;++l){
        cin>>a>>b;
        aa=sqrt((double)a),bb=sqrt((double)b);
        ra=aa,rb=bb;
        if(ra<aa)++ra;
        if(rb<=BM-5)printf("Case #%d: %d\n",l,d[rb]-d[ra-1]);
        else printf("Case #%d: %d\n",l,d[BM-5]-d[ra-1]);
    }
    return 0;
}
