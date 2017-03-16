#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define FOR(i,s,e) for (int i = int(s); i < int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sz(v) (int)v.size()
#define all(c) (c).begin(), (c).end()

typedef long long int ll;

// %I64d for ll in CF

double solution;
double c, f, x;

void solve(double gain, double total_time) {
	if (total_time - solution > 1e-9) return;

	//printf("%.2f %.7f\n", gain, total_time);

	// wait to get X
	double final_time = total_time + (x / gain);
	if (solution - final_time > 1e-9) {
		solution = final_time;
	}

	// wait for next purchase
	solve(gain + f, total_time + (c / gain));
}

int main() {
	int t;
	scanf("%d", &t);
	for (int c0 = 1; c0 <= t; c0++) {
		solution = 1e18;
		scanf("%lf %lf %lf", &c, &f, &x);
		solve(2, 0);
		printf("Case #%d: %.7f\n", c0, solution);
	}
	return 0;
}
