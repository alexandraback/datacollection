 //FUCK

#include<stdio.h>

int zu[64][8];
int prob[64];
int setp[7];

void init()
{
	for(int i=0;i<64;i++)
	{
		for(int j=0;j<8;j++)
		{
			int ans=1;
			for(int k=0;k<3;k++)
			{
				if(j&(1<<k))
				{
					ans*=(((i>>(2*k))&3)+2);
				}
			}
			zu[i][j]=ans;
		}
	}
}

int getmax()
{
	int ret=0;
	for(int i=0;i<64;i++)
	{
		if(prob[i]>prob[ret])
		{
			ret=i;
		}
	}
	return ret;
}

void solve()
{
	for(int i=0;i<64;i++)
	{
		prob[i]=1;
		for(int j=0;j<7;j++)
		{
			int count=0;
			for(int k=0;k<8;k++)
			{
				if(zu[i][k]==setp[j])
				{
					count++;
				}
			}
			prob[i]=prob[i]*count;
		}
	}
	int ans=getmax();
	printf("%d%d%d\n",((ans>>4)&3)+2,((ans>>2)&3)+2,((ans)&3)+2);
}


int main()
{
	init();
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);


	int t,r,n,m,k;
	scanf("%d",&t);
	scanf("%d %d %d %d",&r,&n,&m,&k);
	printf("Case #1:\n");


	for(int i=0;i<r;i++)
	{
		for(int j=0;j<k;j++)
		{
			scanf("%d",&setp[j]);
		}
		solve();
	}
}
