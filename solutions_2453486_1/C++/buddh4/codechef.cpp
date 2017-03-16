#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <ctime>
#include <cstring>
#include <cassert>
#include <cstdarg>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;

template<typename T> int size(T& a){ return (int) a.size(); }
template<typename T> T sqr(T a){ return a * a; }

#pragma comment(linker, "/STACK:256000000")

#define _(a, b) memset((a), (b), sizeof(a))
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define REPD(i, a, b) for(int i = (b) - 1; i >= a; --i)

const string x = "X won";
const string o = "O won";
const string draw = "Draw";
const string other = "Game has not completed";

char a[5][5];

int findWin(string s) {
	int x = 0, o = 0, t = 0;
	REP(i, 0, size(s)) {
		if(s[i] == 'X') x++;
		if(s[i] == 'O') o++;
		if(s[i] == 'T') t++;
	}
	if(x + t == 4) return -1;
	if(o + t == 4) return 1;
	return 0;
}

string solve(int test) {
	REP(i, 0, 5) gets(a[i]);

	int dots = 0;
	REP(i, 0, 4) REP(j, 0, 4) 
		dots += a[i][j] == '.';

	REP(i, 0, 4) {
		string s = "";
		REP(j, 0, 4) s += a[i][j];
		int win = findWin(s);
		if(win == -1) return x;
		if(win == 1) return o;
	}

	REP(j, 0, 4) {
		string s = "";
		REP(i, 0, 4) s += a[i][j];
		int win = findWin(s);
		if(win == -1) return x;
		if(win == 1) return o;
	}

	string s = "";
	REP(i, 0, 4) s += a[i][i];
	int win = findWin(s);
	if(win == -1) return x;
	if(win == 1) return o;

	s = "";
	REP(i, 0, 4) s += a[i][3 - i];
	win = findWin(s);
	if(win == -1) return x;
	if(win == 1) return o;

	if(dots > 0) return other;

	return draw;
}

int main() {                     
#ifdef shindo
	
	if(false) {
	}

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif

	int T;
	scanf("%d\n", &T);
	REP(t, 0, T) 
		cout << "Case #" << t + 1 << ": " << solve(t + 1) << endl; 
/*	
#ifdef shindo
	printf("\n-------------\n\n\nWalltime = %.3lf\n", clock() * 1e-3);
#endif
*/
}