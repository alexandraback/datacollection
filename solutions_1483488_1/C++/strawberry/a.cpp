#include<iostream>
#include<cstdio>
using namespace std;

int nextInt(int n,int mod){
    int high=n/mod;
    n=n%mod*10+high;
    return n;
}

int count(int n,int b){
    int mod=1;
    while(mod*10<=n)
        mod*=10;
    int cnt=0;
    int m=n;
    do{
        m=nextInt(m,mod);
        if(n<m&&m<=b)
            cnt++;
    }while(m!=n);
    return cnt;
}

int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int cas;
    scanf("%d",&cas);
    int a,b,ans;
    for(int c=1;c<=cas;c++){
        scanf("%d%d",&a,&b);
        ans=0;
        for(int i=a;i<=b;i++)
            ans+=count(i,b);
        printf("Case #%d: %d\n",c,ans);
    }
    return 0;
}

