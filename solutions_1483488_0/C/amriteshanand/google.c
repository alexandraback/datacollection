#include<stdio.h>
#include<math.h>
int cald(int i)
{
	int d=0;
	while(1)
	{
		if(i==0)
			return d;
		i/=10;
		d++;
	}
}
int main()
{
	int array[1000][4]={0};
	int t,sa,sb;
	int i,dig,j,a,p,k,ans,bc,basa;
	for(i=0;i<=1000;i++)
	{
		dig=cald(i);bc=0;
		p=pow(10,dig-1);
		for(k=i,j=1;j<dig;j++)
		{
			k=(k%p)*10+k/p;
			if(k>i)
			{ array[i][bc]=k;bc++;}
		}
	}
	scanf("%d",&t);
	basa=1;
	while(basa<=t)
	{
		scanf("%d%d",&sa,&sb);
		ans=0;
		for(i=sa;i<sb;i++)
		{
			if(array[i][0]<=sb&&array[i][0]>i){ans++;}
			if(array[i][1]<=sb&&array[i][1]>i){ans++;}
			if(array[i][2]<=sb&&array[i][2]>i){ans++;}
		}
		printf("Case #%d: %d\n",basa,ans);
		basa++;
	}
	return 0;
}
