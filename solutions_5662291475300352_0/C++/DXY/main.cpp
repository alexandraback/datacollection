#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

int n,m,d,h,D1,D2;
int myInt(){
    int x;
    cin>>x;
    return x;
}
int cal()
{
    n=myInt();
    int t1=0,t2=0;
    for(int i=0;i<n;i++)
    {
        d=myInt();
        h=myInt();
        m=myInt();
        if(h==2) D1=d,D2=d,t1=m,t2=m+1;
        if(i==0&&h==1) D1=d,t1=m;
        if(i==1&&h==1) D2=d,t2=m;
    }
    if(t1<t2) swap(t1,t2),swap(D1,D2);
    double tmp1=(360-D1)/360.0*t1;
    double tmp2=(360-D2)/360.0*t2;
    if(tmp1>tmp2) swap(t1,t2),swap(tmp1,tmp2);
    return tmp1+t1<=tmp2;
}


int main()
{
    freopen("/Users/DXY/Desktop/DXY/DXY/in.txt","r",stdin);
    //freopen("C-small-1-attempt0.in","r",stdin);
    freopen("/Users/DXY/Desktop/B-LL.txt","w",stdout);    int T=myInt();
    int num=0;
    while(T--)
    {
        printf("Case #%d: %d\n",++num,cal());
    }
    return 0;
}
/*
typedef pair<int,int> PP;
vector<PP> X;
int cnt[5];
int ax[4]={0,0,-1,1};
int ay[4]={1,-1,0,0};
int work(PP ppp,int mod,int R,int C,int n){
    int x=ppp.first;
    int y=ppp.second;
    int num=0;
    for(int i=0;i<4;i++){
        int nx=x+ax[i];
        int ny=y+ay[i];
        if(nx>=0 && nx<R && ny>=0 && ny<C){
            if((nx+ny)%2==mod)num++;
        }
    }
    return num;
}
int solve(int R,int C,int n,int mod){
    if(n==0)return 0;
    if(R>C)swap(R,C);
    X.clear();
    for(int i=0;i<R;i++)for(int j=0;j<C;j++)
        if((i+j)%2==1)X.push_back(PP(i,j));
    sort(X.begin(),X.end());
    X.erase(unique(X.begin(), X.end()),X.end());
    int P=0;
    if(mod==0){
        P=(C+1)/2;
        if(R%2==0) P=C*R/2;
        else P=C*(R-1)/2+P;
    }else{
        P=(
    }
        if(n<=P)return 0;
    int ans=0;
    n-=P; memset(cnt,0,sizeof(cnt));
    for(vector<PP>::iterator it=X.begin();it!=X.end();it++){
        cnt[work(*it,mod,R,C,n)]++;
    }
    for(int i=1;i<5;i++){
        if(n>=cnt[i]){
            ans+=cnt[i]*i;
            n-=cnt[i];
        }else{
            ans+=n*i;
            break;
        }
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    //freopen("/Users/DXY/Desktop/DXY/DXY/in.txt","r",stdin);
    freopen("/Users/DXY/Desktop/B-S.txt","r",stdin);
    //freopen("/Users/DXY/Desktop/B-LL.txt","w",stdout);
    int T;scanf("%d",&T);
    for(int i=1;i<=T;i++){
        int R,C,n;
        cin>>R>>C>>n;
        printf("Case #%d: %d\n",i,min(solve(R,C,n,0),solve(R,C,n,1));
    }
    
    return 0;
}*/
