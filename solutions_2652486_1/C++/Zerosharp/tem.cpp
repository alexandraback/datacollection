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

int test, r, n, N, m, k;
int num[10], nprime[15][10], m5, m7;
int prime[4] = {2, 3, 5, 7};
bool check;
bool f[15][15][15][40];

bool thoaman1(int x1, int x2, int x3, int d){
	return f[x1][x2][x3][d];
}

bool thoaman(int x1, int x2, int d){
	while(d >= 2 && x2 > 0){
		d -= 2;
		x2 -= 1;
	}
	return d <= x1;
}

void go(int id, int d){
	if(id == 8){
		num[8] = d;
		check = true;
		For(i, 1, k) if(!thoaman1(num[2] + num[6], num[4], num[8], nprime[i][0]) || !thoaman(num[3], num[6], nprime[i][1])){
			check = false;
		}
		return;
	}

	if(id == 5 || id == 7){
		go(id + 1, d);
		return;
	}
	if(check) return;
	int ran = rand() % 2;
	if(ran){
		For(i, 0, d){
			num[id] = i;
			go(id + 1, d - i);
			if(check) return;
		}
	}
	else{
		Ford(i, d, 0){
			num[id] = i;
			go(id + 1, d - i);
			if(check) return;
		}
	}
}

void init(){
	ms(f, 0);
	For(i, 0, 12) For(j, 0, 12 - i) For(k, 0, 12 - i - j){
		bool can[40]; ms(can, 0);
		For(t, 0, i) can[t] = 1;
		Ford(t, 39, 0) if(can[t]){
			For(run, 1, j) can[t + run * 2] = 1;
		}
		Ford(t, 39, 0) if(can[t]){
			For(run, 1, k) can[t + run * 3] = 1;
		}
		For(t, 0, 39) if(can[t]) f[i][j][k][t] = 1;
	}
}

void gen(){
	r = 100; n = 12; m = 8; k = 12;
	int x[105][15];

	For(run, 1, r){
		For(i, 1, n) {
			x[run][i] = rand() % (m - 1) + 2;
			printf("%d ", x[run][i]);
		}
		puts("");
	}

	freopen("in.txt", "w", stdout);
//	cout << 1 << endl;
//	cout << 100 << " " << 12 << " " << 8 << " " << 12 << endl;
	For(run, 1, r){
		For(t, 1, k){
			ll res = 1;
			For(i, 1, n){
				int choose = rand() % 2;
				if(choose) res *= x[run][i];
			}
			cout << res << " ";
		}
		puts("");
	}

}

void solve(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
//    freopen("symmetry.out", "w", stdout);

	cin >> test;
	init();
	For(itest, 1, test){
		cout << "Case #" << itest << ":" << endl;
		cin >> r >> n >> m >> k;
		Rep(run, r){
			check = false;
			ms(nprime, 0);
			m5 = 0; m7 = 0;
			For(i, 1, k) {
				ll a;
				cin >> a;
				Rep(j, 4){
					while(a % prime[j] == 0){
						nprime[i][j]++;
						a /= prime[j];
					}
				}
				m5 = max(m5, nprime[i][2]);
				m7 = max(m7, nprime[i][3]);
			}
//			cout << m5 << " " << m7 << endl;
			N = n;
			N -= m5; N -= m7;
			num[5] = m5; num[7] = m7;
			go(2, N);

			For(i, 2, m){
				Rep(rr, num[i]) printf("%d", i);
			}
			puts("");
		}
	}


}

int main() {
//    gen();
	solve();
}
