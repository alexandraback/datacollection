
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream> 

using namespace std;

inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

template<class T> inline T sqr(T x) { return x*x; }

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long ll;

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define P(p) cout<<(p)<<endl;
#define VEC_2D(a,b) vector<vector<int> >(a, vector<int>(b, 0))
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define INF (1100000000)
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define MOD 1000000007LL


int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x%y);
}
int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}
bool is_prime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return n != 1;
}
map<int, int> prime_factor(int n) {
	map<int, int> res;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			++res[i];
			n /= i;
		}
	}
	if (n != 1) res[n] = 1;
	return res;
}
int extgcd(int a, int b, int& x, int& y) {//
	int d = a;
	if (b != 0) {
		d = extgcd(b, a%b, y, x);
		y -= (a / b)*x;
	}
	else {
		x = 1; y = 0;
	}
	return d;
}
ll mod_pow(ll x, ll n, ll mod) {
	if (n == 0) return 1;
	ll res = mod_pow(x * x % mod, n / 2, mod);
	if (n & 1) res = res * x % mod;
	return res;
}
vector<string> split(const string &str, char delim) {
	vector<string> res;
	size_t current = 0, found;
	while ((found = str.find_first_of(delim, current)) != string::npos) {
		res.push_back(string(str, current, found - current));
		current = found + 1;
	}
	res.push_back(string(str, current, str.size() - current));
	return res;
}

bool is_kadomatsu(int a, int b, int c) {
	if (a == b || a == c || b == c)return false;
	if (a > b && c > b) return true;
	if (a < b && c < b)return true;
	return false;
}

int dx8[8] = { 2, 2, 1, 1, -1, -1, -2, -2 };
int dy8[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };

int dx4[4] = { 1, 1, -1, -1 };
int dy4[4] = { 1, -1, -1, 1 };

int H, W;

bool inside(int x, int y) {
	return x >= 0 && x < H && y >= 0 && y < W;
}

int main() {


	return 0;
}




