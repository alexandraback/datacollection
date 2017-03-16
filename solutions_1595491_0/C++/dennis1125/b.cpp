#include <stdio.h>

int casen;
int n,s,p;
int ret;
int a[111];

void solve()
{
	int able = 0;
	int possible = 0;
	
	for(int i=0;i<n;i++) 
	{
		//printf("a[i]=%d\n",a[i]);
		int data = a[i]/3;
		int left = a[i]%3;
		if(0 == left)
		{
			if(data >= p)
			{
				able++;
			}
			else if (data+1 == p && data>0)
			{
				possible++;
			}
		}
		else if(1 == left)
		{
			if(data+1 >= p)
			{
				able++;
			}
		}
		else if(2 == left)
		{
			if(data >= p-1)
			{
				able++;
			}
			else if (data+2 == p)
			{
				possible++;
			}
		}
	}
	//printf("able=%d possible=%d s=%d\n",able,possible,p);
	
	ret = able;
	if(possible > s) ret+=s;
	else ret+=possible;
}

int main()
{
	scanf("%d",&casen);
	
	for(int i=1;i<=casen;i++)
	{
		scanf("%d%d%d",&n,&s,&p);
		for(int j=0;j<n;j++)
			scanf("%d",&a[j]);
		solve();
		printf("Case #%d: %d\n",i,ret);	
	}
	
	return 0;
}
