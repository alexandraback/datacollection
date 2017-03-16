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
#include <unordered_set>

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

#define $(a,op,b) \
([](typeof(a) &_a, typeof(b) &_b) {\
if (!(_b op _a)) return false; \
_a = _b;\
return true;\
})(a,b)

typedef __uint128_t lll;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double,double> pdd;

//#ifdef DEBUG
std::ifstream __fin("B-large.in.txt");
//std::ifstream __fin("in.txt");
std::ofstream __fout("out.txt");
#define cin __fin
#define cout __fout
//#endif


inline ull pow2(ull i) {
	return 1<<i;
}

int test_main() {
	ull b, m; cin >> b >> m;
	
	if (m > pow2(b-2)) EX("IMPOSSIBLE");
	cout << "POSSIBLE" << endl;
	
	if (m == pow2(b-2)) {
		FOR (i, b-1) {
			RAN (j,0, i) {
				cout << 0;
			}
			RAN (j,i+1, b-1) {
				cout << 1;
			}
			cout << endl;
		}
	} else {
		FOR (i, b-1) {
			RAN (j,0, i) {
				cout << 0;
			}
			RAN (j,i+1, b-2) {
				cout << 1;
			}
			if (i == 0) cout << 0;
			else {
				cout << ((m&pow2(i-1) )!= 0);
			}
			cout << endl;
		}
	}
	
	
	FOR (i,b) cout << 0; cout<< endl;
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












































