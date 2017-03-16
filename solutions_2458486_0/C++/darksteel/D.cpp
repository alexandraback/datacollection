#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <vector>
#include <stack>
#include <list>
#include <utility>
#include <queue>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VP;
typedef vector<string> VS;

#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define FORE(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define ALL(x) x.begin(),x.end()
#define CLR(x, v) memset((x),v,sizeof (x))
#define gcd(a, b) __gcd(a, b)
#define PB push_back 
#define MP make_pair
#define INF 2000000007

int toInt(string s){ istringstream sin(s); int t; sin>>t; return t; }
template<class T> string toString(T x){ ostringstream sout; sout<<x; return sout.str(); }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }

VI tr[25];
VI ans;
multiset<int> key[1<<25];
int vis[1<<25];
int tp[25];
int n;

bool dfs(int mask)
{
	int i;
	if(mask==0) return true;
	vis[mask] = 1;
	FOR(i,0,n) if(mask&(1<<i)) {
		int nmask = mask ^ (1<<i);
		if(vis[nmask]) continue;
		ans.PB(i+1);
		if(key[mask].find(tp[i])!=key[mask].end()) {
			key[nmask] = key[mask];
			key[nmask].erase(key[nmask].find(tp[i]));
			FORE(it,tr[i]) key[nmask].insert(*it);
			if(dfs(nmask)) return true;
		}
		ans.pop_back();
	}
	return false;
}

void solve()
{
    int i, j;
	int k;
	cin>>k>>n;
	int m = (1<<n)-1;
	ans.clear();
	FOR(i,0,(1<<n)) key[i].clear();
	FOR(i,0,k) {
		int t;
		cin>>t;
		key[m].insert(t);
	}
	FOR(i,0,n) tr[i].clear();
	FOR(i,0,n) {
		int t, kn;
		cin>>tp[i]>>kn;
		FOR(j,0,kn) {
			cin>>t;
			tr[i].PB(t);
		}
	}
	CLR(vis,0);
	if(dfs(m)) {
		cout<<ans[0];
		FOR(i,1,n) cout<<" "<<ans[i];
		cout<<endl;
	} else {
		cout<<"IMPOSSIBLE"<<endl;
	}
}

int main()
{
    int T;
    cin>>T;
    for(int cs = 1; cs <= T; cs++) {
        cout << "Case #" << cs << ": ";
		solve();
    }
	return 0;
}
