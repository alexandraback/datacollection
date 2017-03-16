#include <stdio.h>
#include <string.h>

int k, l, n;
char a[112], w[112];
bool is[256];

int next[1123];

int foo(int i, char c)
{
	if(i == 0)
		return (c == w[0]) ? 1 : 0;
 
	if(w[next[i]] == c)
		return next[i] + 1;
 
	else
		return foo(w[i], c);
}
 
void process()
{
	next[0] = 0;
	next[1] = 0;
	for(int i = 2; i <= l; i++)
		next[i] = foo(i-1, w[i-1]);
}

double tab[112][112];
bool been[112][112];

double pd(int i, int x)
{
	if(x == l)
		return 1.0 + pd(i, next[l]);

	if(i == n)
		return 0.0;
	if(been[i][x])
		return tab[i][x];
	
	double retv = 0.0;
	for(int j = 0; j < k; j++)
	{
		int prevx = x;
		
		while(x != 0 && w[x] != a[j])
			x = next[x];
		
		if(w[x] == a[j])
			retv += pd(i+1, x+1);
		else
			retv += pd(i+1, 0);
		
		x = prevx;
	}
	been[i][x] = true;
//	printf("%lf\n", retv);
	return tab[i][x] = (retv/double(k));
}

int
main(void)
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		memset(is, 0, sizeof(is));
		memset(been, 0, sizeof(been));
		bool bosta = false;
		scanf("%d %d %d", &k, &l, &n);
		scanf("%s %s", a, w);
		printf("Case #%d: ", t);
		for(int i = 0; i < k; i++)
			is[a[i]] = true;
		for(int i = 0; i < l; i++)
			if(!is[w[i]])
				bosta = true;
		if(l > n || bosta)
		{
			printf("0.0\n");
			continue;
		}
		
		process();
		int take = 0;
		
		for(int i = 0; i + l - 1 < n; i += (l - next[l]))
			take++;
		
		printf("%lf\n", take - pd(0, 0));
	}
}





















