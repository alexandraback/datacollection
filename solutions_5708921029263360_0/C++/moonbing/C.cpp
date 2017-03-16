#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

struct F {
	int J, P, S;
};
int T;
int J, P, S, K;
vector<F> list, test, res;
int max;
map<int, vector<F> > cache;
int bb;
bool bbbb;

void Solve(int day) {
	int i, j;
	int len = list.size();
	for (i = 0; i < len; i++) {
		bool err = false;
		int count1 = 0, count2 = 0, count3 = 0;
		for (j = 0; j < day; j++) {
			if (list[i].J == test[j].J && list[i].P == test[j].P) count1++;
			if (list[i].J == test[j].J && list[i].S == test[j].S) count2++;
			if (list[i].P == test[j].P && list[i].S == test[j].S) count3++;
			if (list[i].J == test[j].J && list[i].P == test[j].P && list[i].S == test[j].S) err = true;
		}
		if (count1 + count2 + count3 < K && !err) {
			test.push_back(list[i]);
			Solve(day + 1);
			test.pop_back();
			if (bbbb) return;
		}
	}
	if (max < day) {
		max = day;
		res.clear();
		int total = test.size();
		for (i = 0; i < total; i++)
			res.push_back(test[i]);
		bb++;
		if (day == J*P*S || bb >= 1) bbbb = true;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t, i, j, k;

	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d %d %d %d", &J, &P, &S, &K);
		int set = J * 100 + P * 10 + S + K * 1000;
		if (cache.find(set) == cache.end()) {
			max = 0;
			list.clear();
			for (i = 1; i <= J; i++) {
				for (j = 1; j <= P; j++) {
					for (k = 1; k <= S; k++)
						list.push_back({ i,j,k });
				}
			}
			bb = 0; bbbb = false;
			Solve(0);
			printf("Case #%d: ", t);
			printf("%d\n", max);
			for (i = 0; i < max; i++)
				printf("%d %d %d\n", res[i].J, res[i].P, res[i].S);
			cache[set] = res;
		}
		else {
			int len = cache[set].size();
			printf("Case #%d: ", t);
			printf("%d\n", len);
			for (i = 0; i < len; i++)
				printf("%d %d %d\n", cache[set][i].J, cache[set][i].P, cache[set][i].S);
		}
	}
	return 0;
}
