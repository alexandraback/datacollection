#include <bits/stdc++.h>
using namespace std;

#ifdef mahou_shoujo_madoka
    #define LLF "%I64d"
#else
    #define LLF "%lld"
#endif
/*
const int SIZE = 1000005;

int dp[SIZE];
int go[SIZE];

int rev(int x){
    int ret=0;
    while(x){
        ret=ret*10+x%10;
        x/=10;
    }
    return ret;
}

int init(){
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    dp[1]=1;
    queue<int> q;
    q.push(1);
    while(q.size()){
        int x=q.front();
        int y=x+1;
        q.pop();
        if(y<SIZE && dp[y]<0){
            dp[y]=dp[x]+1;
            go[y]=x;
            q.push(y);
        }
        y=rev(x);
        if(y<SIZE && dp[y]<0){
            dp[y]=dp[x]+1;
            go[y]=x;
            q.push(y);
        }
    }
    for(int i=SIZE-100;i<SIZE;i++){
        //if(i!=go[i]+1)
            printf("dp[%d] = %d from %d\n",i,dp[i],go[i]);
    }
}
/*/

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
