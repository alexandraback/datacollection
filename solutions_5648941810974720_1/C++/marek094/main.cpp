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
std::ifstream __fin("A-large.in.txt");
std::ofstream __fout("out.txt");
#define cin __fin
#define cout __fout
//#endif

int arr[30];
int fc(string s) {
	int mn = INT_MAX;
	FOR(i, SZ(s)) {
		mn = min(mn, arr[ s[i] - 'A' ]);
	}
	FOR(i, SZ(s)) {
		arr[ s[i] - 'A' ] -= mn;
	}
	
	return mn;
}

int test_main() {
	string s; cin >> s;
	
	FOR (i, 30) arr[i] = 0;
	FOR (i, SZ(s)) arr[ s[i] - 'A' ]++;
	
	int num[10];
	num[0] = fc("ZERO");
	num[2] = fc("TWO");
	num[4] = fc("FOUR");
	num[6] = fc("SIX");
	num[8] = fc("EIGHT");
	
	num[3] = fc("TREE");
	num[7] = fc("SEVEN");
	num[5] = fc("FIVE");
	num[9] = fc("NINE");
	num[1] = fc("ONE");
	
	FOR (i, 10) {
		FOR (j, num[i]) {
			cout << i;
		}
	}
	cout << endl;

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












































