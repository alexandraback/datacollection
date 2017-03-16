#include <stdio.h>
#include <string.h>

#define MAXN 1000005

int acc[MAXN];
long long l[MAXN];
char ent[MAXN];

char vows[] = {'a', 'e', 'i', 'o', 'u'};

int iscons(char c) {
	for(int i = 0; i < 5; i++)
		if(c == vows[i]) return 0;
	return 1;
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int ca = 0; ca < T; ca++) {
		int n;
		long long sol = 0;
		printf("Case #%d: ", ca+1);

		scanf("%s%d", ent, &n);

		memset(acc, 0, sizeof acc);
		memset(l, 0, sizeof l);
		for(int i = 0; ent[i]; i++) {
			if(iscons(ent[i]))
				acc[i+1] = acc[i]+1;
			if(acc[i+1] >= n) l[i+1] = i-n+2;
			else l[i+1] = l[i];
		}

		for(int i = 1; ent[i-1]; i++)
			sol = sol + l[i];

		printf("%lld\n", sol);

	}
	return 0;
}
