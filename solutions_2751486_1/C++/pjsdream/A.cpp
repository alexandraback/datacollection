#include <string.h>
#include <stdio.h>

int n, m;
char data[1000010];

bool consonant(char x) {
	return x=='a' || x=='e' || x=='i' || x=='o' || x=='u';
}

int cnt[1000010];

int main()
{
	freopen ("a.in", "r", stdin);
	freopen ("a.out", "w", stdout);

	int t, tt=0;
	scanf ("%d", &t);
	while (t--) {
		scanf ("%s%d", data, &m);
		n = strlen(data);

		cnt[0] = !consonant(data[0]);
		for (int i=1; i<n; i++) {
			if (!consonant(data[i])) cnt[i] = cnt[i-1] + 1;
			else cnt[i] = 0;
		}

		int lastidx = -1;
		long long ans=0;
		for (int i=0; i<n; i++) {
			if (cnt[i] >= m)
				lastidx = i;
			if (lastidx>=0)
				ans += lastidx - m + 2;
		}

		printf ("Case #%d: ", ++tt);
		printf ("%lld\n", ans);
	}

	return 0;
}
