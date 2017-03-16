#include <stdio.h>

long long int m(long long int a, long long int b)
{
	return a * b % 1000000007;
}

long long int ff(int i)
{
	if (i == 0) return 1;
	return m(i, ff(i - 1));
}

int main(void)
{
	int T, x, N, i, j, k, ex[26], sin[26], occ[26], n[26], c0, c1, f, p, w, asdf, pred[26];
	long long int y;
	char s[101];
	scanf("%d ", &T);
	for (x = 1; x <= T; x++)
	{
		scanf("%d ", &N);
		p = f = 0;
		for (i = 0; i < 26; i++)
		{
			sin[i] = ex[i] = occ[i] = 0;
			pred[i] = n[i] = -1;
		}
		for (i = 0; i < N; i++)
		{
			scanf("%[^ \n] ", s);
			c0 = s[j = 0];

			while (s[++j] == c0);
			if (!s[j])
			{
//printf("single %c\n", c0);
				sin[c0 - 'a']++;
			}
			else
			{
				while (1)
				{
					c1 = s[j];
//printf("%c\n", c1);
					while (s[++j] == c1);
					if (!s[j])
					{
//printf("pair %c%c\n", c0, c1);
						if (n[c0 - 'a'] != -1) f++;
						n[c0 - 'a'] = c1 - 'a';
						pred[c1 - 'a'] = c0 - 'a';
						occ[c0 - 'a']++;
						occ[c1 - 'a']++;
						p++;
						break;
					}
					if (ex[c1 - 'a']) f++;
					ex[c1 - 'a'] = 1;
				}
			}
		}

//printf("abc\n");
		for (i = 0; i < 26; i++)
		{
			if (sin[i] > 0 && ex[i] > 0) break;
			if (n[i] != -1 && (ex[i] || ex[n[i]])) break;
		}
		f += (i < 26);

		w = 0;
		i = 0;
//printf("abc\n");
		while(1)
		{
			for (; i < 26; i++)
				if (occ[i] == 1 && pred[i] == -1)
					break;
			if (i == 26)
				break;
//printf("try %c\n", (char)(i + 'a'));
			j = 0;
			k = i;
			while (n[k] != -1)
			{
				asdf = k;
				k = n[k];
				n[asdf] = -1;
				p--;
			}
			w++;
			i++;
		}
//printf("abc\n");
		if (f)
		{
			printf("Case #%d: 0\n", x);
			continue;
		}

		y = 1;
		k = 0;
		for (j = 0; j < 26; j++)
		{
			if (occ[j] == 0 && sin[j]) k++;
			y = m(y, ff(sin[j]));
//printf("?%d\n", (int)y);
		}
		y = m(y, ff(k + w + p));
//printf("?%d %d\n", k, (int)y);

		printf("Case #%d: %d\n", x, (int)y);
	}
	return 0;
}