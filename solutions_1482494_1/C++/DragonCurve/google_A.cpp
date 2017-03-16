#include <stdio.h>
#include <algorithm>
int chk_a[1005],chk_b[1005],star,flag,cnt;
int val_a[1005];
struct data
{
	int val;
	int index;
}a[1005],b[1005];
bool cmp(data p,data q)
{
	return p.val < q.val;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t1,t,n,i,j,tmp_a,tmp_b;
	scanf("%d",&t);
	int max,max_index;
	for(t1=1;t1<=t;t1++)
	{
		star = 0;
		cnt = 0;
		tmp_a=0;
		tmp_b=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&b[i].val,&a[i].val);
			val_a[i] = a[i].val;
			a[i].index = i;
			b[i].index = i;
		}
		std::sort(a,a+n,cmp);
		std::sort(b,b+n,cmp);

		while(star != 2*n)
		{
			flag = 0;
			for(i=tmp_a;i<n;i++)
			{
				if(a[i].val <= star)
				{
					if(chk_a[a[i].index] == 0)
					{
						chk_a[a[i].index] = 1;
						flag = 1;
						cnt++;
						if(chk_b[a[i].index] == 0)
							star+=2;
						else
							star++;
						chk_b[a[i].index] = 1;
					}
				}
				else
					break;
			}
			tmp_a = i;
			max = -1;
			for(i=0;i<n;i++)
			{
				if(chk_b[b[i].index] == 0 && max<val_a[b[i].index] && b[i].val <= star)
				{
					max = val_a[b[i].index];
					max_index = b[i].index;
				}
			}
			if(max>=0)
			{
				flag = 1;
				cnt++;
				star++;
				chk_b[max_index] = 1;
			}
			if(flag == 0)
				break;
		}

		if(flag == 0)
			printf("Case #%d: Too Bad\n",t1);
		else
			printf("Case #%d: %d\n",t1,cnt);

		for(i=0;i<n;i++)
		{
			chk_a[i] = 0;
			chk_b[i] = 0;
		}
	}
	return 0;
}