//
//  main.cpp
//  codex
//
//  Created by MarekCerny.com.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;
#define X first
#define Y second
#define EX(x) do{cout<<(x)<<endl;return 0;}while(0)
#define SW(a,b) do{auto ___t=a;a=b;b=___t;}while(0)
//#define endl "\n"
#define SZ(v) (int(v.size()))
#define ALL(v) v.begin(),v.end()
#define IN(arr,x) (unsigned)(&x-&arr[0])
#define AT(arr,x) (unsigned)(x-&arr[0])

#define FOR(i,n) for(int i=0;i<int(n);++i)
#define ROF(i,n) for(int i=int(n)-1;i>=0;--i)
#define RAN(i,b,e) for(int i=b;i<=int(e);++i)
#define NAR(i,b,e) for (int i=e;i>=int(b);--i)

#define ASSERT(i,c) do{if(!(c))exit(i);}while(0)
//#include <cassert>
//#define ASSERT(i,c) assert(c)

typedef __uint128_t lll;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double,double> pdd;

//#ifdef DEBUG
std::ifstream __fin("B-small-attempt2.in.txt");
std::ofstream __fout("out.txt");
#define cin __fin
#define cout __fout
//#endif


int gmin = INT_MAX;
int ggmin;
pair<string,string> ps;

void solve(string c, string j, int i) {
	if (i >= SZ(c) ) {
		int v = abs(stoi(c.c_str()) - stoi(j.c_str()));
		int vv = min(stoi(c.c_str()), stoi(j.c_str()));
		if (v < gmin) {
			ggmin = vv;
			gmin = v;
			ps = {c,j};
		} else if (v==gmin && vv<ggmin) {
			ggmin = vv;
			ps = {c,j};
		}
		return;
	}

	if (c[i] == '?') {
		FOR(k,10) {
			c[i] = '0'+k;
			solve(c,j,i);
		}
	} else if (j[i] == '?') {
		FOR(k,10) {
			j[i] = '0'+k;
			solve(c,j,i);
		}
	} else {
		solve(c,j,i+1);
	}
}

int test_main() {
	string c,j; cin >> c >> j;
	
	gmin = INT_MAX;
	solve(c,j,0);
	cout << ps.X << " " << ps.Y << endl;

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t; RAN (i,1,t) {
		cout << "Case #" << i << ": ";
		test_main();
	}
	return 0;
}












































