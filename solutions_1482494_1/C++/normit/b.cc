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
		eaten = false;
	}
	int a,b;
	bool eaten;

	bool operator < (const Level &o) const {
		if(b == o.b) return a < o.a;
		return b < o.b;
	}
};

struct ELevel
{
	ELevel(int l_, int a_) {
		l = l_;
		a = a_;
	}
	int l,a;

	bool operator < (const ELevel &o) const {
		return a < o.a;
	}
};



pair<int, int> checked[30];
vector<int> order, last_order;
vector<int> order2, last_order2;

int sol;
int n;

void go(int i, int star, vector<Level>&levels)
{
	if(star == n*2) {
		if(sol < 0 || sol > i) {sol = i;
			last_order = order;
			last_order2 = order2;
		}
		return;
	}
	REP(j, n) {
		Level &l = levels[j];
		// go get 2 star!
		if(!checked[j].second && l.b <= star) {
			pi ori_check = checked[j];
			int ps = (checked[j].first == 0) + (checked[j].second == 0);
			checked[j] = mp(1, 1);
			order.push_back(j);
			order2.push_back(1);
			go(i+1, star + ps, levels);
			order.pop_back();
			order2.pop_back();
			checked[j] = ori_check;

		}
		else if(!checked[j].first && l.a <= star) {
			pi ori_check = checked[j];
			checked[j] = mp(1, 0);
			order.push_back(j);
			order2.push_back(0);
			go(i+1, star + 1, levels);
			order.pop_back();
			order2.pop_back();
			checked[j] = ori_check;
			order[i] = j;
		}
	}
}

int go2(vector<Level>& levels)
{
	int sol = n;

	for(int i = n-1; i >= 0; --i) {
		int cur_star = i * 2;
		int delta = levels[i].b - cur_star;
		if(delta <= 0) continue;

		vector<ELevel> v;

		for(int j = i; j < n; ++j) v.pb(ELevel(j, levels[j].a));
		sort(v.begin(), v.end());

		set<int> eaten_set;

		for(int j = 0; j < v.size() && delta > 0; ++j) {
			if(v[j].a <= cur_star && levels[v[j].l].eaten) {
				eaten_set.insert(j);
				levels[v[j].l].eaten = true;
				++cur_star;
				--delta;
			}
		}
		for(int j = 0; j < v.size() && delta > 0; ++j) {
			if(v[j].a <= cur_star && eaten_set.count(j) == 0) {
				levels[v[j].l].eaten = true;
				++cur_star;
				--delta;
			}
		}


		if(delta > 0) {
			//cout << "Failed to eat : " << levels[i].a << " " << levels[i].b << endl ;
			return -1;
		}

	}
	sol = n;
	REP(i, n) {
		if(levels[i].eaten) ++ sol;
	}
	return sol;
}

void solve()
{

	vector<Level> levels;

	cin >> n; 
	
	REP(i,n) {
		int a, b;
		cin >> a >> b;
		levels.pb(Level(a,b));
	}
	sort(levels.begin(), levels.end());

	sol = go2(levels);


//	go(0, 0, levels);

	if(sol == -1) {
		cout << "Too Bad" << endl;
	}
	else {
		/*
		REP(i, last_order.size()) {
			int jjj = last_order[i];
			cout << "(" << levels[jjj].a << "," << levels[jjj].b << ")";
			if(last_order2[i]) cout << "* ";
			else cout << " ";
		}
		cout << endl;
*/
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

