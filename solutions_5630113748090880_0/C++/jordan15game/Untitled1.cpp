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
bool row[60],col[60];
struct my{
    int a[60];
    bool operator <(const my &u)const{
        for(int i=n-1;i>=0;i--){
            if(a[i]==u.a[i])continue;
            return a[i]<u.a[i];
        }
    }
    void get(){
        for(int i=0;i<n;i++)cin>>a[i];
    }
}b[110];

bool dfs(int d){
    if(d==-1){
        return true;
    }
    for(int i=n-1;i>=0;i--){
        if(!row[i]){
            int flag=1;
            for(int j=n-1;j>=0;j--){
                if(col[j]&&b[d].a[j]!=a[i][j]){
                    flag=0;
                    break;
                }
                a[i][j]=b[d].a[j];
            }
            if(flag){
                row[i]=1;
                if(dfs(d-1))return true;
                row[i]=0;
            }
        }
        if(!col[i]){
            int flag=1;
            for(int j=n-1;j>=0;j--){
                if(row[j]&&b[d].a[j]!=a[j][i]){
                    flag=0;
                    break;
                }
                a[j][i]=b[d].a[j];
            }
            if(flag){
                col[i]=1;
                if(dfs(d-1))return true;
                col[i]=0;
            }
        }
    }
    return false;
}

void check(){
    for(int i=0;i<n;i++){
        if(!row[i]){
            for(int j=0;j<n;j++)printf(" %d",a[i][j]);
            return;
        }
        if(!col[i]){
            for(int j=0;j<n;j++)printf(" %d",a[j][i]);
            return;
        }
    }
}

int main(){
#ifdef jordan13game
    freopen("D:\\in.txt","r",stdin);
    freopen("D:\\out.txt","w",stdout);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<2*n-1;i++)b[i].get();
        clr(row,0);clr(col,0);
        sort(b,b+2*n-1);
        if(!dfs(2*n-2))puts("fuck");
        printf("Case #%d:",ti++);
        check();
        puts("");
    }
    return 0;
}




