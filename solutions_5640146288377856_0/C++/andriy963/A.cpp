#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <math.h>
#include <stack>

using namespace std;
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	int R, C, W;
	int cnt;
	for(int t1 = 1;t1<=T;t1++)
	{
		scanf("%d%d%d", &R, &C, &W);
		if(R == 1)
		{
			if(W == 1)
				cnt = C;
			else
			{
				cnt = C/W + W;
				if(C%W == 0)
					cnt--;
			}
		}
		else
		{
			if(W == 1)
				cnt = C*R;
			else
			{
				cnt = C/W*R + W;
				if(C%W == 0)
					cnt--;
			}
		}
		printf("Case #%d: %d\n", t1, cnt);
	}
	system("Pause");
	return 0;
}
