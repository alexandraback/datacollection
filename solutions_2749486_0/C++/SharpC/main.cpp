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
#include <ctime>
#include <limits>
#include <memory.h>
#include <iterator>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
#define sz(m) ((m).size())
#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i=0,i##e=n;i<i##e;++i)
#define fori(i,m) forn(i,sz(m))
#define each(i,m) for(typeof(m.begin())i=m.begin(),i##e=m.end();i!=i##e;++i)
#define srt(s) sort(all(s))
#define maxup(a,b) a=max(a,b)
#define minup(a,b) a=min(a,b)
#define pb push_back
#define mp make_pair
#define x first
#define y second


vector<vector<vector<string>>> res(23, vector<vector<string>>(520, vector<string>(520)));
int shift;

void init()
{
	int sx = 100;
	shift = 260;
	int len = 520;
	int rem = (2*sx + 1)*(2*sx + 1)-1;
	vector<pair<pair<int, int>, char>> wave, nwave;
	wave.pb(mp(mp(0, 0), '\0'));
	for (int i = 1; i <= 22; ++i) {
		cerr << "step " << i << ", rem = " << rem << ", wavesize = " << wave.size() << endl;
		//cout << "i = " << i << ", wave size = " << wave.size() << endl;
		fori(j,wave) {
			int x = wave[j].x.x, y = wave[j].x.y;
			char c = wave[j].y;
			int pi = i - 1;
			int ix = wave[j].x.x + shift, iy = wave[j].x.y + shift;
			string path = c == 'E' ? res[pi][ix-pi][iy] + "E" : c == 'W' ? res[pi][ix+pi][iy] + "W" : c == 'N' ? res[pi][ix][iy-pi] + "N" : c == 'S' ? res[pi][ix][iy+pi] + "S" : "";
			nwave.pb(mp(mp(wave[j].x.x + i, wave[j].x.y), 'E'));
			nwave.pb(mp(mp(wave[j].x.x - i, wave[j].x.y), 'W'));
			nwave.pb(mp(mp(wave[j].x.x, wave[j].x.y + i), 'N'));
			nwave.pb(mp(mp(wave[j].x.x, wave[j].x.y - i), 'S'));
			//cout << "can be at " << wave[j].x.x << "," << wave[j].x.y << " after " << wave[j].y << endl;
			//if (ix >= 0 && ix < len && iy >= 0 && iy < len) {
				res[i][ix][iy] = path;
				bool was = false;
				for (int k = 0; k < i; ++k) if (!res[k][ix][iy].empty()) was = true;
				if (abs(wave[j].x.x) <= sx && abs(wave[j].x.y) <= sx && !was) {
					--rem;
					if (rem == 0) {
						cerr << "Finished at step " << i << endl;
						//return;
					}
				}
			//}
		}
		srt(nwave); nwave.erase(unique(all(nwave)), nwave.end());
		wave.swap(nwave);
		nwave.clear();
	}
}


string solve(int x, int y)
{
	for (int i = 0; i < 23; ++i) if (!res[i][x+shift][y+shift].empty()) {
		return res[i][x+shift][y+shift];
	}
	return "(error)";
}

bool check(const string& s, int x, int y)
{
	int cx = 0, cy = 0;
	fori(i,s) s[i] == 'N' ? cy += i+1 : s[i] == 'S' ? cy -= i+1 : s[i] == 'E' ? cx += i+1 : s[i] == 'W' ? cx -= i+1 : 0;
	return cx == x && cy == y;
}

int main()
{
	int tests;
	cin >> tests;
	init();
	for (int test = 1; test <= tests; ++test) {
		int x, y;
		cin >> x >> y;
		string sol = solve(x, y);
		cout << "Case #" << test << ": " << sol << endl;
		cerr << (check(sol, x, y) ? "OK" : "FAILED") << endl;
	}
}
