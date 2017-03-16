#include<stdio.h>
#include<math.h>
int array[2000001][9];
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
	int t,sa,sb;
	int i,dig,j,a,p,k,ans,bc,basa,km,ms;
	for(i=0;i<=2000000;i++)
	{
		dig=cald(i);bc=0;
		p=pow(10,dig-1);
		for(k=i,j=1;j<dig;j++)
		{
			k=(k%p)*10+k/p;
			ms=0;
			if(k>i)
			{     for(km=0;km<bc;km++){if(array[i][km]==k){ms=1;continue;}}
			      if(ms==0)array[i][bc]=k;bc++;
                         }
		}
		//printf("%d-%d %d %d %d %d %d %d %d\n",i-4,array[i-4][0],array[i-4][1],array[i-4][2],array[i-4][3],array[i-4][4],array[i-4][5],array[i-4][6],array[i-4][7]);
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
			if(array[i][3]<=sb&&array[i][3]>i){ans++;}
			if(array[i][4]<=sb&&array[i][4]>i){ans++;}
			if(array[i][5]<=sb&&array[i][5]>i){ans++;}
			if(array[i][6]<=sb&&array[i][6]>i){ans++;}
			if(array[i][7]<=sb&&array[i][7]>i){ans++;}
		}
		printf("Case #%d: %d\n",basa,ans);
		basa++;
	}
	return 0;
}
