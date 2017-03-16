#pragma comment(linker, "/STACK:65536000")
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<queue>
#include<iostream>
#include<time.h>
#include <list>
#include <numeric>
#include <complex>
#define forn(i,n) for(int i=0;i<n;i++)
#define clr(a,b) memset(a,b,sizeof(a))
#define ll long long
#define ull unsigned long long
#define lowb(i) (i&(-i))
#define bug(n,m,x) forn(i,n){forn(j,m)printf("%d ",x[i][j]);puts("");}puts("")
#define sqr(x) ((x)*(x))
using namespace std;
const int inf=1<<30;
const double eps=1e-8;
const double pi=acos(-1.0);
//const ll mod = 9223372034707292160LL;
//const double inf = 1e10;
const double E=2.718281828459;


int n,m;
int ti=1,t;

int sum=0;
char a[100];
int b[20];
void dfs(int d){
    if(sum==m)return;
    if(d==n){
        bool vis[110]={0};
        for(int i=2;i<=10;i++){
            int flag=1;
            for(int j=2;j<=100;j++)if(!vis[j]){
                int ans=0;
                for(int k=0;k<n;k++){
                    ans=(ans*i+a[k]-'0')%j;
                }
                if(ans==0){
                    vis[j]=1;
                    b[i]=j;
                    flag=0;
                    break;
                }
            }
            if(flag)return;
        }
        a[n]=0;
        printf("%s",a);
        for(int i=2;i<=10;i++)printf(" %d",b[i]);
        puts("");
        sum++;
        return;
    }
    if(d==0||d==n-1){
        a[d]='1';
        dfs(d+1);
        return;
    }
    a[d]='0';
    dfs(d+1);
    a[d]='1';
    dfs(d+1);
}

int main(){
#ifdef jordan13game
    freopen("C:\\D\\in.txt","r",stdin);
    freopen("C:\\D\\out.txt","w",stdout);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        printf("Case #%d:\n",ti++);
        dfs(0);
    }
    return 0;
}




