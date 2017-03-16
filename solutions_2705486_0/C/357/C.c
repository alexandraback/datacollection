#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 521196

char D[521197][11];
int len[521197];
char s[4001];
int f[4001];

int main(int argc, const char *argv[])
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
    FILE *in = fopen("D.txt", "r");
    int o, T, i, j, t, k, tt, n, ans;
    for(i = 1; i <= N; ++i)
    {
        fscanf(in, "%s", D[i]);
        len[i] = strlen(D[i]);
    }
    for(scanf("%d", &T), o = 1; o <= T; ++o)
    {
        printf("Case #%d: ", o);
        scanf("%s", s+1);
        n = strlen(s+1);
        f[0] = 0;
        for(i = 1; i <= n; ++i)
			f[i] = 100000;
        for(i = 1; i <= n; ++i)
        {
			for(j = 1; j <= N; ++j)
			{
				t = -100; tt = 0;
				if(i + len[j] - 1 > n)
					continue;
				for(k = 0; k < len[j]; ++k)
					if(D[j][k] != s[i+k])
					{
						if(i - t <= 5)
							break;
						t = k; ++tt;
					}
				if(k >= len[j])
					if(tt + f[i-1] < f[i+len[j]-1])
						f[i+len[j]-1] = tt + f[i-1];
			}
        }
        printf("%d\n", f[n]);
    }
    return 0;
}
