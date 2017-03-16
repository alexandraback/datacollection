#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	int testnum;
	scanf("%d", &testnum);
	for (int testcase = 1; testcase <= testnum; ++testcase) {
		int shyness_max;
		char shyness[1010];
		scanf("%d %s", &shyness_max, shyness);

		int answer = 0;
		int num_audience = shyness[0] - '0';
		for (int i = 1; i <= shyness_max; ++i) {
			shyness[i] -= '0';
			int num_friend = shyness[i] == 0 ? 0 : max(0, i - num_audience);
			answer += num_friend;
			num_audience += shyness[i] + num_friend;
		}
		printf("Case #%d: %d\n", testcase, answer);
	}
	return 0;
}

