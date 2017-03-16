#include<stdio.h>

int T, N, M;
int a[222][222], b[222], c[222];
int d[222];
int perm[222],check[222];
int found;

int have[222], use[222];

void Go(int depth)
{
	if(found) return;

	if(depth==N)
	{
		int l1;

		found = 1;
		for(l1=0;l1<N;l1++) printf(" %d",perm[l1]+1);
		printf("\n");
	}
	else
	{
		int l1, l2;
		for(l1=0;l1<222;l1++)
		{
			have[l1] = d[l1];
			use[l1] = 0;
		}
		while(1)
		{
			int stop = 1;
			for(l1=0;l1<N;l1++)
			{
				if(check[l1]) continue;
				if(have[c[l1]])
				{
					check[l1] = 2;
					stop = 0;
					use[c[l1]]++;
					for(l2=0;l2<b[l1];l2++)
					{
						have[a[l1][l2]]++;
					}
				}
			}
			if(stop)
			{
				for(l1=0;l1<N;l1++)
				{
					if(check[l1] == 0) break;
				}
				if(l1 < N)
				{
					for(l1=0;l1<N;l1++) if(check[l1] == 2) check[l1] = 0;
					return;
				
				}
				for(l1=0;l1<222;l1++) if(have[l1] < use[l1]) break;
				if(l1<222)
				{
					for(l1=0;l1<N;l1++) if(check[l1] == 2) check[l1] = 0;
					return;
				}
				break;
			}
		}
		for(l1=0;l1<N;l1++) if(check[l1] == 2) check[l1] = 0;
		for(l1=0;l1<N;l1++)
		{
			if(check[l1]) continue;
			if(d[c[l1]] <= 0) continue;

			d[c[l1]]--;
			check[l1] = 1;
			perm[depth] = l1;

			for(l2=0;l2<b[l1];l2++)
			{
				d[a[l1][l2]]++;
			}

			Go(depth+1);

			for(l2=0;l2<b[l1];l2++)
			{
				d[a[l1][l2]]--;
			}

			d[c[l1]]++;
			check[l1] = 0;
		}
	}
}

int main(void)
{
	int l0, l1, l2;

	scanf("%d",&T);
	for(l0=1;l0<=T;l0++)
	{
		fprintf(stderr,"working..%d\n",l0);
		for(l1=0;l1<222;l1++)
		{
			for(l2=0;l2<222;l2++)
			{
				a[l1][l2]=0;
			}
			b[l1]=c[l1]=d[l1]=perm[l1]=check[l1]=0;
		}
		scanf("%d %d",&M,&N);
		for(l1=0;l1<M;l1++)
		{
			int temp;

			scanf("%d",&temp);
			d[temp]++;
		}
		for(l1=0;l1<N;l1++)
		{
			scanf("%d",&c[l1]);
			scanf("%d",&b[l1]);
			for(l2=0;l2<b[l1];l2++)
			{
				scanf("%d",&a[l1][l2]);
			}
		}
		found = 0;
		printf("Case #%d:",l0);
		Go(0);
		if(found == 0)
		{
			printf(" IMPOSSIBLE\n");
		}
	}
	return 0;
}
