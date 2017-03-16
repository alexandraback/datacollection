#include<stdio.h>
#include<iostream>
int max=0,banana,total,k,l,s;
char str[10],stack[10],key[10];
void work(int p)
{
	int flag,temp,i,j;
	if(p==s)
	{
		temp=0;
		for(i=0;i<=s-l;i++)
		{
			flag=1;
			for(j=i;j<=i+l-1;j++)
			{
				if(stack[j]!=str[j-i])
				{
					flag=0;
					break;
				}
			}
			if(flag==1)
				temp++;
		}
		if(temp>max)
			max=temp;
		banana+=temp;
		return ;
	}
	for(i=0;i<k;i++)
	{
		stack[p]=key[i];
		work(p+1);
	}
}
int main()
{
	int task,max_task,i; 
	double ans;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	std::cin >> max_task;
	for(task=1;task<=max_task;task++)
	{
		std::cin >> k >> l >> s;
		if(task==100)
			i=1;
		max=0;
		banana=0;
		scanf(" %s",key);
		scanf(" %s",str);
		work(0);
		total=1;
		for(i=1;i<=s;i++)
			total*=k;
		ans=max-banana*1.0/total;

		std::cout << "Case #" << task << ": " ;
		printf("%.7lf\n",ans);
	}
	fclose(stdout);
}
