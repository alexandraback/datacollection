#define print(x) cerr << #x << " = " << toStr(x) << endl;
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int)((x).size()))
#define rep(i, N) for (int i = 0; i < N; ++i)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
typedef long long lint;
typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pii;
template<class T> string toStr(T x){stringstream ss;ss<< x; return ss.str(); } 
template<class T1,class T2>string toStr(pair<T1,T2>x){return toStr(x.first)+": "+toStr(x.second);}
template<class T> string containerToStr(T v) { string r = "["; foreach (it, v) { if (r != "[") r += ", "; r += toStr(*it); } return r + "]";}
template<class T> string toStr(vector<T>v){return containerToStr(v);} 
template<class T> string toStr(set<T> v) {return containerToStr(v);} 
template<class T1,class T2>string toStr(map<T1,T2>v){return containerToStr(v);}

int n;


/*int len(int x) {
	int res = 0;
	while (x) {
		res++;
		x %= 10;
	}
	return res;
}*/

bool check(int x, int y) {
	int z = x;
//	cout << z << " ";
	while (true) {
		z = z / 10 + z % 10 * n;
		if (z == x) break;
		if (z == y) return true;
	}
	return false;
}

void solve(int num) {
	int lo, hi;
	long long ans = 0;
	cin >> lo >> hi;
	n = 1;
	while (n * 10 <= lo) n *= 10;
	
	for (int i = lo; i < hi; ++i) {
		for (int j = i + 1; j <= hi; ++j) {
			if (check(i, j)) {
				++ans;
			}
		}
	}
	printf("Case #%d: %d\n", num, ans);
}

int main() {
	int tst;
	cin >> tst;
	for (int i = 1; i <= tst; ++i) solve(i);
    return 0;
}
