#include <cstdio>
#include <cstring>

char str[1000005];
int d[1000005];

int isConsonant(char c) {
	return c != 'a' && c != 'i' && c != 'o' && c != 'u' && c != 'e';
}

int main() {
	int r;
	scanf("%d", &r);
	for (int cs = 1; cs <= r; ++cs) {
		printf("Case #%d: ", cs);

		int n;
		scanf("%s %d", str + 1, &n);
		int L = strlen(str + 1);	
		memset(d, 0, sizeof(d));
		
		long long sol = 0;
		int x = -1;
		for (int i = 1; i <= L; ++i) {
			if (isConsonant(str[i])) d[i] = d[i - 1] + 1;	
			if (d[i] >= n) {
				x = i;
			}
			if (x != -1) {
				sol += x - n + 1;
			}
		}
		printf("%lld\n", sol);
	}
	return 0;
}
