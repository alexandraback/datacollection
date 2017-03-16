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
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

const int SIZE = 512;

const int SAMPLES = (1<<26) - 100;

int n;
int COUNT;
int64 arr[SIZE];

bool used[SIZE];
int cnt;
int64 sum;

typedef pair<int64, int> Sample;
int s;
Sample *samples/*[SAMPLES]*/;

inline bool operator< (const Sample &a, const Sample &b) { return a.first < b.first; }
inline bool operator== (const Sample &a, const Sample &b) { return a.first == b.first; }

int *history/*[SAMPLES]*/;
int currSample;
int GenNext() {
	bool poss[2] = {true, true};
	if (cnt < COUNT) poss[true] = false;
	if (cnt > COUNT) poss[false] = false;

	int ind;
	do {
		ind = rand() & (SIZE - 1);
	} while (ind >= n || !poss[used[ind]] || ind == history[currSample-1]);

	used[ind] ^= 1;
	sum += (used[ind] ? arr[ind] : -arr[ind]);
	cnt += (used[ind] ? 1 : -1);

	history[currSample] = ind;
	return currSample++;
}

vector<int64> GetSampleInfo(Sample sample) {
	bool tmp[SIZE] = {false};
	for (int i = 0; i<=sample.second; i++)
		tmp[history[i]] ^= 1;

	vector<int64> res;
	int64 tsum = 0;
	for (int i = 0; i<n; i++) if (tmp[i]) {
		res.push_back(arr[i]);
		tsum += arr[i];
	}

/*	printf("%d ", sample.second);
	for (int i = 0; i<n; i++) printf("%d", int(tmp[i]));
	printf(" : %I64d  (%I64d %d)\n", tsum, sample.first, sample.second);
	fflush(stdout);*/

	assert(tsum == sample.first);
	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	srand(time(0));

	samples = new Sample[SAMPLES];
	history = new int[SAMPLES];

	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		scanf("%d", &n);
		for (int i = 0; i<n; i++) scanf("%I64d", &arr[i]);

		memset(used, 0, sizeof(used));
		cnt = 0;
		sum = 0;
		currSample = 0;
		COUNT = n / 2;

		for (s = 0; s<SAMPLES; s++) {
			GenNext();
			samples[s] = make_pair(sum, s);

/*			printf("%d ", s);
			for (int i = 0; i<n; i++) printf("%d", int(used[i]));;
			printf(" : %I64d\n", sum);*/
		}
		E(Generated\n);

		sort(samples, samples+s);
		E(Sorted\n);

		set<vector<int64> > ans;
		int j;
		for (int i = 0; i<s; i = j) {
			for (j = i; samples[i].first == samples[j].first && j<s; j++);
			if (j - i > 1) {
				Eo(j - i);
				ans.clear();
				for (int u = i; u<j; u++) {
					ans.insert(GetSampleInfo(samples[u]));
					if (ans.size() >= 2) break;
				}
				if (ans.size() >= 2) break;
			}
		}
		E(Analyzed\n);

		printf("Case #%d: \n", tt);
		if (ans.size() >= 2) {
			vector<int64> v[2] = {*ans.begin(), *ans.rbegin()};

			for (int u = 0; u<2; u++) {
				for (int i = 0; i<v[u].size(); i++)
					printf(" %I64d", v[u][i]);
				printf("\n");
			}
			fflush(stdout);

			int64 control = 0;
			for (int i = 0; i<v[0].size(); i++) control += v[0][i];
			for (int i = 0; i<v[1].size(); i++) control -= v[1][i];
			Eo(control);
			assert(control == 0);
		}
		else printf("Impossible\n");
		fflush(stdout);
	}
	return 0;
}
