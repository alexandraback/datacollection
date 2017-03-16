#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
//#include <emmintrin.h>

using namespace std;

#define FOR(i,a,b)  for(int i=(a);i<(b);++i)
#define REP(i,a)    FOR(i,0,a)
#define ZERO(m)    memset(m,0,sizeof(m))
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define S          size()
#define LL          long long
#define ULL        unsigned long long
#define LD          long double
#define MP          make_pair
#define X          first
#define Y          second
#define VC          vector
#define PII        pair <int, int>
#define VI          VC < int >
#define VVI        VC < VI >
#define VD          VC < double >
#define VVD        VC < VD >
#define VS          VC < string >
#define DB(a)      cerr << #a << ": " << (a) << endl;

template<class T> void print(VC < T > v) {cerr << "[";if (v.S) cerr << v[0];FOR(i, 1, v.S) cerr << ", " << v[i];cerr << "]n";}
template<class T> string i2s(T x) {ostringstream o; o << x; return o.str(); }
VS splt(string s, char c = ' ') {VS all; int p = 0, np; while (np = s.find(c, p), np >= 0) {if (np != p) all.PB(s.substr(p, np - p)); p = np + 1;} if (p < s.S) all.PB(s.substr(p)); return all;}

string board[4];
int xwin = 0;
int owin = 0;

int get(int x, char c) {
	return board[x/4][x%4] == 'T' || board[x/4][x%4] == c;
}

void check(int a, int b, int c, int d) {
	xwin |= get(a, 'X') && get(b, 'X') && get(c, 'X') && get(d, 'X');
	owin |= get(a, 'O') && get(b, 'O') && get(c, 'O') && get(d, 'O');
}

int main() {
	int tc;
	cin >> tc;
	FOR(atc, 1, tc + 1) {
		xwin = owin = 0;
		REP(i, 4) cin >> board[i];
		REP(i, 4) check(i * 4, i * 4 + 1, i * 4 + 2, i * 4 + 3);
		REP(i, 4) check(i + 0, i + 4, i + 8, i + 12);
		check(0, 5, 10, 15);
		check(3, 6, 9, 12);
		int no = 0;
		REP(i, 4) REP(j, 4) no += board[i][j] == '.';
		string output = xwin ? "X won" : owin ? "O won" : no != 0 ? "Game has not completed" : "Draw";
		printf("Case #%d: %s\n", atc, output.c_str());
	}
}