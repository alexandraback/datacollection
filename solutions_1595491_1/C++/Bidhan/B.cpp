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

#define mx 105
int n,s,p,t[mx];
i64 dp[mx][mx];
i64 call(int pos,int l){
    if(l<0) return -inf;
    if(pos==n) {
        if(l==0) return 0;
        return -inf;
    }
    if(dp[pos][l]!=-1) return dp[pos][l];
    i64 ret=0;
    for(int i=0; i<=t[pos]; i++){
        for(int j=0; j<=t[pos]; j++){
            if(i+j>t[pos]) break;
            int k=t[pos]-(i+j);
            if(abs(i-j)>2 || abs(i-k)>2 || abs(j-k)>2) continue;
            if(i>10 || j>10 || k>10) continue;
            int maxi=max(i,max(j,k));
            int ll=l-(abs(i-j)==2 || abs(i-k)==2 || abs(j-k)==2);
            ret=max(ret,call(pos+1,ll)+(maxi>=p));
        }
    }
    return dp[pos][l]=ret;
}

int main(){
	read("bin");
	rite("bout");
	int test,kas=0;
	cin>>test;
	while(test--){
	    cin>>n>>s>>p;
	    rep(i,n) scanf("%d",&t[i]);
	    mem(dp,-1);
	    printf("Case #%d: ",++kas);
	    cout<<call(0,s)<<endl;
	}
    double cl = clock();
    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds", cl / CLOCKS_PER_SEC);
    return 0;
}
