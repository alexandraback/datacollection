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
map<string,int> mp1,mp2;
struct my{
    string a,b;
    void get(){
        cin>>a>>b;
        mp1[a]++;mp2[b]++;
    }
    bool operator < (const my &u)const{
        return min(mp1[a],mp2[b])<min(mp1[u.a],mp2[u.b]);
    }
}a[1010];

int main(){
#ifdef jordan13game
    freopen("C:\\D\\in.txt","r",stdin);
    freopen("C:\\D\\out.txt","w",stdout);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("Case #%d: ",ti++);
        mp1.clear();mp2.clear();
        for(int i=0;i<n;i++)a[i].get();
        sort(a,a+n);
        int ans=0;
        for(int i=0;i<n;i++){
            int flag=0,flag1=0;
            for(int j=0;j<i;j++)if(a[i].a==a[j].a){
                flag=1;break;
            }
            for(int j=0;j<i;j++)if(a[i].b==a[j].b){
                flag1=1;break;
            }
            if(flag&&flag1){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}




