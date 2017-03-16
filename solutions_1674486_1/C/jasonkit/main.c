#include "stdio.h"

#define QSIZE 1000000

int main()
{
	int i,t;
	scanf("%d", &t);

	for(i=0;i<t;i++)
	{
		int j,n;

		char map[1000][1000] = {{0}};
		scanf("%d", &n);
		for(j=0; j<n; j++)
		{
			int k,m;
			scanf("%d", &m);
			for(k=0;k <m; k++)
			{
				int a;
				scanf("%d", &a);
				map[j][a-1] = 1;
			}
		}

		int is_diamond = 0;

		for(j=0; j<n; j++)
		{
			char visited[1000] = {0};
			int queue[QSIZE] = {0};
			int h=1;
			int t=0;
			queue[0]=j;
/*
			int r=t,s=h;
			printf("Q: ");
			while(r!=s)
			{
				printf("%d, ",queue[r]);
				r = (r+1)%QSIZE;
			}
			printf("\n");
*/

			while(h!=t)
			{
//				printf("h:%d t:%d\n",h,t);
				int c = queue[t];
				t = (t+1)%QSIZE;
				if(visited[c])
				{
					is_diamond = 1;
					break;
				}
				
				visited[c] = 1;
				
				int k;
				for(k=0; k<1000; k++)
				{
					if(map[c][k])
					{
						queue[h]=k;

						if(visited[k])
						{
							is_diamond = 1;
							break;
						}


						h = (h+1)%QSIZE;
					}

					if(is_diamond)
						break;
				}

				if(is_diamond)
					break;
			}
		
		}

		printf("Case #%d: %s\n",i+1,is_diamond?"Yes":"No");
	}
	return 0;
}
