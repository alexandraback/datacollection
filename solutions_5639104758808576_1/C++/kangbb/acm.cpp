#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <cstring>
using namespace std;


int main() {
	int cases;
	int caseid = 1;
	int N;
	char s[ 1005 ];

	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	scanf("%d", &cases);
	while(cases--) {

		scanf("%d%s", &N, s);

		int add = 0;
		int up = 0;
		for(int i = 0; i < N + 1; i++) {
			if (up < i) {
				add += i - up;
				up = i;
			}
			up += s[i] - '0';
		}



		printf("Case #%d: %d\n", caseid++, add);
	}
	return 0;
}

