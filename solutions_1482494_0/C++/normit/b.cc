#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back

#define REP(i,n) for(int i=0; i < (n); ++i)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;


struct Level
{
	Level(int _a, int _b) {
		a = _a;
		b = _b;
	}
	int a,b;
	bool operator < (const Level &o) const {
		if(b == o.b) return a < o.a;
		return b < o.b;
	}
};



pair<int, int> checked[30];

int sol;
int n;

void go(int i, int star, vector<Level>&levels)
{
	if(star == n*2) {
		if(sol < 0 || sol > i) sol = i;
		return;
	}
	REP(j, n) {
		Level &l = levels[j];
		// go get 2 star!
		if(!checked[j].second && l.b <= star) {
			pi ori_check = checked[j];
			int ps = (checked[j].first == 0) + (checked[j].second == 0);
			checked[j] = mp(1, 1);
			go(i+1, star + ps, levels);
			checked[j] = ori_check;
		}
		else if(!checked[j].first && l.a <= star) {
			pi ori_check = checked[j];
			checked[j] = mp(1, 0);
			go(i+1, star + 1, levels);
			checked[j] = ori_check;
		}
	}
}

void solve()
{

	vector<Level> levels;

	cin >> n; 
	sol = -1;

	REP(i,n) {
		int a, b;
		cin >> a >> b;
		levels.pb(Level(a,b));
		checked[i] = mp(0, 0);
	}
	sort(levels.begin(), levels.end());

	go(0, 0, levels);

	if(sol == -1) {
		cout << "Too Bad" << endl;
	}
	else {
		cout << sol << endl;
	}
}

int main(int argc, char *argv[])
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}

