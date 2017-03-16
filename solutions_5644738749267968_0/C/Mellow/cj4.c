#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp ( const void *a , const void *b )
{
  return  *(double *)a > *(double *)b ? 1 : -1;;  //升序排序
}
double a[10000];
double b[10000];
int n = 0;
int r1 = 0;
int r2 = 0;

int main()
{
	FILE* fp = 0;
	if(0 == ( fp = freopen("cj3a.in", "w" ,stdout)))
   		 printf("Cannot open file.\n");
	int T = 0;
	scanf("%d",&T);

	for(int cT = 0; cT < T; cT ++)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		r1 = r2 = 0;		
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf",a + i);
		}
		qsort(a,n,sizeof(a[0]),cmp);
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf",b + i);
		}
		qsort(b,n,sizeof(b[0]),cmp);

		for (int i = 0; i < n; ++i)
		{
			if (a[i] > b[r1])
			{
				r1 ++;
			}
		}
		for (int i = 0; i < n; ++i)
		{
			if (b[i] > a[r2])
			{
				r2 ++;
			}
		}
		printf("Case #%d: %d %d\n",cT + 1, r1, n - r2 );
	}
	fclose(fp);
}
