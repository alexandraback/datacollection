#include <stdio.h>

int main()
{
	int _T;
	scanf("%d",&_T);
	int k,c,s;
	for(int CAS = 1; CAS <= _T; CAS++)
	{
		scanf("%d%d%d",&k,&c,&s);
		printf("Case #%d:", CAS);
		for(int i = 1; i <= s; i++)
			printf(" %d", i);
		puts("");
	}
}