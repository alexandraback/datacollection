#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <algorithm>
#include <bitset>

using namespace std;

int main()
{
	freopen("try.in", "r", stdin);
	freopen("try.out", "w", stdout);
	int Test;
	scanf("%d", &Test);
	for (int TT=1; TT<=Test; ++TT)
	{
		printf("Case #%d: ", TT);
		int k,c,s;
		scanf("%d%d%d",&k,&c,&s);
		for (int i=1;i<=s;++i)
			printf(i==1?"%d":" %d", i);
		puts("");
	}
	return 0;
}
