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
using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
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


char ans[64][64];


void output(int h, int w, bool sw){
	if(sw){
		for(int x = 0; x < w; ++x){
			for(int y = 0; y < h; ++y){
				cout << ans[y][x];
			}
			cout << '\n';
		}
	}
	else{
		for(int y = 0; y < h; ++y){
			for(int x = 0; x < w; ++x){
				cout << ans[y][x];
			}
			cout << '\n';
		}
	}
}


void problem(int h, int w, int m){
	memset(ans, 0, sizeof ans);

	int sp = h * w - m;

	if(sp == 1){
		for(int y = 0; y < h; ++y)
		for(int x = 0; x < w; ++x){
			ans[y][x] = '*';
		}
		ans[0][0] = 'c';
		output(h, w, false);
		return;
	}

	bool sw = false;
	if(h < w){
		swap(h, w);
		sw = true;
	}

	if(sp >= 2 * w){
		int k = m;
		bool ok = true;
		for(int y = h - 1; y >= 0; --y)
		for(int x = w - 1; x >= 0; --x){
			if(k > 0){
				ans[y][x] = '*';
				--k;
			}
			else{
				ans[y][x] = '.';
			}
		}
		
		if(w > 1 && (m + 1) % w == 0){
			int p = sp / w;
			if(p <= 2 || w == 2){
				ok = false;
			}
			else{
				swap(ans[p][1], ans[p - 1][w - 1]);
			}
		}
		
		if(ok){
			ans[0][0] = 'c';
			output(h, w, sw);
			return;
		}
	}
	
	if(sp >= 4 && sp % 2 == 0){
		int k = m;
		for(int y = h - 1; y >= 2; --y)
		for(int x = w - 1; x >= 0; --x){
			ans[y][x] = '*';
			--k;
		}
		for(int x = w - 1; x >= 0; --x){
			if(k > 0){
				ans[0][x] = ans[1][x] = '*';
				k -= 2;
			}
			else{
				ans[0][x] = ans[1][x] = '.';
			}
		}
		ans[0][0] = 'c';
		output(h, w, sw);
		return;
	}
	
	if(w >= 3 && sp >= 9 && sp % 2 == 1){
		int k = m;
		for(int y = h - 1; y >= 2; --y)
		for(int x = w - 1; x >= 0; --x){
			ans[y][x] = '*';
			--k;
		}
		ans[2][0] = ans[2][1] = ans[2][2] = '.';
		k += 3;
		for(int x = w - 1; x >= 0; --x){
			if(k > 0){
				ans[0][x] = ans[1][x] = '*';
				k -= 2;
			}
			else{
				ans[0][x] = ans[1][x] = '.';
			}
		}
		ans[0][0] = 'c';
		output(h, w, sw);
		return;
	}
	
	cout << "Impossible\n";
}


int main(){
	cout << fixed << setprecision(15);

	int T;
	int r, c, m;
	cin >> T;
	for(int i = 1; i <= T; ++i){
		cin >> r >> c >> m;
		cerr<<"Case " << i << " / " << T << endl;
		cout << "Case #" << i << ":\n";
		problem(r, c, m);
	}
}
