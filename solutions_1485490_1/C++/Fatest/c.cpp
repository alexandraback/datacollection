#include<cmath>
#include<cstdio>
#include<cctype>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

#define sqr(a) (a)*(a)
#define cub(a) (a)*(a)*(a)
#define for1(i,a,b) for(i=(a);i<(b);i++)
#define for2(i,a,b) for(i=(a);i>(b);i--)
#define same(a) memset((a),0,sizeof(a));
#define ll long long

int cmpint(const void*a,const void *b)
{
    if(((int*)a)[0]==((int*)b)[0])
      return ((int*)a)[1]-((int*)b)[1];
    return ((int*)a)[0]-((int*)b)[0];
}

ll a[105][2];
ll b[105][2];
ll tans[105][105];


ll min(ll a,ll b){
    if(a>b) return b;
    return a;
}
ll max(ll a,ll b){
    if(a<b) return b;
    return a;
}

ll dfs(int n,int m,ll ta,ll tb){
    ll ans;
    if(a[n][0]==ta){
        n--;
        ta=0;
    }
    if(b[m][0]==tb){
        m--;
        tb=0;
    }
    if(n<0||m<0) return 0;
    if(a[n][1]==b[m][1]){
        ans=min(a[n][0]-ta,b[m][0]-tb);
        //printf("test3\n");
        return ans+dfs(n,m,ta+ans,tb+ans);
    }
    if(n>0&&m>0){
        if(tans[n-1][m-1]==-1)
          tans[n-1][m-1]=dfs(n-1,m-1,0,0);
        ans=tans[n-1][m-1];
    }
    else ans=0;

    int tn=n,tm=m;
    while(tm>=0){
        if(a[n][1]!=b[tm][1])
           tm-=1;
        else break;
    }
    //printf("test\n");
    if(tm>=0){
        if(ta==0){
            if(tans[n][tm]==-1)
               tans[n][tm]=dfs(n,tm,0,0);
            ans=max(ans,tans[n][tm]);
        }
        else ans=max(ans,dfs(n,tm,ta,0));
    }
    while(tn>=0){
        if(a[tn][1]!=b[m][1]) tn-=1;
        else break;
    }
    if(tn>=0){
        if(tb==0){
            if(tans[tn][m]==-1)
               tans[tn][m]=dfs(tn,m,0,0);
            ans=max(ans,tans[tn][m]);
        }
        else ans=max(ans,dfs(tn,m,0,tb));
    }
    return ans;
}

int main()
{
    int i,j,n,m,k,l,o,p;
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    scanf("%d",&p);
    for1(o,0,p){
        scanf("%d%d",&n,&m);
        for1(i,0,n){
            cin>>a[i][0]>>a[i][1];
            if(i>0&&a[i][1]==a[i-1][1]){
                a[i-1][0]+=a[i][0];
                i--;
                n--;
            }
        }
        for1(i,0,m){
            cin>>b[i][0]>>b[i][1];
            if(i>0&&b[i][1]==b[i-1][1]){
                b[i-1][0]+=b[i][0];
                i--;
                m--;
            }
        }
        for1(i,0,n+1)
         for1(j,0,m+1)
          tans[i][j]=-1;
        ll ans=dfs(n-1,m-1,0,0);
        printf("Case #%d: %lld\n",o+1,ans);
    }
    return 0;
}
