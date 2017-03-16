#include <cstdio>
#include <cstring>
int a[10000],b[10000];
bool half[10000],done[10000];
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int t,cn,i,n,max,count,star,work;
	bool flag;
	scanf("%d",&t);
	for(cn=1;cn<=t;cn++)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d%d",&a[i],&b[i]);
		star = count = work = 0;
		memset(half,false,sizeof(half));
		memset(done,false,sizeof(done));
		while(count < n)
		{
			flag = true;
			for(i=1;i<=n;i++)
				if(!done[i] && b[i]<=star)
				{
					if(!half[i])
					{
						done[i] = half[i] = true; 
						star += 2;
					}
					else
					{
						done[i] = true;
						star++;	
					}
					work++;	flag = false; count++;
				}	
			if(flag)
			{
				max = -1;
				for(i=1;i<=n;i++)
					if(!half[i] && a[i]<=star)
					{
						if(max == -1 || b[i] > b[max])
							max = i;	
					}
				if(max == -1 && count < n)
				{
					printf("Case #%d: Too Bad\n",cn);
					goto A;
				}	
				half[max] = true;
				star++;
				work++;
			}
		}
		printf("Case #%d: %d\n",cn,work);
		A:
			continue;
	}	
}
