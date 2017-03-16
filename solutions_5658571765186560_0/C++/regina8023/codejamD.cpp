#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#define G printf("GABRIEL\n")
#define R printf("RICHARD\n")
using namespace std;
int T;
int main()
{
	freopen("t.in","r",stdin);freopen("t.out","w",stdout);
    scanf("%d",&T);
	for (int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		int x,r,c;
		scanf("%d%d%d",&x,&r,&c);
		if ((r*c)%x)
		{
			R;continue;
		}
		switch (x)
		{
			case 1:
				G;
				break;
			case 2:
				G;
				break;
			case 3:
				if (r==1||c==1) R;
				else
					G;
				break;
			case 4:
				if (r==1||c==1||r==2||c==2) R;
				else
					G;
				break;
		}
	}
	return 0;
}
