#include <stdio.h>
#include <algorithm>
using namespace std;

int cs, ct;
int n, s, p, ans;
int t[200];

int main()
{
	int i, j;

	scanf("%d", &cs);
	for (ct = 1; ct <= cs; ct++) {
		scanf("%d%d%d", &n, &s, &p);
		for (i = 0; i < n; i++)
			scanf("%d", &t[i]);
		sort(t, t + n);
		ans = 0;
		for (i = 0; i < n; i++) {
			if (p >= 2 && t[i] == p + (p - 1) + (p - 2) && s) {
				ans++;
				s--;
			}
			else if (p >= 2 && t[i] == p + (p - 2) + (p - 2) && s) {
				ans++;
				s--;
			}
			else if (t[i] > p + (p - 1) + (p - 2)) ans++;
		}
		printf("Case #%d: %d\n", ct, ans);
	}	
	return 0;
}
