#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
using namespace std;


int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int T, kase = 0;
	scanf("%d", &T);
	while (++kase <= T) {
		int n;
		char str[110];
		scanf("%s", str);
		n = strlen(str);
		int cnt = 0;
		for (int i = 1; i < n; i++)
			if (str[i - 1] != str[i])
				cnt++;
		if (str[n - 1] == '-')
			cnt++;
		printf("Case #%d: %d\n", kase, cnt);
	}

	return 0;
}