// Codejam.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "stdio.h"
#include <queue>

using namespace std;

#if 1

#define N		3

int main(void)
{
	int tst=1,n=3,k=4,r=2,m=4;
	int i,j;

	scanf("%d",&tst);
	for(i=1 ; i<=tst ; ++i)
	{
		printf("Case #%d:\n",i);

		scanf("%d %d %d %d",&r,&n,&m,&k);

		for(j=0 ; j<r ; ++j)
		{
			int a,b=1,aa,pted=0;

			for(aa=0 ; aa<k ; ++aa)
			{
				scanf("%d", &a);
				if(b<a)	b=a;
			}

			queue<int> q;
			for(a=2 ; a<=m ; a++)
				q.push(a);
			for(; !q.empty() ; q.pop())
			{
				int val;
				val = q.front();
				if(val<=99)
				{
					for(a=2 ; a<=m ; a++)
						q.push(val*10+a);
					continue;
				}
				int A = val%10;
				int B = val / 100;
				int C = (val / 10) % 10;

				if(A*B*C == b)
				{
					printf("%d\n", val);
					pted = 1;
					break;
				}
			}

			if(pted==0)
			{
				int aa,cc=2;
				for(aa=0 ; aa<n ; ++aa)
				{
					printf("%d",cc);
					if(++cc > m)	cc=2;
				}
				printf("\n");
			}
		}
	}

	fflush(stdin);
	getchar();
	return 0;
}

/*

1 3 4 4
9 4 36 1

*/
#endif