#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for (int i = 0; i < T; ++i)
	{
		int a,b;
		scanf("%d/%d",&a,&b);
		//cout<<a<<" "<<b<<endl;
		int cn=1;
		int flag=0;
		while(cn<=b)
		{
			if(cn==b)
				flag=1;
			cn=cn*2;
		}
		if(flag==0)
		{
			printf("Case #%d: impossible\n", i+1);
			continue;
		}
		double val=a/(double)b;
		//cout<<"val "<<val<<endl;
		double ct=1;
		int count=0;
		while(count<40)
		{
			count++;
			ct=ct/2;
			if(val>=ct)
			{
				printf("Case #%d: %d\n", i+1,count);
				break;
			}

		}
	}
}