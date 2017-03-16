#include <algorithm> 
#include <iostream> 
#include <valarray> 
#include <iomanip> 
#include <fstream> 
#include <sstream> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <numeric> 
#include <complex> 
#include <cstdio> 
#include <string> 
#include <vector> 
#include <bitset> 
#include <ctime> 
#include <cmath> 
#include <queue> 
#include <stack> 
#include <deque> 
#include <map> 
#include <set> 

using namespace std; 

#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i) 
#define FOR(i, a, n) for (int i = (a); i < int(n); ++i) 
#define error(x) cout << #x << " = " << (x) << endl; 
#define all(n) (n).begin(), (n).end() 
#define Size(n) ((int)(n).size()) 
#define mk make_pair 
#define pb push_back 
#define F first 
#define S second 
//#define X real() 
//#define Y imag() 

int _;
#define scanf _ = scanf

typedef long long ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef complex<double> point; 

template <class P, class Q> void smin(P &a, Q b) { if (b < a) a = b; } 
template <class P, class Q> void smax(P &a, Q b) { if (b > a) a = b; } 
template <class P, class Q> bool in(const P &a, const Q &b) { return a.find(b) != a.end(); } 

int tc;
bool X, O;

void check(char a, char b, char c, char d) {
	map<char, int> mp;
	mp[a]++; mp[b]++; mp[c]++; mp[d]++;
	if (mp['X']+mp['T'] == 4) X = true;
	if (mp['O']+mp['T'] == 4) O = true;
}

int main() {
	cin >> tc;
	for (int l = 1; l <= tc; l++) {
		cout << "Case #" << l << ": ";
		int cnt = 0;
		string s[4];
		FOR(i, 0, 4) cin >> s[i], cnt += count(all(s[i]), '.');
		X = O = false;
		check(s[0][0], s[1][1], s[2][2], s[3][3]);
		check(s[0][3], s[1][2], s[2][1], s[3][0]);
		FOR(i, 0, 4)
			check(s[i][0], s[i][1], s[i][2], s[i][3]),
			check(s[0][i], s[1][i], s[2][i], s[3][i]);
		if (X)
			cout << "X won";
		else if (O)
			cout << "O won";
		else if (cnt)
			cout << "Game has not completed";
		else
			cout << "Draw";
		cout << endl;
	}
	return 0;
}

