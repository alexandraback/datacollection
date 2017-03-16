#include <queue>
#include <bitset>
#include <stdio.h>
#include <string.h>

using namespace std;

#define MAXN 9091
#define MAXE 2000100

int a[510], N;

int head[MAXN], sum[MAXE], s[MAXE], nxt[MAXE], eg;

int sethh(int val, int sb)
{
	int st = val % MAXN;
	int e = head[st];

	while (e != -1) {
		if (sum[e] == val)
			return s[e];
		e = nxt[e];
	}

	sum[eg] = val;
	s[eg] = sb;
	nxt[eg] = head[st];
	head[st] = eg++;
	return -1;
}

int set1[510], sn1;
int set2[510], sn2;

int find(int i, int sb, int s)
{
	if (i > N) {
		int t, ret = sethh(s, sb);
		if (ret == -1) return 0;
		sn1 = sn2 = 0; t = 1;
		while (sb > 0) {
			if (sb & 1) set1[sn1++] = a[t];
			sb >>= 1; t++;
		}
		t = 1;
		while (ret > 0) {
			if (ret & 1) set2[sn2++] = a[t];
			ret >>= 1; t++;
		}

		return 1;
	}

	if (find(i + 1, sb, s)) return 1;
	if (find(i + 1, sb | (1 << (i - 1)), s + a[i])) return 1;

	return 0;
}

int main()
{
	int T, t, i;

	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d", &N);

		eg = 0;
		memset(head, -1, sizeof(head));
		for (i = 1; i <= N; i++) {
			scanf("%d", &a[i]);
		}

		printf("Case #%d:\n", t);
		if (find(1, 0, 0)) {
			for (i = 0; i < sn1; i++) {
				if (i) printf(" ");
				printf("%d", set1[i]);
			}
			printf("\n");
			for (i = 0; i < sn2; i++) {
				if (i) printf(" ");
				printf("%d", set2[i]);
			}
			printf("\n");
		}
		else printf("Impossible\n");
	}

	return 0;
}

