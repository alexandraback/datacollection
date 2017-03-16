
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int R, C, W;

int main(void)
{	int T, TT = 1;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d %d", &R, &C, &W);
		printf("Case #%d: %d\n", TT++, ((W-1) + (C/W) + (C%W != 0)) + (R-1)*(C/W));
	}
	return 0;
}
