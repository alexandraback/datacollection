#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	char s[1008], res[1008], tmp[1008];
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	scanf("%d", &t);
	for (int cas=1; cas<=t; cas++)
	{
		int i;
		scanf("%s", s);
		res[0]=s[0];
		res[1]=0;
		for (i=1; s[i]; i++)
		{
			strcpy(tmp+1, res);
			tmp[0]=s[i];
			res[i]=s[i];
			res[i+1]=0;
			if (strcmp(tmp, res)>0) strcpy(res, tmp);
		}
		printf("Case #%d: %s\n", cas, res);
	}
	return 0;
}
		
