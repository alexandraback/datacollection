#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// int cmp ( const void *a , const void *b )
// {
//   return  *(double *)a > *(double *)b ? 1 : -1;;  //升序排序
// }

long long a = 0;
long long b = 1;
long long count = 1;
int main()
{
	FILE* fp = 0;
	if(0 == ( fp = freopen("3a1.in", "w" ,stdout)))
   		 printf("Cannot open file.\n");
	int T = 0;
	scanf("%d",&T);

	for(int cT = 1; cT <= T; cT ++)
	{
		count = 0;
		scanf("%lld/%lld",&a,&b);
			
		for (int i = 0; b > a; ++i)
		{
			if(b %2)
			{
				count = 0;
				break;
			}
			b /= 2;
			if (b % 2)
			{
				/* code */
			}
			count ++;
		}
		if (count)
		{
			
			for (int i = 0; (b % 2) != 1 ; ++i)
			{
				b /= 2;
			}

			if (b != 1)
			{
				printf("Case #%d: impossible\n",cT);
			}else{
				printf("Case #%d: %lld\n",cT, count);
			}
		}else{
			printf("Case #%d: impossible\n",cT);
		}
	}
	fclose(fp);
}
