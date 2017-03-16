
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int numCases = 0;
	
	int L;
	int n;
	int i,j,jj,k;
	int total;
	char name[1000001];

	char starts[1000001];

	int lenStarts = 0;

	scanf("%d",&numCases);

	for (i=0;i<numCases;i++)
	{	
		total = 0;
		scanf("%s",name);
		scanf("%d",&n);
		L = strlen(name);

		for (j=0;j<L;j++)
			for (jj=0;jj<L;jj++)
			{
				int cnt=0;
				int ok = 0;
				for (k=j;k<=jj;k++)
				{
					char c = name[k];
					if (c!='a' && c!='e' && c!='i' && c!='o' && c!='u')
					{
						cnt++;
					}
					else
					{
						cnt = 0;
					}
					if (cnt>=n) ok =1;
				}
				if (ok) total++;
			}

		printf("Case #%d: %d\n",i+1,total);
	}

	return 0;
	
}
