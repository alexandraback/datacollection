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
char a[10][10]={"ZERO","TWO","SIX","EIGHT","THREE","FOUR","SEVEN","FIVE","ONE","NINE"};
char b[]="0268347519";
char ans[2010];
int c[256];
char q[2010];

bool dfs(int d,int sum){
    if(sum==0){
        ans[d]=0;
        sort(ans,ans+d);
        return true;
    }
    for(int i=0;i<10;i++){
        int l=strlen(a[i]);
        int flag=1;
        for(int j=0;j<l;j++)if(c[a[i][j]]==0){
            flag=0;break;
        }
        if(flag){
            for(int j=0;j<l;j++)c[a[i][j]]--;
            ans[d]=b[i];
            if(dfs(d+1,sum-l))return true;
            for(int j=0;j<l;j++)c[a[i][j]]++;
        }
    }
    return false;
}

int main(){
#ifdef jordan13game
    freopen("C:\\D\\in.txt","r",stdin);
    freopen("C:\\D\\out.txt","w",stdout);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%s",q);
        printf("Case #%d: ",ti++);
        int l=strlen(q);
        clr(c,0);
        for(int i=0;i<l;i++)c[q[i]]++;
        dfs(0,l);
        puts(ans);
    }
    return 0;
}




