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

void solve()
{
	int n;
	int score[300];
	int sum = 0;
	int zc = 0;
	cin >> n;
	REP(i,n) {
		cin >> score[i];
		sum += score[i];
	}

	for(int i = 0; i < n; ++i) {
		double l = 0.0;
		double r = 1.0;
		while(r-l >= 1e-9) {
			double p = (l+r) / 2.;
			double acc = score[i] + sum * p;

			double sum_prob = 0.;
			for(int j = 0; j < n; ++j) {
				if(i == j) continue;
				if(acc < score[j]) continue;
				sum_prob += (acc - score[j]) / (double)sum;
			}
			if(sum_prob > 1-p) r = p;
			else l = p;
		}

		printf("%.6f ", l * 100);
	}

/*
		double sum_minus = sum - score[i];
		double p = (sum_minus + sum - (n-1) * score[i]) / ( n * sum );
		if(p < 0) p = 0;
		if(score[i] == 0 && zc >= 2) {
			p = 1./zc;
		}

		printf("%.6f ", p * 100);
	}
*/
	printf("\n");
}

int main(int argc, char *argv[])
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i) {
		printf("Case #%d: ", i);
	 //cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}

