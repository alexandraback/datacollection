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

int n;

int war(vector<double> &naomi, vector<double> &ken) {
	int points = 0;

	bool naomi_used[n];
	bool ken_used[n];
	memset(naomi_used, false, sizeof naomi_used);
	memset(ken_used, false, sizeof ken_used);

	for (int i = 0; i < n; i++) {
		bool done = false;
		for (int j = 0; j < n && !done; j++) {
			if (!ken_used[j] && ken[j] - naomi[i] > 1e-9) {
				ken_used[j] = true;
				done = true;
			}
		}

		if (!done) {
			// ken can't defeat this weight, so he will play the least weighted he currently has
			for (int j = n - 1; j >= 0; j--) {
				if (!ken_used[j]) {
					ken_used[j] = true;
					break;
				}
			}

			points++;
		}
	}

	return points;
}

bool can_play_normal(vector<double> &naomi, vector<double> &ken, bool *naomi_used, bool *ken_used) {
	bool done = true;
	int i = 0, j = 0;
	while (i < n && j < n && done) {
		if (naomi_used[i]) {
			i++;
		}
		else if (ken_used[j]) {
			j++;
		}
		else {
			done &= naomi[i] - ken[j] > 1e-9;
			i++;
			j++;
		}
	}

	return done;
}

int deceitful_war(vector<double> &naomi, vector<double> &ken) {
	int points = 0;

	bool naomi_used[n];
	memset(naomi_used, false, sizeof naomi_used);
	bool ken_used[n];
	memset(ken_used, false, sizeof ken_used);
	int nexti = n - 1;
	int nextj = 0;
	while (!can_play_normal(naomi, ken, naomi_used, ken_used)) {
		naomi_used[nexti] = true;
		ken_used[nextj] = true;
		nexti--;
		nextj++;
	}

	return nexti + 1;
}

int main() {
	int t;
	scanf("%d", &t);
	int c = 1;
	while (t--) {
		scanf("%d", &n);
		vector<double> naomi(n), ken(n);
		for (int i = 0; i < n; i++) {
			scanf("%lf", &naomi[i]);
		}

		for (int i = 0; i < n; i++) {
			scanf("%lf", &ken[i]);
		}

		sort(all(naomi));
		sort(all(ken));
		reverse(all(naomi));
		reverse(all(ken));

		printf("Case #%d: %d %d\n", c, deceitful_war(naomi, ken), war(naomi, ken));
		c++;
	}
	return 0;
}
