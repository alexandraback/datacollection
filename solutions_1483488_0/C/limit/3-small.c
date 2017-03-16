#include<stdio.h>

int nos[20];
int found=0,ans=0,a,b;

int power(int b,int a)
{
   if(a==1)
	   return b;
   if(a==2)
   	   return b*b;
   if(a==3)
   	   return b*b*b;
   if(a==4)
   		return b*b*b*b;
   if(a==5)
   		return b*b*b*b*b;
   if(a==6)
   		return b*b*b*b*b*b;
   if(a==7)
   		return b*b*b*b*b*b*b;
   if(a==8)
   		return b*b*b*b*b*b*b*b;
   return 1;
}

void find_all(int num)
{
	int start=0,first=num,pow=-1,temp,number=num,i,start_pow=1;
	while(first>0)
	{
		pow++;
		first/=10;
	}
	start+=num%10;
	num/=10;
	while(num>0)
	{
		temp=start*power(10,pow)+num;
		if(temp<=b&&temp>number)
		{
			for(i=0;i<found;i++)
			{
				if(nos[i]==temp)
				 break;
			}
			if(i==found)
			{
				nos[found++]=temp;
			}
		}
		start+=num%10*power(10,start_pow);
		num/=10;
		start_pow++;
		pow--;
	}
	ans+=found;
	return;
}

int main()
{
	int test,i,j;
	scanf("%d",&test);
	for(i=1;i<=test;i++)
	{
		ans=0;
		scanf("%d %d",&a,&b);
		for(j=a;j<b;j++)
		{
			found=0;
			find_all(j);
		}
		printf("Case #%d: %d\n",i,ans);
	}
}
