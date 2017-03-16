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
char a[200],b[200];
ll c[20];
ll qq,ww;

void dfs(int d,ll q,ll w){
    if(d==n){
//        cout<<abs(qq-ww)<<" "<<abs(q-w)<<endl;
        if(abs(qq-ww)>abs(q-w)){
//            cout<<q<<" "<<w<<endl;
            qq=q;ww=w;
        }
        else if(abs(qq-ww)==abs(q-w)){
            if(q<qq){
                qq=q;ww=w;
            }
            else if(q==qq){
                if(w<ww)qq=q,ww=w;
            }
        }
        return;
    }
    if(a[d]=='?'){
        if(b[d]!='?'){
            for(int i=-1;i<2;i++){
                dfs(d+1,q+((b[d]-'0')+i+10)%10*c[n-d-1],w+(b[d]-'0')*c[n-d-1]);
            }
        }
        else{
            for(int i=-1;i<2;i++){
                dfs(d+1,q,w+(i+10)%10*c[n-d-1]);
            }
            for(int i=-1;i<2;i+=2){
                dfs(d+1,q+(i+10)%10*c[n-d-1],w);
            }
        }
    }else{
        if(b[d]=='?'){
            for(int i=-1;i<2;i++){
                dfs(d+1,q+(a[d]-'0')*c[n-d-1],w+((a[d]-'0')+i+10)%10*c[n-d-1]);
            }
        }
        else{
            dfs(d+1,q+(a[d]-'0')*c[n-d-1],w+(b[d]-'0')*c[n-d-1]);
        }
    }
}

int main(){
#ifdef jordan13game
    freopen("C:\\D\\in.txt","r",stdin);
    freopen("C:\\D\\out.txt","w",stdout);
#endif
    scanf("%d",&t);
    for(ll i=0,r=1;i<20;i++,r*=10)c[i]=r;
    while(t--){
        scanf("%s%s",a,b);
        n=strlen(a);
        qq=1LL<<62,ww=0;
        printf("Case #%d: ",ti++);
        dfs(0,0,0);
        char f[100];
        sprintf(f,"%%0%dlld %%0%dlld%\n",n,n);
        printf(f,qq,ww);
    }
    return 0;
}




