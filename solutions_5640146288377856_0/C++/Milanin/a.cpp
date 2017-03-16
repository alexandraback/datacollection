#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:100000000")
#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;

void solve()
{
	int r, c, w;
	scanf("%d%d%d", &r, &c, &w);
	int a;
	if(w==1) a=r*c;
	else
	{
		a=(r-1)*(c/w);
		if(c%w==0) a+=c/w+w-1;
		else a+=c/w+w;
	}
	printf("%d\n", a);
}
int main()
{
	int tst;
	scanf("%d", &tst);
	for(int ts=1; ts<=tst; ts++)
	{
		printf("Case #%d: ", ts);
		solve();
	}
	return 0;
}