#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int64;

int main()
{
	int testcase;

	scanf("%d", &testcase);

	for(int case_num = 0; case_num < testcase; ++case_num) {

		int k, c, s;

		scanf("%d%d%d", &k, &c, &s);

		if(s * c < k) {
			printf("Case #%d: IMPOSSIBLE\n", case_num + 1);
			continue;
		}

		int next = 0;
		vector<int64> ans;

		for(int sample = 0; sample * c < k; ++sample) {

			int64 pos = 0;

			for(int step = 0; step < c; ++step) {
				pos = pos * k + next;
				next = min(next + 1, k - 1);
			}

			if(ans.empty() || ans.back() != pos)
				ans.push_back(pos);
		}

		printf("Case #%d:", case_num + 1);
		for(auto a : ans)
			printf(" %lld", a + 1);
		printf("\n");
	}

	return 0;
}
