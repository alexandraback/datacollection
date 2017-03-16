#include <stdio.h>
#include <set>
using namespace std;
int main()
{
	freopen("in.in", "r", stdin);
	freopen("out", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt)
	{
		int a, b;
		scanf("%d%d",&a,&b);
		int x= 1;
		while(a/x)x*=10;
		int r = 0;
		for(int i = a; i <b; ++i)
		{
			set<int> s;
			for(int y = 10;y<x;y*=10)
			{
				int j=i%y*(x/y)+i/y;
				if(j<=b&&j>i&&s.find(j)==s.end())
					{
					s.insert(j);
//					printf("%d %d\n",i,j);
					++r;
					}
			}
		}
		printf("Case #%d: %d\n",tt,r);
	}
	return 0;
}
