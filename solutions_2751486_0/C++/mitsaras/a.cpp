#include <map>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

char name[1000009];

int iscons (char a) {
	switch (a) {
		case 'a': return 0;
		case 'e': return 0;
		case 'i': return 0;
		case 'o': return 0;
		case 'u': return 0;
		default: return 1;
	}
}

int solve () {
	int n;

	scanf("%s %d", name, &n);
	int l = strlen(name);
	int s = 0;
	int e = 1;
	int count = 0;

	int acc = 0;
	int left = 0, right = 0;
	while (e <= l) {
		while (iscons(name[e-1]) && count < n && e <= l) {
			e++;
			count++;
		}
		if (count == n) {
			left = e - n - s;
			right = l - e + 2;
			acc += left * right;
			s = e - n;
			count--;
		} else {
			e++;
			count = 0;
		}
	}

	return acc;
}

int main () {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
		printf("Case #%d: %d\n", i, solve());

	return 0;
}
