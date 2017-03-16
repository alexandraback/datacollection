#include <cstdio>

int main()
{
	int test_case;

	scanf("%d", &test_case);

	for(int case_num = 1; case_num <= test_case; ++case_num) {

		const int max_s = 2000;
		int s;
		char count[max_s];

		scanf("%d %s", &s, count);

		int ans = 0;

		while(true) {

			int cur = ans;
			bool ok = true;

			for(int level = 0; level <= s; ++level) {
				if(cur < level)
					ok = false;
				cur += (count[level] - '0');
			}

			if(ok)
				break;

			ans += 1;
		}

		printf("Case #%d: %d\n", case_num, ans);

	}

	return 0;
}
