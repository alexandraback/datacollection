#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;


int main()
{
	int testcase;

	scanf("%d", &testcase);

	for(int case_num = 0; case_num < testcase; ++case_num) {

		char str[1024];

		scanf("%s", str);
		int len = strlen(str);
		int ans = 0;

		for(int i = 0; i < len - 1; ++i) {
			if(str[i] != str[i + 1])
				ans += 1;
		}
		if(str[len - 1] == '-')
			ans += 1;

		printf("Case #%d: %d\n", case_num + 1, ans);
	}

	return 0;
}
