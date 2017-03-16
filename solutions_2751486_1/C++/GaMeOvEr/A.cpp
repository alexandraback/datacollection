#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<cmath>
#include<map>
#define _USE_MATH_DEFINES
using namespace std;

bool vowel(char c) {
	if ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u')) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int t, n;
	char name[1000010];
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%s %d", name, &n);
		int l = strlen(name);
		int a = 0;
		int b = 0;
		unsigned long long ans = 0;
		int count = 0;
		while (a < l) {
			if (count == n) {
				ans += l - b + 1;
				if (b - a == n) {
					count--;
				}
				a++;
				continue;
			}
			if (b == l) {
				break;
			}
			if (! vowel(name[b])) {
				count++;
				b++;
			}
			else {
				count = 0;
				b++;
			}
		}
		printf("Case #%d: %llu\n", i+1, ans);
	}
	return 0;
}
