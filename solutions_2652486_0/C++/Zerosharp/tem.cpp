#include <set>
#include <map>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

#include <ctime>
#include <deque>
#include <bitset>
#include <cctype>
#include <utility>
#include <cassert>

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)
#define Fit(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define Fitd(i,v) for(__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); ++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))

template<class F, class T> T convert(F a, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; T r; ss >> r; return r; }
template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return s == 0 ? 0 : cntbit(s >> 1) + (s & 1); }
const int bfsz = 1 << 16; char bf[bfsz + 5]; int rsz = 0;int ptr = 0;
char gc() { if (rsz <= 0) { ptr = 0; rsz = (int) fread(bf, 1, bfsz, stdin); if (rsz <= 0) return EOF; } --rsz; return bf[ptr++]; }
void ga(char &c) { c = EOF; while (!isalpha(c)) c = gc(); }
int gs(char s[]) { int l = 0; char c = gc(); while (isspace(c)) c = gc(); while (c != EOF && !isspace(c)) { s[l++] = c; c = gc(); } s[l] = '\0'; return l; }
template<class T> bool gi(T &v) {
    v = 0; char c = gc(); while (c != EOF && c != '-' && !isdigit(c)) c = gc(); if (c == EOF) return false; bool neg = c == '-'; if (neg) c = gc();
    while (isdigit(c)) { v = v * 10 + c - '0'; c = gc(); } if (neg) v = -v; return true;
}

#define maxn 10005
#define mod 7340033
#define eps 1e-6

int test, r, n, m, k;
int a[20], res[20];
bool check;
set<int>::iterator it;

void go(int id, set<int> S){
	if(check) return;
	if(id == n + 1){
		check = true;
//		For(i, 1, n) cout << res[i] << " "; puts("");
//		for(it = S.begin(); it != S.end(); it++) cout << (*it) << " "; puts("");
		For(i, 1, k) if(!S.count(a[i])){
			check = false;
			break;
		}
		return;
	}

	For(i, 2, m){
		set<int> SS;
		res[id] = i;
		for(it = S.begin(); it != S.end(); it++){
			SS.insert(*it);
			SS.insert((*it) * i);
		}
		go(id + 1, SS);
		if(check) return;
	}
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
//    freopen("symmetry.out", "w", stdout);

	cin >> test;

	For(itest, 1, test){
		cout << "Case #" << itest << ":" << endl;
		cin >> r >> n >> m >> k;
		Rep(run, r){
			set<int> S; S.insert(1); check = false;
			For(i, 1, k) cin >> a[i];
			go(1, S);
			For(i, 1, n) cout << res[i]; puts("");
		}
	}

    return 0;
}
