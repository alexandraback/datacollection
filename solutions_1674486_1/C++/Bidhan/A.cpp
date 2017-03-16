/*
 * Bidhan Roy
 * University of Dhaka
 */

using namespace std;

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define inf (1<<30)
#define eps 1e-9
#define pb push_back
#define ins insert
#define mp make_pair
#define sz(x) ((int)x.size())
#define clr clear()
#define all(x) x.begin(),x.end()
#define xx first
#define yy second
#define sqr(x) ((x)*(x))
#define mem(x,val) memset((x),(val),sizeof(x));
#define read(x) freopen(x,"r",stdin);
#define rite(x) freopen(x,"w",stdout);
#define chk(a,k) ((bool)(a&(1<<(k))))
#define off(a,k) (a&(~(1<<(k))))
#define on(a,k) (a|(1<<(k)))

typedef long long i64;
typedef unsigned long long ui64;
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef map<int,int> mii;
typedef map<st,int> msi;
typedef map<int,st> mis;
typedef set<int> si;
typedef set<st> ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define mx 1010
int n;
vi edge[mx];
int D;
int dp[mx];
int call(int u){
    if(u==D) return 1;
    if(dp[u]!=-1) return dp[u];
    int tot=0;
    rep(i,sz(edge[u])){
        int v=edge[u][i];
        //if(v==par) continue;
        tot+=call(v);
        tot=min(tot,2);
    }
    return dp[u]=tot;
}

int main(){
	double cl = clock();
    cl = clock() - cl;
    read("ain.txt");
    rite("aout.txt");
    int test,kas=0;
    cin>>test;
    while(test--){
        printf("Case #%d: ",++kas);
        cin>>n;
        rep(i,n) edge[i].clr;
        rep(i,n){
            int tt;
            cin>>tt;
            while(tt--){
                int temp;
                scanf("%d",&temp);
                edge[i].pb(temp-1);
            }
        }
        int ans=0;
        rep(i,n) rep(j,n) if(i!=j) { if(ans) break; mem(dp,-1); D=j; ans|=(call(i)>=2); }
        cout<<(ans?"Yes":"No")<<endl;
    }
    fprintf(stderr, "Total Execution Time = %lf seconds", cl / CLOCKS_PER_SEC);
    return 0;
}
