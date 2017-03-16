#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <map>
#include <string.h>
#include <assert.h>
#include <set>
#include <cmath>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=b-1;i>=a;i--)
#define inf 1000000007
#define mod 1000000007
#define x first
#define y second
#define pi acos(-1.0)
#define DBG(x) cerr<<(#x)<<"="<<x<<"\n";
//#define dprintf(...) 
#define hash _hash
//#define dprintf(...) fprintf(outFile,__VA_ARGS__)
 
#define FOREACH(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define ull unsigned long long
#define ll long long
#define N 1010
 
template <class T,class U>inline void Max(T &a,U b){if(a<b)a=b;}
template <class T,class U>inline void Min(T &a,U b){if(a>b)a=b;}
 
//FILE* outFile;
 
inline void add(int &a,int b){a+=b;while(a>=mod)a-=mod;}
 
int pow(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=ans*(ll)a%mod;
        a=(ll)a*a%mod;b>>=1;
    }
    return ans;
}

char s[20][2][22];
int f[20][2],dp[1<<16];
int main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int m,j,k,i,T,ca=0,n;
    scanf("%d",&T);
    while(T--){
        printf("Case #%d: ",++ca);
        scanf("%d",&n);
        rep(i,0,n)rep(j,0,2)scanf("%s",s[i][j]);
        memset(f,0,sizeof(f));
        rep(i,0,n){
            rep(j,0,n)if(i!=j){
                if(strcmp(s[i][0],s[j][0])==0)f[i][0]|=1<<j;
                if(strcmp(s[i][1],s[j][1])==0)f[i][1]|=1<<j;
            }
        }
        memset(dp,0,sizeof(dp));
        rep(i,0,1<<n){
            rep(j,0,n)if(!(i>>j&1)){
                if((f[j][0]&i)&&(f[j][1]&i)&&((f[j][0]^f[j][1])&i)){
                    Max(dp[i|1<<j],dp[i]+1);
                }
                max(dp[i|1<<j],dp[i]);
            }
        }
        printf("%d\n",dp[(1<<n)-1]);
    }
    //cerr<<1.*clock()/CLOCKS_PER_SEC<<"s\n";
    return 0;
}