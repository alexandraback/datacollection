#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int n,i,j,ans,min[100],t,T,a,size[100],add;
	cin>>T;
	for(t=1;t<=T;t++)
	{
		cin>>a>>n;
		for(i=0;i<n;i++)
			cin>>size[i];
		sort(size,size+n);
		if(a==1)
			ans=n;
		else
		{
			int k;
			add=0;
			ans=n;
			for(i=0;i<n;i++)
			{
				while(a<=size[i])
				{
					add++;
					a=a+a-1;
				}
				min[i]=add+n-i-1;
				if(min[i]<ans)
					ans=min[i];
				a=a+size[i];
				//printf("add=%d ans=%d\n",add,ans);
			}
		}
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
