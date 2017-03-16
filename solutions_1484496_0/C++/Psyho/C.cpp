#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>

using namespace std;

#define FOR(i,a,b)  for(int i=(a);i<(b);++i)
#define REP(i,a)    FOR(i,0,a)
#define ZERO(m)     memset(m,0,sizeof(m))
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define S           size()
#define LL          long long
#define LD          long double
#define MP          make_pair
#define X           first
#define Y           second
#define VC          vector
#define PII			pair <int, int>
#define VI          VC<int>
#define VPII		VC < PII >
#define VS          VC<string>
#define DB(a)		cout << #a << ": " << a << endl;

void print(VI v) {cerr << "[";if (v.S) cerr << v[0];FOR(i, 1, v.S) cerr << ", " << v[i];cerr << "]\n";}
void print(VS v) {cerr << "[";if (v.S) cerr << v[0];FOR(i, 1, v.S) cerr << ", " << v[i];cerr << "]\n";}
template<class T> string i2s(T x) {ostringstream o; o << x; return o.str(); }
VS splt(string s, char c = ' ') {VS rv; int p = 0, np; while (np = s.find(c, p), np >= 0) {if (np != p) rv.PB(s.substr(p, np - p)); p = np + 1;} if (p < s.S) rv.PB(s.substr(p)); return rv;}

#define IMP "Impossible"

int cnt[1<<24];

int main() {
	int tc;
	cin >> tc;
	FOR(atc, 1, tc + 1) {
		int N; cin >> N;
		VI v(N);
		REP(i, N) cin >> v[i];
		
		ZERO(cnt);
		printf("Case #%d:\n", atc);
		int st = 0;
lab1:
		FOR(i, 1, 1 << N) {
			int x = 0;
			REP(j, N) if (i & (1 << j)) x += v[j];
			if (cnt[x]) {
				bool f = true;
				REP(j, N) if (i & (1 << j)) {
					if (!f) cout << " ";
					f = false;
					cout << v[j];
				}
				cout << endl;
				ZERO(cnt);
				cnt[x] = 1;
				if (st == 0) {
					st++;
					goto lab1;
				} else {
					goto lab2;
				}
			}
			cnt[x]++;
		}
		cout << IMP << endl;
		
lab2: ;
	}
}