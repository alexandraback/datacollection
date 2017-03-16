#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	int test;
	scanf("%d", &test);
	for(int testCount = 1; testCount <= test; testCount++) {
		int smax;
		static char buffer[11];
		scanf("%d %s", &smax, buffer);
		int answer = 0, exist = 0;
		for(int i = 0; i <= smax; i++) {
			int x = buffer[i] - '0';
			if (exist >= i) {
				exist += x;
			} else {
				answer += i - exist;
				exist = i + x;
			}
		}
		printf("Case #%d: %d\n", testCount, answer);
	}
	return 0;
}