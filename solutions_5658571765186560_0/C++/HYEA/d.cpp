#include<cstdio>
bool tmain(int X,int R,int C)
{
	if(X>=7) return false;
	if(X==1) return true;
	if(X==2) return ((R*C)%2==0);
	if(X==3)
	{
		if(R==1 || C==1) return false;
		return ((R*C)%3==0);
	}
	if(X==4)
	{
		if(R<=2 || C<=2) return false;
		return ((R*C)%4==0);
	}
	if(X==5)
	{
		if(R<=2 || C<=2) return false;
		if(R*C==15) return false;
		return ((R*C)%5==0);
	}
	if(X==6)
	{
		if(R<=4 || C<=4) return false;
		return ((R*C)%6==0);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int X,R,C;
		scanf("%d%d%d",&X,&R,&C);
		printf("Case #%d: ",i);
		if(tmain(X,R,C))
			puts("GABRIEL");
		else
			puts("RICHARD");
	}
	return 0;
}