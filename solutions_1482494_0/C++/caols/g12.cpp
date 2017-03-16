#include "stdio.h"
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output1.txt","w",stdout);
	int a[1005];
	int b[1005];
	bool level2[1005];
	bool level1[1005];
	int n,m;
	int count,i,j;
	scanf("%d",&n);
	for(count=1;count<=n;count++)
	{
		scanf("%d",&m);
		bool flag=false;
		int max=-1;
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&(a[i]),&(b[i]));
			if(a[i]>max)
			{
				max=a[i];
			}
			if(b[i]>max)
			{
				max=b[i];
			}
			if(a[i]==0||b[i]==0)
			{
				flag=true;
			}

			level2[i]=false;
			level1[i]=false;

		}
		if(max>2*(m-1)+1||flag==false)
		{
			printf("Case #%d: Too Bad\n",count);

		}else
		{
			int index=0;
			int notcom=m;
			int curr=0;
			while(true)
			{
				if(notcom==0)break;
				bool ff=true;
				for(i=0;i<m;i++)
				{
					if(curr>=b[i] && level2[i]==false&&level1[i]==false)
					{
						notcom--;
						level2[i]=true;
						index++;	
						curr+=2;					
						ff=false;
						break;
					//	printf("level2:%d\n",i);
					}
				}
				if(ff==true)
				{
					for(i=0;i<m;i++)
					{
						if(curr>=b[i] && level2[i]==false&&level1[i]==true)
						{
							notcom--;
							level2[i]=true;
							index++;
							curr+=1;
							ff=false;
							break;
						//	printf("level2:%d\n",i);
						}
					}

				}
				if(ff==true)
				{
						for(i=0;i<m;i++)
						{
							if(a[i]<=curr && level1[i]==false && level2[i]==false)
							{
								level1[i]=true;
								index++;
								curr+=1;
							//	printf("level1:%d\n",i);
								ff=false;
								break;
							}
						}
				}
				if(ff==true)
				{
					index=-1;
					break;
				}
			}
			if(index==-1)
				printf("Case #%d: Too Bad\n",count);
	       else printf("Case #%d: %d\n",count,index);
		}
		
	}
	return 0;
}