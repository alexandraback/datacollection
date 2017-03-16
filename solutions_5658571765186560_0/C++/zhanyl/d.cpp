#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <tr1/unordered_set>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

const int maxn=20;
const int MAXN=6;

set<string> S;
int Ans[7][1005][1005];
bool p[21][21];
bool q[21][21];

void xz(){
    int i,j;
    for(i=0;i<21;i++)
    for(j=0;j<21;j++)
        q[i][j]=p[i][j];
    for(i=0;i<21;i++)
    for(j=0;j<21;j++)
        p[i][j]=q[20-j][i];
}

int vis[1005][1005];
int r,c,n;
int ed;

bool ok(int i,int j,int idx){
    if(i<0||j<0||i>=r||j>=c)return false;
    if(vis[i][j])return false;
    if(i&&vis[i-1][j]==idx)return true;
    if(i+1<r&&vis[i+1][j]==idx)return true;
    if(j&&vis[i][j-1]==idx)return true;
    if(j+1<c&&vis[i][j+1]==idx)return true;
    return false;
}

bool test(int idx,int i,int j,int x){
    if(idx>ed)return true;
    if(x==n)return test(idx+1,i,j,x);
    if(j==c)return test(idx,i+1,0,x);
    if(i==r)return false;
    if(x==0){
        if(vis[i][j])return test(idx,i,j+1,x);
        vis[i][j]=idx;
        if(test(idx,i,j,x+1))return true;
        vis[i][j]=0;
        return false;
    }
    int ii,jj;
    for(ii=-x;ii<=x;ii++)
    for(jj=-x;jj<=x;jj++){
        if(ok(i+ii,j+jj,idx)){
            vis[i+ii][j+jj]=idx;
            if(test(idx,i,j,x+1))return true;
            vis[i+ii][j+jj]=0;
        }
    }
    return false;
}

bool check(int N,int R,int C){
    n=N,r=R,c=C;
    ed=r*c/n;
    int i,j,ii,jj;
    for(i=0;i<r;i++)
    for(j=0;j<c;j++)
        vis[i][j]=0;
    int xa=22,ya=22,xb=-1,yb=-1;
    for(i=5;i<=15;i++)
    for(j=5;j<=15;j++)
        if(p[i][j]){
            if(i<xa)xa=i;
            if(i>xb)xb=i;
            if(j<ya)ya=j;
            if(j>yb)yb=j;
        }
    for(i=0;i+xb-xa<r;i++)
    for(j=0;j+yb-ya<c;j++){
        for(ii=xa;ii<=xb;ii++)
        for(jj=ya;jj<=yb;jj++)
            if(p[ii][jj]){
                vis[i+ii-xa][j+jj-ya]=1;
            }
        if(test(2,0,0,0))return true;
        for(ii=xa;ii<=xb;ii++)
        for(jj=ya;jj<=yb;jj++)
            if(p[ii][jj]){
                vis[i+ii-xa][j+jj-ya]=0;
            }
    }
    return false;
}

bool panduan(){
    int i,j;
    for(i=5;i<=15;i++)
    for(j=5;j<=15;j++)
        if(p[i][j]){
            if(i==10 && j==10)return true;
            return false;
        }
    return false;
}

void solve(int n){
    int r,c;
    if(!panduan())return;
    for(r=1;r<=maxn;r++)
    for(c=1;c<=maxn;c++)
        if(Ans[n][r][c]){
            static bool flag;
            flag=false;
            if(!flag)flag=check(n,r,c);
            xz();
            if(!flag)flag=check(n,r,c);
            xz();
            if(!flag)flag=check(n,r,c);
            xz();
            if(!flag)flag=check(n,r,c);
            xz();
            if(!flag)Ans[n][r][c]=0;
        }
}

void dfs(int n){
    solve(n);
    if(n==MAXN)return;
    for(int i=5;i<=15;i++)
    for(int j=5;j<=15;j++)
        if((!p[i][j])&&(p[i-1][j]||p[i+1][j]||p[i][j-1]||p[i][j+1])){
            p[i][j]=true;
            dfs(n+1);
            p[i][j]=false;
        }
}

int main(){
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);
    freopen("D-small-attempt0.in","r",stdin);
    freopen("D-small-attempt0.out","w",stdout);
    //freopen("D-large.in","r",stdin);
    //freopen("D-large.out","w",stdout);
    S.clear();
    for(int n=1;n<=MAXN;n++)
    for(int r=1;r<=maxn;r++)
    for(int c=1;c<=maxn;c++)
        if((r*c)%n!=0)Ans[n][r][c]=0;
        else Ans[n][r][c]=1;
    memset(p,0,sizeof(p));
    p[10][10]=true;
    dfs(1);
    int T;
    scanf("%d",&T);
    for(int Cas=1;Cas<=T;Cas++){
        int n,r,c;
        scanf("%d%d%d",&n,&r,&c);
        if(n>=7||(!Ans[n][r][c]))printf("Case #%d: RICHARD\n",Cas);
        else printf("Case #%d: GABRIEL\n",Cas);
    }
    return 0;
}
