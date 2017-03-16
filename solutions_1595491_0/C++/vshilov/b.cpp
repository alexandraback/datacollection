#include <iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int test_case=0;test_case<t;test_case++)
	{
		int n,s,p;
		cin>>n>>s>>p;
		int a[100];
		for(int i=0;i<n;i++)cin>>a[i];
		int res=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]>=3*p-2)
				res++;
			else
				if(a[i]>=3*p-4&&p>1&&s>0)
				{
					res++;
					s--;
				}
		}
		cout<<"Case #"<<test_case+1<<": "<<res<<endl;
	}
	return 0;
}
