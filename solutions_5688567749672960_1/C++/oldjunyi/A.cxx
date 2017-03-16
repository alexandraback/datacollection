#include <bits/stdc++.h>
using namespace std;

#ifdef mahou_shoujo_madoka
    #define LLF "%I64d"
#else
    #define LLF "%lld"
#endif

int numlen(long long x){
    return x<10?1:numlen(x/10)+1;
}

long long pow10(int x){
    long long ret=1;
    for(int i=0;i<x;i++) ret*=10;
    return ret;
}

long long rev(long long x){
    long long ret=0;
    while(x){
        ret=ret*10+x%10;
        x/=10;
    }
    return ret;
}

long long gao(long long n){
    if(n==1) return 1;
    int x=numlen(n)/2;
    long long r=n%pow10(x);
    if(r==0) return gao(n-1)+1;
    if(r!=1) return gao(n-(r-1))+r-1;
    if(rev(n)<n) return gao(rev(n))+1;
    return gao(n-1)+1;
}

int main(){
    //init();
    int cs;
    scanf("%d",&cs);
    for(int no=1;no<=cs;no++){
        long long n;
        scanf(LLF,&n);
        long long ans=gao(n);
        printf("Case #%d: " LLF "\n",no,ans);
    }
}
