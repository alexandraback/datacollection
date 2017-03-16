#include<stdio.h>

int T;
int a[11111], b[11111];
int earn[11111];
int ret;
int tot;
int n;

int main(void)
{
	int l0, l1, l2;
	freopen("b2.in","r",stdin);
	freopen("b2.out","w",stdout);
	scanf("%d",&T);
	for(l0=1;l0<=T;l0++)
	{
		scanf("%d",&n);
		for(l1=0;l1<n;l1++)
		{
			scanf("%d %d",&a[l1],&b[l1]);
			earn[l1] = 0;
		}

		ret = 0;
		tot = 0;
		while(1)
		{
			int l1;

			for(l1=0;l1<n;l1++)
			{
				if(earn[l1] == 0 || earn[l1] == 1) break;
			}
			if(l1 == n)
			{
				printf("Case #%d: %d\n",l0,ret);
				break;
			}

			int flag = 0;
			for(l1=0;l1<n;l1++)
			{
				if(earn[l1] < 2 && tot >= b[l1])
				{
					tot += 2 - earn[l1];
					earn[l1] = 2;
					flag = 1;
					ret++;
				}
			}

			if(flag == 0)
			{
				int idx = -1;
				for(l1=0;l1<n;l1++)
				{
					if(earn[l1] == 0 && tot >= a[l1])
					{
						if(idx == -1 || b[l1] > b[idx])
						{
							idx = l1;
						}
					}
				}
				if(idx == -1)
				{
					printf("Case #%d: Too Bad\n",l0);
					break;
				}
				tot++;
				earn[idx] = 1;
				ret++;
			}
		}
	}
}