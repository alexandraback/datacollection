#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int T;
	int x,y;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ++ii)
	{
		scanf("%d%d", &x,&y);
		printf("Case #%d: ", ii);
		if(x>0)
		{
			for (int i = 0; i < x; ++i)
			{
				printf("WE");
			}
		}
		else
		{
			for (int i = 0; i < -x; ++i)
			{
				printf("EW");
			}
		}
		if(y>0)
		{
			for (int i = 0; i < y; ++i)
			{
				printf("SN");
			}
		}
		else
		{
			for (int i = 0; i < -y; ++i)
			{
				printf("NS");
			}
		}
		printf("\n");
	}
	return 0;
}