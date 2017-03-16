#include<stdio.h>
#include<stdlib.h>

struct c_t
{
	int val,idx;
	double part;
};
struct c_t contestants[300];
int sum;

int comp(const void *in1, const void *in2)
{
	struct c_t *c1=(struct c_t*)in1;
	struct c_t *c2=(struct c_t*)in2;
	return c1->val-c2->val;
}
int uncomp(const void *in1, const void *in2)
{
	struct c_t *c1=(struct c_t*)in1;
	struct c_t *c2=(struct c_t*)in2;
	return c1->idx-c2->idx;
}

int main()
{
	int t,tcase;
	int n,tsum,ttsum;
	int i,j;
	double start;

	scanf("%d",&t);
	for (tcase=1;tcase<=t;tcase++)
	{
		sum=0;
		scanf("%d",&n);
		for (i=0;i<n;i++)
		{
			scanf("%d",&contestants[i].val);
			contestants[i].idx=i;
			contestants[i].part=-1.0;
			sum+=contestants[i].val;
		}
		qsort(contestants,n,sizeof(struct c_t),comp);
		contestants[n].val=500000;

		for (tsum=i=0; i<n; tsum+=contestants[i++].val)
		{
			start=(double)(i*contestants[i].val-tsum)/(double)sum;
			//printf("---%.6f\n",start);
			if (start>=1.0)
			{
				contestants[i].part=0.0;
				continue;
			}
			ttsum=tsum+contestants[i].val;
			for (j=i+1; j<=n; ttsum+=contestants[j++].val)
			{
				start=(double)(j*contestants[j].val-ttsum)/(double)sum;
				//printf("j:%d,i:%d, start:%.6f, ttsum:%d\n",j,i,start,ttsum);
				if (start<1.0) { continue; }
				contestants[i].part=((double)(ttsum+sum)/(double)j-(double)contestants[i].val)/(double)sum;
				//printf("%d --> %.6f\n",i,contestants[i].part);
				break;
			}
		}

		qsort(contestants,n,sizeof(struct c_t),uncomp);
		printf("Case #%d:",tcase);
		for (i=0;i<n;i++) { printf(" %.6f",contestants[i].part*100); }
		printf("\n");
	}

	return 0;
}

