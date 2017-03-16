#include <stdio.h>
int Base[10][10]=
{
	{ 0, 0, 0, 0, 0},
	{ 0, 1, 2, 3, 4},
	{ 0, 2,-1, 4,-3},
	{ 0, 3,-4,-1, 2},
	{ 0, 4, 3,-2,-1},
};
char x[10010];
int y[200010];
void solve(int);
int main()
{
	freopen("C-small-attempt1.in","r",stdin);
	freopen("output.txt","w",stdout);
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) solve(i);
}
void solve(int T)
{
	int a,i,j,k,s;
	long long int b;
	scanf("%d%lld",&a,&b);
	scanf("%s",x+1);
	for(i=1;i<=a;i++) y[i]=x[i]-'i'+2;
	for(i=a+1;i<=12*a;i++) y[i]=y[(i-1)%a+1];
	s=1;
	for(i=1;i<=a;i++)
	{
		if(s>0)
		{
			s=Base[s][y[i]];
		}
		else
		{
			s=-Base[-s][y[i]];
		}
	}
	if((s==-1&&b%2==1)||(s*s!=1&&b%4==2));
	else
	{
		printf("Case #%d: NO\n",T);
		return;
	}
	s=1;
	for(i=1;i<=4*a;i++)
	{
		if(s>0)
		{
			s=Base[s][y[i]];
		}
		else
		{
			s=-Base[-s][y[i]];
		}
		if(s==2) break;
	}
	if(i>4*a)
	{
		printf("Case #%d: NO\n",T);
		return;
	}
	s=1;
	for(j=i+1;j<=4*a+i;j++)
	{
		if(s>0)
		{
			s=Base[s][y[j]];
		}
		else
		{
			s=-Base[-s][y[j]];
		}
		if(s==3) break;
	}
	if(j>4*a+i)
	{
		printf("Case #%d: NO\n",T);
		return;
	}
	s=1;
	for(k=j+1;k<=4*a+j;k++)
	{
		if(s>0)
		{
			s=Base[s][y[k]];
		}
		else
		{
			s=-Base[-s][y[k]];
		}
		if(s==4) break;
	}
	if(k>4*a+j)
	{
		printf("Case #%d: NO\n",T);
		return;
	}
	if((long long int)k>b*a)
	{
		printf("Case #%d: NO\n",T);
		return;
	}
	printf("Case #%d: YES\n",T);
}
