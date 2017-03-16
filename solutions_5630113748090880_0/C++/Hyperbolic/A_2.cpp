#include <stdio.h>
#include <algorithm>
void solve(int);
int main()
{
	freopen("inputS2_1.in","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++) solve(i);
}
int x[210][210];
int y[210],z[210][3];
void solve(int T)
{
	int a,i,j,w=-1,s,t;
	scanf("%d",&a);
	for(i=1;i<=2*a-1;i++)
	{
		for(j=1;j<=a;j++)
		{
			scanf("%d",&x[i][j]);
		}
	}
	for(int i=1;i<=a;i++)
	{
		//a,a determine
		for(int j=1;j<=2*a-1;j++)
		{
			y[j] = x[j][i];
		}
		std::sort(y+1,y+2*a);
		if(w==-1)
		{
			s = y[2*i-1];
			t = y[2*i];
		}
		else
		{
			s = y[2*i-2];
			t = y[2*i-1];
		}
		if(s!=t) w = i;
		int count = 1;
		for(int j=1;j<=2*a-1;j++)
		{
			if(x[j][i]==s)
			{
				z[i][count] = j;
				count++;
			}
		}
	}
	printf("Case #%d: ",T);
	for(int i=1;i<=a;i++)
	{
		if(i==w) printf("%d ",x[z[w][1]][w]);
		else printf("%d ",x[z[i][1]][w]+x[z[i][2]][w]-x[z[w][1]][i]);
	}
	printf("\n");
}
