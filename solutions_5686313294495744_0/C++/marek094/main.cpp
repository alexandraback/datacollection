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

typedef __uint128_t lll;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double,double> pdd;

//#ifdef DEBUG
std::ifstream __fin("C-small-attempt0.in.txt");
std::ofstream __fout("out.txt");
#define cin __fin
#define cout __fout
//#endif


int gmin = INT_MAX;
int ggmin;
pair<string,string> ps;



int test_main() {
	int n; cin >> n;
	
	unordered_set<string> l,r;
	int b = 0;
	FOR (i, n) {
		string ls, rs; cin >> ls >> rs;
		
		l.insert(ls);
		if (l.find(rs)!=l.end()) b++;
		
		r.insert(rs);
		if (r.find(ls)!=r.end()) b++;
	}
	
	cout << (SZ(l)*SZ(r)-n-b) << endl;

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












































