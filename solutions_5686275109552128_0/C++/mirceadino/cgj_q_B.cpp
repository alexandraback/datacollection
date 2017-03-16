#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

int number_of_cases, testcase;
int N, sol;
int V[1005];

int check(int val) {
	int i;

	for (int s = 0; s <= 1000; s++) {
		priority_queue<int> PQ;
		int cnt = s;

		for (i = 1; i <= N; i++)
			PQ.push(max(0, V[i] - s));

		while ((cnt <= val) && (cnt + PQ.top() > val)) {
			int x = PQ.top();
			PQ.pop();
			PQ.push(x / 2);
			PQ.push(x - x / 2);
			cnt++;
		}

		cnt += PQ.top();

		if (cnt <= val)
			return 1;
	}

	return 0;
}

int main() {
	int cnt, S, i;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &number_of_cases);

	for (testcase = 1; testcase <= number_of_cases; testcase++) {
		scanf("%d", &N);

		for (i = 1; i <= N; i++)
			scanf("%d", &V[i]);

		sol = 1000;

		for (S = 1; S <= 1000; S++) {
			cnt = 0;

			for (i = 1; i <= N; i++)
				cnt += (V[i] - 1) / S;

			cnt += S;

			sol = min(sol, cnt);
		}

		printf("Case #%d: %d\n", testcase, sol);
	}

	return 0;
}