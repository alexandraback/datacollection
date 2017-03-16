#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define NMAX 11111

vector<pair<int, int> > v;
int E, R, N;

map<pair<int, int>, pair<int, int> > jobs;
set<pair<int, int> > avail_jobs;
set<pair<int, int> >::iterator it;

long long answer;

void Solve() {
	int i, pstart, pend, pmax, emax_before, emin_after;
	pair<int, int> energy;

	jobs.clear();
	avail_jobs.clear();

	avail_jobs.insert(make_pair(N - 1, 0));
	jobs[make_pair(0, N - 1)] = make_pair(E, 0);
	answer = 0;

	for (i = N - 1; i >= 0; i--) {
		it = avail_jobs.lower_bound(make_pair(v[i].second, -1));
		
		if (it == avail_jobs.end()) {
			fprintf(stderr, "no available job found!\n");
			exit(1);
		}

		pstart = it->second;
		pend = it->first;
		pmax = v[i].second;
		if (pstart <= pmax && pmax <= pend) {
			avail_jobs.erase(*it);
			if (jobs.find(make_pair(pstart, pend)) == jobs.end()) {
				fprintf(stderr, "No info found for available job!\n");
				exit(4);
			}

			energy = jobs[make_pair(pstart, pend)];

			if (pmax - pstart <= E / R) {
				emax_before = energy.first + (pmax - pstart) * R;
				if (emax_before > E)
					emax_before = E;
			} else
				emax_before = E;
			
			if (pend - pmax <= E / R) {
				emin_after = energy.second - (pend - pmax) * R;
				if (emin_after < 0)
					emin_after = 0;
			} else
				emin_after = 0;
			
			if (emax_before < emin_after) {
				fprintf(stderr, "!!! emax_before=%d emin_after=%d\n", emax_before, emin_after);
				exit(3);
			}

			answer += (long long) v[i].first * (long long) (emax_before - emin_after);
			//fprintf(stderr, "pstart=%d pend=%d pmax=%d emax_before=%d emin_after=%d answer=%lld\n", pstart, pend, pmax, emax_before, emin_after, answer);
	
			if (pstart <= pmax - 1) {
				emax_before -= R;
				if (emax_before < 0)
					emax_before = 0;
				jobs[make_pair(pstart, pmax - 1)] = make_pair(energy.first, emax_before);
				avail_jobs.insert(make_pair(pmax - 1, pstart));
			}
			
			if (pmax + 1 <= pend) {
				emin_after += R;
				if (emin_after > E)
					emin_after = E;
				jobs[make_pair(pmax + 1, pend)] = make_pair(emin_after, energy.second);
				avail_jobs.insert(make_pair(pend, pmax + 1));
			}
		} else {
			fprintf(stderr, "incorrect available job found!\n");
			exit(2);
		}		
	}
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("Blarge.out", "w", stdout);

	int T, te, i;
	
	scanf("%d", &T);
	for (te = 1; te <= T; te++) {
		scanf("%d %d %d", &E, &R, &N);

		v.resize(N);
		for (i = 0; i < N; i++) {
			scanf("%d", &(v[i].first));
			v[i].second = i;
		}

		sort(v.begin(), v.end());
		
		Solve();
		
		printf("Case #%d: %lld\n", te, answer);
		fprintf(stderr, "Case #%d: %lld\n", te, answer);
	}
	
	return 0;
}
