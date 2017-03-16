#include <cstdio>
#include <string>
using namespace std;

char buf[1024];

int main() {
	int T;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		scanf("%s", buf);
		string ans = string(1, buf[0]);
		for (int i = 1 ; buf[i] ; ++i) {
			if (buf[i] >= ans[0]) {
				ans = string(1, buf[i]) + ans;
			} else {
				ans = ans + string(1, buf[i]);
			}
		}
		printf("Case #%d: %s\n", ca, ans.c_str());
	}
	return 0;
}