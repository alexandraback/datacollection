#include <stdio.h>
#include <algorithm>
#include <deque>

#define TEST_NUM "a2"
//#define DEBUGGGGGGGGGGGGGGGGGGGGGGGGGG
char inname[100];
char outname[100];

char arr[1010];
char res[1010];

void process()
{
	bool u;
	int i, j;
	scanf("%s", arr);

	res[0] = arr[0];
	res[1] = '\0';
	for(i = 1; arr[i]; i++)
	{
		u = 1;
		for(j = 0; j<i; j++)
		{
			if(arr[i]==res[j])
				continue;
			u = arr[i]>res[j] ? 0 : 1;
			break;
		}

		if(u)
			res[i] = arr[i];
		else
		{
			for(j = i; j>=1; j--)
				res[j] = res[j-1];
			res[0] = arr[i];
		}

		res[i+1] = '\0';
	}

	printf("%s", res);
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