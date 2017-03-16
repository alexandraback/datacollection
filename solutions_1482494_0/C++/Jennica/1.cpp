#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

typedef struct PO
{
	int a,b,order;
}LEVEL;

LEVEL level[1010],la[1010],lb[1010];
int ok1[1010],ok2[1010];

int cmpa(const void*aa,const void *bb)
{
	LEVEL * _a=(LEVEL*)aa;
	LEVEL * _b=(LEVEL*)bb;
	if(_a->a<_b->a)
		return -1;
	else if(_a->a>_b->a)
		return 1;
	else
	{
		if(_a->b>_b->b)
			return -1;
		else if(_a->b<_b->b)
			return 1;
		else 
			return 0;
	}
}

int cmpb(const void*aa,const void *bb)
{
	LEVEL * _a=(LEVEL*)aa;
	LEVEL * _b=(LEVEL*)bb;
	return _a->b-_b->b;
}

int main()
{
	int T,t,N,i,sum,now,OK,count;
//	freopen("B-small-attempt4.in","r",stdin);
//	freopen("B-small-attempt4.out","w",stdout);
	scanf("%d",&T);
	for(t=1;t<=T;++t)
	{
		memset(ok1,0,sizeof(ok1));
		memset(ok2,0,sizeof(ok2));
		printf("Case #%d: ",t);
		now=0;
		sum=0;
		count=0;
		scanf("%d",&N);
		for(i=0;i<N;++i)
		{
			scanf("%d%d",&level[i].a,&level[i].b);
			la[i].a=lb[i].a=level[i].a;
         	la[i].b=lb[i].b=level[i].b;
			la[i].order=lb[i].order=i;
		}

		qsort(lb,N,sizeof(LEVEL),cmpb);
		qsort(la,N,sizeof(LEVEL),cmpa);

		while(1)
		{
			if(now==N)
				goto L1;
			OK=0;
			for(i=0;i<N;++i)
			{
				if(!ok2[lb[i].order] && lb[i].b<=sum)
				{
				//	printf("**i=%d: %d\n",lb[i].order,lb[i].b);
					if(ok1[lb[i].order])
						sum++;
					else
						sum+=2;
					ok2[lb[i].order]=1;
					ok1[lb[i].order]=1;
					OK=1;
					++now;
					++count;
					break;
				}
			}
			if(!OK)
			{
				for(i=0;i<N;++i)
				{
					if(!ok1[la[i].order] && la[i].a<=sum)
					{
                 //   printf("**i=%d: %d\n",la[i].order,la[i].a);
						ok1[la[i].order]=1;
						++count;
						sum++;
						OK=1;
						break;
					}
				}
			}
			if(!OK)
			{
			   goto L;
			}
			//printf("sum=%d\n",sum);
		}
L:
        printf("Too Bad\n");
		continue;
L1:
		printf("%d\n",count);

	}
	return 0;
}