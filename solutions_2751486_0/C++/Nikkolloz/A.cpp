#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int tc, n;
char s[1000010];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &tc);
	for (int tn = 0; tn < tc; tn++) {
		scanf("%s%d", &s, &n);
		int k = 0, p = 0;
		int l = strlen(s);
		long long res = 0;
		for (int i = 0; i < l; i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
				k = 0;
			else
				k++;
			if (k >= n) {
				res += (i-n+1-p+1)*(long long)(l-i);
				p = i-n+2;
			}
		}
		printf("Case #%d: %lld\n", tn+1, res);
	}
	return 0;
}