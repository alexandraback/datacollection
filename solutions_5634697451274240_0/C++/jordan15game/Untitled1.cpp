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
char a[110];

int getp(int len){
    for(int i=len-1;i>=0;i--){
        if(a[i]=='-')return i;
    }
    return -1;
}

char b[110];

void rev(int l){
    for(int i=0;i<=l;i++)b[i]=a[i];
    for(int i=0;i<=l;i++)a[i]=(b[l-i]=='+'?'-':'+');
}

int main(){
#ifdef jordan13game
    freopen("C:\\D\\in.txt","r",stdin);
    freopen("C:\\D\\out.txt","w",stdout);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%s",a);
        printf("Case #%d: ",ti++);
        int l=strlen(a);
        int ans=0;
        while(1){
            int p=getp(l);
            if(p==-1)break;
            if(a[0]=='+'){
                for(int i=0;i<l;i++){
                    if(a[i]=='+')a[i]='-';
                    else break;
                }
                ans++;
                continue;
            }
            rev(p);
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}




