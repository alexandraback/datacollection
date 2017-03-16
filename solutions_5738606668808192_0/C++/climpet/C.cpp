#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
#include <cassert>

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>

#define cauto const auto&
#endif

using namespace std;


namespace{

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T, class U=T>
void initvv(vector<vector<T> > &v, int a, int b, const U &t = U()){
	v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
	stringstream ss;
	ss << f;
	ss >> t;
}


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back


#define MOD 1000000009LL
#define EPS 1e-8

#if defined(SMALL)
constexpr int n = 16;
int ocnt = 50;
#elif defined(LARGE)
constexpr int n = 32;
int ocnt = 500;
#else
#error "Specify SMALL or LARGE"
#endif

void output(LL x){
	cout << bitset<n>(x) << " 3 2 3 2 7 2 3 2 3\n";
	if(--ocnt == 0){
		throw 0;
	}
}

void mainmain(){
	cout << "Case #1:\n";
	vector<int> tbl[2][3][3][7];
	for(int S = 0; S < (1 << (n / 2)); ++S){
		int m2 = 0, m3a = 0, m3b = 0, m7 = 0;
		for(int i = 0; i < n / 2; ++i){
			if(S >> i & 1){
				++m2;
				++m3a;
				m3b += (i % 2 ? 2 : 1);
				m7 += (i % 2 ? 6 : 1);
			}
		}
		tbl[m2 % 2][m3a % 3][m3b % 3][m7 % 7].push_back(S);
	}
	
	for(int h = 0; h < 2; ++h)
	for(int i = 0; i < 3; ++i)
	for(int j = 0; j < 3; ++j)
	for(int k = 0; k < 7; ++k){
		auto &v = tbl[h][i][j][k];
		auto &w = tbl[h][(3 - i) % 3][(3 - j) % 3][(7 - k) % 7];
		
		for(LL x : v){
			if(!(x >> (n / 2 - 1) & 1)){ continue; }
			for(LL y : w){
				if(!(y & 1)){ continue; }
				output(x << (n / 2) | y);
			}
		}
	}
	assert(false);
}

}

int main() try{
	mainmain();
}
catch(...){}
