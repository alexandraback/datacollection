#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <limits>
#include <functional>
#include <numeric>
#define _ << " _ " <<
#define dbg(x) //cerr << #x << " == " << x << endl
#define mp(x,y) make_pair((x),(y))
#define pv(x,y) {for(typeof(y) z=(x);z!=(y);z++)cerr<<*z<<" ";cerr<<endl;}
#define rep(x,y) for(int(x)=(0);(x)<int(y);++(x))
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int,int> pt;

#if 0
#define GENERATE 1
#endif

int f[1111], n;

void read() {
	cin>>n;
	rep(i,n) {
		cin>>f[i];
		f[i]--;
	}
}

vector<int> r[1111];
int v[1111], mk;

int go(int x, int p) {
	//dbg(x);
	//dbg(p);
	int ans = 1;
	for (int i = 0; i < r[x].size();i++) {
		int adj = r[x][i];
		if(adj==p) continue;
		dbg(x _ adj);
		ans = max(ans, 1 + go(adj, x));
	}
	dbg(x _ p _ (ans+1));
	return ans;
}

void process() {

	rep(i,1111) r[i].clear();

	rep(i,n) {
		r[f[i]].push_back(i);
	}

	// cycle
	int ans = 0;
	rep(i,n) {
		mk++;
		int at=i, sz=0;
		do {
			sz++;
			v[at]=mk;
			at=f[at];
		} while(v[at]!=mk);

		if(at==i) {
			//cout<<"!!!"<<sz<<endl;
			dbg("cycle" _ sz);
			ans=max(ans,sz);
		}
	}

	int dup = 0;
	// two
	rep(i,n) {
		if(f[f[i]] == i) {
			//dup++;

			dbg(i);
			dbg(f[i]);
			int A = go(i, f[i]);
			int B = go(f[i], i);
			dbg(A);
			dbg(B);
			int sz = A + B;
			dbg("two" _ i _ f[i] _ sz);
			ans = max(ans, sz);

			//cout<<i+1<<endl;
			//cout<<f[i]+1<<endl;
			//cout<<A+B<<endl<<endl;

			dup += A + B;
		}
	}

	ans = max(ans, dup/2);

	printf(" %d\n",ans);
}

int main() {
	int T;
#ifdef GENERATE
	unsigned int seed=time(0);
	dbg(seed);
	srand(seed);
	T=50;
	for(int testcase=1;testcase<=T;++testcase) {
		fprintf(stderr,"Case #%d:",testcase);
		// *generate input!
		// BEGIN
		// END
#else
		cin>>T;
		for(int testcase=1;testcase<=T;++testcase) {
			fprintf(stdout,"Case #%d:",testcase);
			read();
#endif
		//if(testcase!=4)continue;

		try {
			process();
		} catch(char const*exception) {
			puts(exception);
		}
	}
	return 0;
}
