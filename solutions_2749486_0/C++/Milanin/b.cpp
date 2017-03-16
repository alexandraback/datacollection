#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
using namespace std;
#define N 100
int main()
{
	int ts, tst, x, y;
	for(scanf("%d", &tst), ts=1; ts<=tst; ts++)
	{
		printf("Case #%d: ", ts);
		scanf("%d%d", &x, &y);
		for(; x>0; printf("WE"), x--);
		for(; x<0; printf("EW"), x++);
		for(; y>0; printf("SN"), y--);
		for(; y<0; printf("NS"), y++);
		printf("\n");
	}
	return 0;
}