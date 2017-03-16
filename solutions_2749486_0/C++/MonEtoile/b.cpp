#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<functional>
#include<algorithm>

using namespace std;

//#define _INFILE		"B.in"
//#define _OUTFILE	"B.out"

#define _INFILE		"B-small-attempt1.in"
#define _OUTFILE	"B-small.out"

//#define _INFILE		"B-large.in"
//#define _OUTFILE	"B-large.out"
	
void solve()
{
	char str[512];
	int len = 0;
	int x, y;
	scanf("%d%d",&x,&y);
	if (x < 0)
	{
		for(int i=0; i<-x; i++)
		{
			str[len++] = 'E';
			str[len++] = 'W';
		}
	}
	else if (x > 0)
	{
		for(int i=0; i<x; i++)
		{
			str[len++] = 'W';
			str[len++] = 'E';
		}

	}
	if (y < 0)
	{
		for(int i=0; i<-y; i++)
		{
			str[len++] = 'N';
			str[len++] = 'S';
		}
	}
	else if (y > 0)
	{
		for(int i=0; i<y; i++)
		{
			str[len++] = 'S';
			str[len++] = 'N';
		}
	}


	str[len] = '\0';
	printf("%s\n", str);
}

int main(void)
{
	int T;
	freopen(_INFILE, "r", stdin);
	freopen(_OUTFILE, "w", stdout);

	scanf("%d",&T);

	for(int i=0; i<T; i++)
	{
		printf("Case #%d: ", i+1);
		solve();
	}
	return 0;
}

