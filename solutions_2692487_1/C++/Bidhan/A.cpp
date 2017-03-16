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

template <class T> inline T __in() { T v; cin>>v; return v; }

#define Q __in<int>()
#define QQ __in<i64>()
#define QS __in<st>()

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

#define mx 300

int a[mx];

i64 call(i64 a,i64 b,int &cnt){
    cnt=0;
    //cout<<a<<","<<b<<endl;
    while(a<=b){
        a+=(a-1);
        cnt++;
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(0);
	read("in.txt");
	rite("out.txt");
	double cl = clock();
    int test=Q,kas=0;
    while(test--){
        int A=Q;
        int N=Q;
        rep(i,N) a[i]=Q;
        sort(a,a+N);
        i64 ans=inf;
        i64 s=A;
        int add=0;
        int f=0;
        rep(i,N){
            ans=min(ans,(i64)add+N-i);
            if(s==1) { f=1; break; }
            if(s>a[i]) s+=a[i];
            else{
                int cnt=0;
                s=call(s,a[i],cnt);
                add+=cnt;
                s+=a[i];
            }
        }
        if(!f)
        ans=min(ans,1LL*add);
        cout<<"Case #"<<++kas<<": ";
        cout<<ans<<endl;
    }
    cl = clock() - cl;
    cerr<<endl<<endl<<endl;
    cerr<<"-----------------------------------"<<endl;
	cerr<<"Total Execution Time = "<<cl / CLOCKS_PER_SEC<<" s"<<endl;
	cerr<<"-----------------------------------"<<endl;
	return 0;
}
