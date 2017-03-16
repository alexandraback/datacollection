#include <stdio.h>
#include <malloc.h>
int *arr;
int *choice;
int len;
void main()
{
	char c = 's';
	if(c=='s')
	{
		len = 10;
		arr = (int *)malloc(sizeof(int)*11);
		choice = (int *)malloc(sizeof(int)*11);
	}
	else
	{
		len = 1000;
		arr = (int *)malloc(sizeof(int)*1001);
		choice = (int *)malloc(sizeof(int)*1001);
	}
	int i;
	int cases;
	scanf("%d",&cases);
	int n = 0;
	int max;
	int temp;
	while(n<cases)
	{
		max = -1;
		n++;
		printf("Case #%d: ",n);
		scanf("%d",&len);
		for(i=1;i<=len;i++)
		{
			scanf("%d",&choice[i]);
			arr[i]=0;
		}
		
		for(i=1;i<=len;i++)
		{
			temp = getlength(i,i,1,0,i);
			//printf("for %d got max len as %d\n",i,temp);
			if(temp>max)
				max = temp;
		}
		printf("%d\n",max);
	}
}
int getlength(int first,int now, int len, int ok, int slast)
{
	//printf("in funct with first now len ok as %d %d %d %d\n",first,now,len,ok);
	arr[now]=1;
	//printf("making %d busy\n",now);
	int t1=0,t2=0,t3=0,t4=0,t5=0;
	int i;
	if(arr[choice[now]]==0)
	{
		t1=getlength(first,choice[now],len+1,0,now);
	}
	else
	{
		if(choice[now]==first&&!ok)
		{
			t2=getlength(first,now,len,1,slast);
		}
		if(choice[now]==slast&&!ok)
		{
			t5=getlength(first,now,len,1,slast);
		}
		if(ok)
		{
			for(i=1;i<=len;i++)
			{
				if(arr[i]==0&&choice[i]==now)
				{
					//printf("needed\n");
					t3=getlength(first,i,len+1,1,now);
				}
			}
			//printf("making %d free\n",now);
			arr[now]=0;
		//printf("returning %d\n",len);
		return len;
		}
		
		
	}
	//printf("making %d free\n",now);
	arr[now]=0;
	if(t1>=t2&&t1>=t3&&t1>t5)
	return t1;
	else if(t2>=t1&&t2>=t3&&t2>t5)
	return t2;
	else if(t3>=t2&&t3>=t1&&t3>t5)
	return t3;
	else if(t5>=t2&&t5>=t1&&t5>t3)
	return t5;
}












