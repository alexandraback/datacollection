#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

long long cal(long long L,long long R,int B){
    long long ans=R-L,pre=0;
    for(int i=0;i<B-1;i++){
        pre=pre*10+9;
        long long tmp=0;
        for(int j=B-1-i-1;j>=0;j--) tmp=tmp*10+9;
        long long pp=pre+tmp-1+1;
        if(pp<ans) ans=pp;
    }
    return ans;
    
}
long long n;
long long cal(){
    if(n<=10) return n;
    long long tmp=n;
    int cnt=0,X[30];
    while(tmp) X[++cnt]=tmp%10,tmp/=10;
    long long ans=10;
    int B=2;
    long long cur=10;
    while(B<cnt){
        ans+=cal(cur,cur*10-1,B);
        ans++;
        cur*=10;
        B++;
    }
    if(n==cur) return ans;
    if(X[1]==0)
    {
        X[1]=9,X[2]--;
        for(int i=2;i<=cnt;i++)
        {
            if(X[i]>=0) break;
            X[i]+=10;
            X[i+1]--;
        }
        ans++;
        n--;
    }
    long long A=n-cur;
    for(int i=cnt;i>=1;i--)
    {
        long long tmp=0;
        for(int j=i;j<=cnt;j++) tmp=tmp*10+X[j];
        tmp++;
        long long P=0;
        for(int j=i-1;j>=1;j--) P=P*10+X[j];
        if(P==0) continue;
        P--;
        tmp+=P;
        if(tmp<A) A=tmp;
    }
    return ans+A;
}

int main()
{
    freopen("/Users/DXY/Desktop/DXY/DXY/in.txt","r",stdin);
    //freopen("/Users/DXY/Desktop/B-S.txt","r",stdin);
    freopen("/Users/DXY/Desktop/B-LL.txt","w",stdout);
    int T; cin>>T;
    for(int cs=1;cs<=T;cs++){
        cin>>n;
        printf("Case #%d: %lld\n",cs,cal());
    }
    return 0;
}

/*
int R,C,n;
int solve(){
    cin>>R>>C>>n;
    if(n==0)return 0;
    if(R>C)swap(R,C);
    if(R==1){
        int mx=(C+1)/2;
        if(n<=mx)return 0;
        n-=mx;
        if(C%2==0)return n*2-1;
        else return n*2;
    }
    int ans=0,cur=0,les=n;
    
    if(C%2==0)cur=R;
    else
        
    for(int i=0;i<C;i++){
        if(
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    freopen("/Users/DXY/Desktop/DXY/DXY/in.txt","r",stdin);
    //freopen("/Users/DXY/Desktop/B-S.txt","r",stdin);
    //freopen("/Users/DXY/Desktop/B-LL.txt","w",stdout);
    int T;scanf("%d",&T);
    for(int i=1;i<=T;i++){
        printf("Case #%d: %d\n",i,solve());
        //cout<<solve()<<endl;
    }
    
    return 0;
}*/
