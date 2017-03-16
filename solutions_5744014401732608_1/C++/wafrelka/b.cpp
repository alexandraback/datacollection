#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

typedef long long int int64;

int main()
{
	int testcases;

	scanf("%d", &testcases);

	for(int case_num = 1; case_num <= testcases; ++case_num) {

		int b;
		int64 m;

		scanf("%d%lld", &b, &m);

		int64 maximum = 1LL << (b - 2);

		if(maximum < m) {
			printf("Case #%d: IMPOSSIBLE\n", case_num);
			continue;
		}

		vector<string> ans;

		ans.resize(b);
		for(int i = 0; i < b; ++i)
			ans[i].resize(b, '0');

		int64 diff = maximum - m;
		ans[0][b - 1] = '1';

		for(int v = 0; v < b - 2; ++v) {

			const int x = b - 2 - v;

			ans[0][x] = '1';

			const int z = diff >> (b - 3 - v);

			if((z & 1) == 0)
				ans[x][b - 1] = '1';

			for(int i = x + 1; i < b - 1; ++i)
				ans[x][i] = '1';
		}

		printf("Case #%d: POSSIBLE\n", case_num);
		for(auto s : ans)
			printf("%s\n", s.c_str());
	}

	return 0;
}
