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
pii star[20];
int fdp[1<<11][1<<11];
int tot(int one,int two){
    if(fdp[one][two]!=-1) return fdp[one][two];
    int ret=0;
    rep(i,n){
        if(chk(two,i)) ret+=2;
        else if(chk(one,i)) ret++;
    }
    return fdp[one][two]=ret;
}

i64 dp[1<<11][1<<11];
i64 call(int one,int two){
    if(two== (1<<n)-1) return 0;
    if(dp[one][two]!=-1) return dp[one][two];
    int now=tot(one,two);
    i64 ret=inf;
    rep(i,n){
        if(!chk(two,i) && now>=star[i].yy){
            ret=min(ret,call(one,on(two,i))+1);
        }
        else if(!chk(one,i) && now>=star[i].xx){
            ret=min(ret,call(on(one,i),two)+1);
        }
    }
    return dp[one][two]=ret;
}
int main(){
	read("bin.txt");
	rite("bout.txt");
    double cl = clock();
    int test,kas=0;
    cin>>test;
    while(test--){
        cin>>n;
        mem(fdp,-1);
        rep(i,n){
            int x,y;
            scanf("%d%d",&x,&y);
            star[i]=mp(x,y);
        }
        mem(dp,-1);
        i64 ans=call(0,0);
        if(ans>=inf-10) printf("Case #%d: Too Bad\n",++kas);
        else printf("Case #%d: %lld\n",++kas,call(0,0));
    }
    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds", cl / CLOCKS_PER_SEC);
    return 0;
}
