#include<iostream>
#include<stdio.h>
int main()
{
	int n,m,w,ans,task,max_task;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	std::cin >> max_task;
	for(task=1;task<=max_task;task++)
	{
		std::cin >> n >> m >> w;
		ans=(n-1)*(m/w);
		ans+=m/w;
		m%=w;
		if(m==0)
		{
			ans+=w-1;
		}
		else
		{
			ans+=w;
		}
		std::cout << "Case #" << task << ": " << ans << std::endl; 
	}
	fclose(stdout);
}
