#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

//1 2 4 8 16

int n;
int d[112];
bool been[10][32];
bool tab[10][32];
int v;

bool pd(int i, int a)
{
	if(a < 0)
		return false;
	if(a == 0)
		return true;
	if(i < 0)
		return false;
	if(been[i][a])
		return tab[i][a];
	been[i][a] = true;
	return tab[i][a] = (pd(i-1, a - d[i]) || pd(i-1, a));
}

int foo(int i)
{
	if(i == n + 4)
	{
		memset(been, 0, sizeof(been));
		bool ok = true;
		for(int j = 1; j <= v; j++)
			ok = (ok && pd(n+3, j));
		if(!ok)
		{
			return 0x3f3f3f3f;
		}
		int retv = 0;
		for(int j = n; j < n + 4; j++)
			if(d[j])
				retv++;
	//	printf("%d\n", retv);
		return retv;				
	}
	int retv = 0x3f3f3f3f;
	for(int j = 0; j <= v; j++)
	{
		d[i] = j;
	//	printf("%d\n", d[i]);
	//	d[20]++;
		retv = min(retv, foo(i+1));
	}
	return retv;
}

int
main(void)
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%*d %d %d", &n, &v);
		for(int i = 0; i < n; i++)
			scanf("%d", &d[i]);
			
	//	printf("%d\n", pd(2, 3));
		printf("Case #%d: ", t);
		printf("%d\n", min(5, foo(n)));
	}
}
