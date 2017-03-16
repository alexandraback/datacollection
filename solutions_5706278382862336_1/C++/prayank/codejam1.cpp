#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,count=1;
	scanf("%d",&t);
	while(t--)
	{
		long long int p=0,q=0;
		int i=0,f=0,temp=0;
		int *cnt=(int *)calloc(40,sizeof(int));
		char a[100];
		scanf("%s",a);
		while(a[i]!='/')
		{
			p=10*p+a[i]-48;
			i++;
		}
		i++;
		while(a[i]!='\0')
		{
			q=10*q+a[i]-48;
			i++;
		}
	
		

		for(i=0;i<40;i++)
		{
			p=p*2;
			cnt[temp]++;
			if(p>=q)
			{
				temp++;
				p=p-q;	
			}
		}
		if(p==0 || p==q)
			printf("Case #%d: %d\n",count++,cnt[0]);
		else
			printf("Case #%d: impossible\n",count++);
	}
	return 0;
}