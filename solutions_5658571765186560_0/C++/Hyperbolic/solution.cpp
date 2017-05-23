#include <stdio.h>
void solve(int);
int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) solve(i);
}
void solve(int T)
{
	int a,b,c,d,e,i;
	scanf("%d%d%d",&a,&b,&c);
	if(a>=7||((b*c)%a!=0))
	{
		printf("Case #%d: RICHARD\n",T);
		return;
	}
	for(i=1;i<=a;i++)
	{
		d=i,e=a+1-i;
		if(((d<=b)&&(e<=c))||((d<=c)&&(e<=b)));
		else
		{
			printf("Case #%d: RICHARD\n",T);
			return;
		}
	}
	if(a==6)
	{
		if(b==3||c==3)
		{
			printf("Case #%d: RICHARD\n",T);
			return;
		}
	}
	if(a==4)
	{
		if(b==2||c==2)
		{
			printf("Case #%d: RICHARD\n",T);
			return;
		}
	}
	printf("Case #%d: GABRIEL\n",T);
}
