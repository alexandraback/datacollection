#include <stdio.h>
#include <string.h>

char keyb[110];
char typed[110];
char pstrings[823600][110];
int pi[110];
int banhits[15];
int z = 0,S,K;

void rec(int i, char str[])
{
	int j;
	if(i == S)
	{
		str[i] = '\0';
		for(j = 0; j <= S; ++j)
			pstrings[z][j] = str[j];

		++z;
		return;
	}

	//char str1[15];

	for(j = 0; j < K; ++j)
	{
		str[i] = keyb[j];
		/*for(k = 0; k <= i; ++k)
			str1[i] = str[i];*/
		rec(i+1, str);
	}
}

void prec()
{
	pi[0] = -1;
	int k = -1,	m = strlen(typed),i;

	for(i= 1; i <= m; ++i) 
	{
		k = pi[i-1];
		while(k > -1 && typed[k] != typed[i-1]) k = pi[k];
		pi[i] = k + 1;
	}
}

inline int gethitcount(int z)
{
	int i,j,k,m,count;
	i = 0;
	k = 0;
	j = 0;
	m = strlen(typed);
	char c;
	count = 0;

	while(1)
	{
		c = pstrings[z][j];
		if(c == '\0') break;
		while(k > -1 && typed[k] != c) k = pi[k];
		++k; ++i;
		if(k == m)
		{
			++count;
			k = pi[k];
		}
		++j;
	}

	return count;
}

int main()
{
	int T,i,L,j,k, maxhits;
	char str[15];

	scanf("%d",&T);
	for(k = 1; k <= T; ++k)
	{
		scanf("%d", &K);
		scanf("%d", &L);
		scanf("%d", &S);
		scanf("%s", keyb);
		scanf("%s", typed);

		z = 0;
		for(i = 0; i < K; ++i)
		{
			str[0] = keyb[i];
			rec(1,str);
		}

		prec();

		for(i = 0; i < 15; ++i)
			banhits[i] = 0;

		maxhits = -1;
		for(i = 0; i < z; ++i)
		{
			/*printf("%s\n", pstrings[i]);
			printf("hits with this = %d\n", gethitcount(i));*/
			j = gethitcount(i);
			if(j > maxhits) maxhits = j;

			++banhits[j];
		}

		double ans = 0;

		for(i = 0; i < maxhits; ++i)
			ans += (maxhits-i)*((double)banhits[i]/z);
		
		printf("Case #%d: %0.7lf\n", k,ans);
	}

	return 0;
}