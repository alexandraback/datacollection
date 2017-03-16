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

#define mx 0
int n;
pii star[1010];

i64 dfs(int now,bitset<1002> &a,bitset<1002> &b){
    //cout<<now<<" "<<a<<" "<<b<<endl;
    int cnt=0;
    rep(i,n) {
        if(!b[i] && now>=star[i].yy) {
        b[i]=1;
        return dfs(now+2-a[i],a,b)+1;
    }
    cnt+=b[i];
    }
    if(cnt==n) return 0;
    int val=0, idx=-1;
    rep(i,n) if(!a[i] && !b[i] && now>=star[i].xx) {
        if(val<star[i].yy) val=star[i].yy, idx=i;
        //a[i]=1;
        //return dfs(now+1,a,b)+1;
    }
    if(idx>-1){
        a[idx]=1;
        return dfs(now+1,a,b)+1;
    }
    return inf;
}

int main(){
	read("bin.txt");
	rite("bout_FINAL.txt");
    double cl = clock();
    int test,kas=0;
    cin>>test;
    while(test--){
        cin>>n;
        //mem(fdp,-1);
        rep(i,n){
            int x,y;
            scanf("%d%d",&x,&y);
            star[i]=mp(x,y);
        }
        bitset<1002> aa,bb;
        i64 ans=dfs(0,aa,bb);
        if(ans>=inf)printf("Case #%d: Too Bad\n",++kas);
        else printf("Case #%d: %lld\n",++kas,ans);
    }
    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds", cl / CLOCKS_PER_SEC);
    return 0;
}
