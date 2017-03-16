#include <stdio.h>

int main(void)
{
	int temp,t,i,j,num,k=1,sw=1;
	int a[10]={0};
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		k=1;
		a[0]=0,a[1]=0,a[2]=0,a[3]=0,a[4]=0,a[5]=0,a[6]=0,a[7]=0,a[8]=0,a[9]=0;
		scanf("%d",&num);
		if(num!=0)
		{
		temp=num;
		a[num%10]=1;
		while(num/10!=0)
		{
			num=num/10;
			if(a[num%10]<1)
				a[num%10]=1;
		}
		num=temp;
		while(1)
		{
			sw=1;
			num=num*(k+1)/k;
			k++;
			if(a[num%10]<1)
				a[num%10]=1;
			temp=num;
			while(num/10!=0)
			{
				num=num/10;
				if(a[num%10]<1)
					a[num%10]=1;
			}
			num=temp;
			for(j=0;j<10;j++)
				if(a[j]==0)
					sw=0;
			if(sw==1)
				break;
		}
		printf("Case #%d: %d\n",i+1,num);
		}
		else
			printf("Case #%d: INSOMNIA\n",i+1);
	}
	return 0;
}