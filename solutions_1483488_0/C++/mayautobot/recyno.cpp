#include<stdio.h>
#include<math.h>
int main()
{
	long test,A,B,ans,num2,num,num1;
	int arr[10],i,x,t,j,z,temp,sign;
	long stor[10];
	scanf("%ld",&test);
	for(t=0;t<test;t++)
	{
		ans=0;
		scanf("%ld %ld",&A,&B);
		for(num=A;num<=B;num++)
		{
			//printf("\n\n****Number : %ld*****\n\n",num);
			i=0;
			num1=num;
			while(num1>0)
			{
				arr[i]=num1%10;
				num1/=10;
				i++;
			}
			for(j=0;j<(i/2);j++)
			{
				temp=arr[j];
				arr[j]=arr[i-j-1];
				arr[i-j-1]=temp;
			}
			for(z=0;z<10;z++){stor[z]=0;}
			sign=0;
			for(j=0;j<=i-2;j++)
			{
				temp=arr[i-1];
				for(x=i-2;x>=0;x--)
				{
					arr[x+1]=arr[x];
				}
				arr[0]=temp;num2=0;
				for(x=0;x<i;x++)
				{
				  //num2=num2*10+(long)arr[x];
				  num2=num2+(arr[x]*(long)pow(10,(i-1-x)));
				  stor[j]=num2;
				}
				for(z=0;z<j;z++){if(num2==stor[z]){sign=1;}}
				if(num2>=A && num2<=B && num2>num && sign==0)
				{   ++ans;}
			}
		}
		printf("Case #%d: %ld\n",t+1,ans);
	}
	return 0;
}
