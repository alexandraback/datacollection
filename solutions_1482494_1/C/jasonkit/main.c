#include "stdio.h"
#include "stdlib.h"
int a[1000];
int b[1000];

int ca[1000];
int cb[1000];


typedef struct _item item;
struct _item{
	int index;
	int value;
};

int cmp(const void* a, const void* b)
{
	return (((item*)b)->value -  ((item*)a)->value);
}

int main()
{
	int t,i;

	scanf("%d", &t);
	for(i=0; i<t; i++)
	{
		int n,j;
		scanf("%d", &n);
		for(j=0; j<n; j++)
		{
			scanf("%d %d", &a[j], &b[j]);

			ca[j]=cb[j]=0;
		}

		int star=0;
		int count=0;

		while(1)
		{
			int v;
			int last_star = star;

			item map[1000] = {{0,0}};
			int map_cnt = 0;
			
//			printf("Next Loop:\n");

			for(v=0; v<n; v++)
			{
				if(cb[v])
					continue;

				if(star >= b[v])
				{
//					printf(">> Play Level %d for 2 star with star:%d (%d,%d)\n",v+1,star,a[v],b[v]);
					if(ca[v])
						star += 1;
					else
						star += 2;

					ca[v]=1;
					cb[v]=1;
					count++;
				}else{
					map[map_cnt].index = v;
					map[map_cnt].value = b[v];
					map_cnt++;
				}
			}


			if(star == 2*n)
				break;

			if(last_star != star)
			{
//				printf(">> A: star:%d count:%d\n",star,count);
				continue;
			}

			qsort(map,map_cnt,sizeof(item),cmp);

			for(v=0; v<map_cnt; v++)
			{
//				printf(">>>>>map[%d].value=%d index:%d ca:%d\n",v,map[v].value,map[v].index,ca[map[v].index]);
			}
//			printf("-------\n");

#if 1
			for(v=0; v<map_cnt; v++)
			{

				if(ca[map[v].index])
					continue;

//				printf(">>>>>>>>Play Level %d for 1 star with star:%d (%d,%d)\n",map[v].index+1,star,a[map[v].index],b[map[v].index]);
				if(star >= a[map[v].index])
				{
//					printf(">> Play Level %d for 1 star with star:%d (%d,%d)\n",map[v].index+1,star,a[map[v].index],b[map[v].index]);
					star++;
					ca[map[v].index]=1;
					count++;
					break;
				}
			}

#else			
			for(v=0; v<n; v++)
			{
//				printf(">>>v:%d a:%d ca:%d\n",v,a[v],ca[v]);

				if(ca[v])
					continue;

				if(star >= a[v])
				{
//					printf(">> Play Level %d with star:%d (%d,%d)\n",v+1,star,a[v],b[v]);
					star++;
					ca[v]=1;
					count++;
					break;
				}
			}
#endif
			if(last_star == star)
			{
//				printf("TOO BAD???\n");
				break;
			}
			
//			printf(">> B: star:%d count:%d\n",star,count);
		}

		if(star == 2*n)
		{
			printf("Case #%d: %d\n",i+1,count);
		}else{
			printf("Case #%d: Too Bad\n",i+1);
		}
	}


	return 0;
}
