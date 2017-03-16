#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;++i)
#define FOR(i, a, b) for(int i = a;i < b;++i)
#define F first
#define S second
typedef vector<int> vi;
typedef long long int ll;
typedef pair<double, double> ii;

vector<ii> v;

void input() {
	int n;
	cin >> n;
	int kolko;
	double pos, brz;
	v.clear();
	if(n == 1) {
		cin >> pos >> kolko >> brz;
		if(kolko == 1) v.push_back({pos, brz});
		else {
			v.push_back({pos, brz});
			v.push_back({pos, brz + 1.0});
		}
	}
	else {
		cin >> pos >> kolko >> brz;
		v.push_back({pos, brz});
		cin >> pos >> kolko >> brz;
		v.push_back({pos, brz});
	}
}

int solve() {
	if(v.size() == 1) return 0;
	if(v[1].S == v[0].S) return 0;
	if(v[0].S > v[1].S) swap(v[0], v[1]);
	double t;
	t = (720.0 - v[0].F)*v[0].S/360.0;
	if(t * 360.0/v[1].S + v[1].F >= 360.0) return 0;
	return 1;
}

int main() {
	int t;
	cin >> t;
	int n;
	int sol = 0;
	REP(i, t) {
		input();
		cout << "Case #" << i + 1 << ": " << solve() << "\n";
	}
}