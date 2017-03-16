#include <stdio.h>
#include <vector>
#include <string.h>
#include <string>

using namespace std;

int Solve(int set, vector<pair<string, string>> &vt, int N)
{
	int ret = 0;
	for (int i = 0; i < N; i++) {
		int checker = 1 << i;

		if (set & checker) {
			bool flag_a = false;
			bool flag_b = false;
			for (int m = 0; m < vt.size(); m++) {
				if (i == m) continue;
				int check_fake = 1 << m;
				if (set & check_fake) continue;

				if (vt[m].first == vt[i].first)
					flag_a = true;
				if (vt[m].second == vt[i].second)
					flag_b = true;
			}

			if (flag_a && flag_b)
				ret++;
			else
				return -1;
		}
		else {
			continue;
		}

	}

	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);
	
	for (int w = 0; w < T; w++) {
		int N;
		scanf("%d", &N);

		vector<pair<string, string>> vt;

		for (int i = 0; i < N; i++) {
			char A[30], B[30];
			scanf("%s %s", A, B);

			vt.push_back(pair<string, string>(A, B));
		}

		int ret = -1;
		int len = 1 << N;
		for (int i = 0; i < len; i++) {
			int temp = Solve(i, vt, N);
			if (temp > ret)
				ret = temp;
		}

		printf("Case #%d: %d\n", w + 1, ret);
	}
	
	

	return 0;
}