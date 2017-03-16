#include<cstdio>
void termin(){int a[10];for(int i=0;;i--)a[i]=100;}
int T,X,R,C;
int min(int a,int b){return a<b?a:b;}
bool canmod(int m1,int n1,int m2,int n2)
{
//	printf("\t%d %d %d %d\n",m1,n1,m2,n2);
	for(int i=0;i<=n2;i++)
	{
		bool found=false;
		for(int j=0;j<=n1;j++)
		{
			if((m1*j+m2*i)%X==0)found=true;
		}
		if(!found)return false;
	}
	return true;
}
bool solve()
{
	if((R*C)%X!=0)return false;
	if(X>=7)return false;
	if(X<=2)return true;
	if(X>R&&X>C)return false;
	if((X+1)/2>min(R,C))return false;
	if((X+1)/2==min(R,C))
	{
		int x=(X+1)/2;
		if(R>C)
		{
			return canmod(C,R-(X+2)/2,C-1,(X+2)/2-1);
		}
		else return canmod(R,C-(X+2)/2,R-1,(X+2)/2-1);
	}
//	if(X%2==0&&X/2==min(R,C))
//	{
//		//X !| min(R,C)*N+(min(R,C)-1)*M
//		else return canmod();
//	}
	if(X>=R+C-1)return false;
	if(X<R+C-1)return true;
	termin();
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout); 
	scanf("%d",&T);
	int kase=1;
	while(T--)
	{
		scanf("%d%d%d",&X,&R,&C);
//		printf("%d %d %d\n",X,R,C);
		printf("Case #%d: ",kase++);
		if(solve())printf("GABRIEL\n");
		else printf("RICHARD\n");
	}
	return 0;
}
