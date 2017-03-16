#include<iostream>
#include<cstdio>
int n,m,k,num;
int f[32][4][2];
using namespace std;

void solve()
{
	memset(f,0,sizeof(f));
	f[31][0][0]=1;

	int x1,x2,x3;
	for (int i=30; i>=0; i--)
	{
		if ((n&(1<<i))==0) x1=0; else x1=1;
		if ((m&(1<<i))==0) x2=0; else x2=1;
		if ((k&(1<<i))==0) x3=0; else x3=1;
		


		if ((x1&x2)==x3) f[i][0][0]+=f[i+1][0][0];
		if ((x1&x2)<x3) f[i][0][1]+=f[i+1][0][0];
		if (x1==1)
		{
			if (x3==0) f[i][2][0]+=f[i+1][0][0]; else f[i][2][1]+=f[i+1][0][0];
		}
		if (x2==1)
		{
			if (x3==0) f[i][1][0]+=f[i+1][0][0]; else f[i][1][1]+=f[i+1][0][0];
		}
		
		if ((x1==1) && (x2==1))
		{
			if (x3==0) f[i][3][0]+=f[i+1][0][0]; else f[i][3][1]+=f[i+1][0][0];
		}


		f[i][0][1]+=f[i+1][0][1];
		if (x1==1) f[i][2][1]+=f[i+1][0][1];
		if (x2==1) f[i][1][1]+=f[i+1][0][1];
		if ((x1==1) && (x2==1)) f[i][3][1]+=f[i+1][0][1];
		

		if ((x1&1)==x3) f[i][1][0]+=f[i+1][1][0];
		if ((x1&1)<x3) f[i][1][1]+=f[i+1][1][0];
		if ((x1&0)==x3) f[i][1][0]+=f[i+1][1][0];
		if ((x1&0)<x3) f[i][1][1]+=f[i+1][1][0];
		if (x1==1)
		{
			if (x3==0) f[i][3][0]+=2*f[i+1][1][0]; else f[i][3][1]+=2*f[i+1][1][0];
		}


		f[i][1][1]+=2*f[i+1][1][1];
		if (x1==1)
		{
			f[i][3][1]+=2*f[i][1][1];		
		}

		
		if ((x2&1)==x3) f[i][2][0]+=f[i+1][2][0];
		if ((x2&1)<x3) f[i][2][1]+=f[i+1][2][0];
		if ((x2&0)==x3) f[i][2][0]+=f[i+1][2][0];
		if ((x2&0)<x3) f[i][2][1]+=f[i+1][2][0];
		if (x2==1)
		{
			if (x3==0) f[i][3][0]+=2*f[i+1][2][0]; else f[i][3][1]+=2*f[i+1][2][0];
		}

		f[i][2][1]+=2*f[i+1][2][1];
		if (x2==1)
		{
			f[i][3][1]+=2*f[i][2][1];
		}

	}

	int ans=0;
	for (int i=0; i<4; i++)
		for (int j=0; j<2; j++) ans+=f[0][i][j];

	printf("Case #%d: \n",ans);

}
void init()
{
	scanf("%d",&num);
	while (num--)
	{
		scanf("%d%d%d",&n,&m,&k);
		--n; --m; --k;
		solve();
	}
}
int main()
{
	init();
	return 0;
}
