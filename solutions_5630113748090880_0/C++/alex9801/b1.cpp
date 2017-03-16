#include <stdio.h>
#include <string.h>
#include <algorithm>

#define TEST_NUM "b1"
//#define DEBUGGGGGGGGGGGGGGGGGGGGGGGGGG
char inname[100];
char outname[100];

int cnt[2560];

void process()
{
	memset(cnt, 0, sizeof(cnt));

	int n, a, i, j;
	scanf("%d", &n);
	for(i = 0; i<n*(2*n-1); i++)
	{
		scanf("%d", &a);
		cnt[a]++;
	}

	for(i = 1; i<=2500; i++)
		if(cnt[i]%2==1)
			printf("%d ", i);
}

void pre_process()
{

}

int main()
{
#ifndef DEBUGGGGGGGGGGGGGGGGGGGGGGGGGG
	sprintf(inname, "%s.in", TEST_NUM);
	sprintf(outname, "%s.out", TEST_NUM);
#endif
	freopen(inname, "r", stdin);
	freopen(outname, "w", stdout);
	int tn, ti;
	scanf("%d", &tn);
	pre_process();
	for(ti = 1; ti<=tn; ti++)
	{
		printf("Case #%d: ", ti);
		process();
		printf("\n");
	}
	return 0;
}