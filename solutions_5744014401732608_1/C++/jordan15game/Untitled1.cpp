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
int a[60][60];

int main(){
#ifdef jordan13game
    freopen("C:\\D\\in.txt","r",stdin);
    freopen("C:\\D\\out.txt","w",stdout);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        clr(a,0);
        printf("Case #%d:",ti++);
        for(int i=0;i<n-1;i++)for(int j=i+1;j<n-1;j++)a[i][j]=1;
        a[0][n-1]=1;
        m--;
        for(int i=n-3;i>=0;i--)if(m&(1<<i))a[i+1][n-1]=1,m-=1<<i;
        if(m==0){
            puts(" POSSIBLE");
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)printf("%d",a[i][j]);
                puts("");
            }
        }else
        {
            puts(" IMPOSSIBLE");
        }
    }
    return 0;
}




