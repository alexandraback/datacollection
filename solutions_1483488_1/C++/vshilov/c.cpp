#include <iostream>
#include <set>

using namespace std;

int len(int x)
{
	int res=0;
	while(x)
	{
		x/=10;
		res++;
	}
	return res;
}


int main()
{
	int t;
	cin>>t;
	for(int test_case=0;test_case<t;test_case++)
	{
		int a,b;
		cin>>a>>b;
		int res=0;
		for(int i=a;i<=b;i++)
		{
			set<int> s;
			s.insert(i);
			int cur=i;
			int l=len(i);
			int x=1;
			for(int j=0;j<l-1;j++)x*=10;
			for(int j=0;j<l-1;j++)
			{
				int y=cur%10;
				cur/=10;
				cur+=y*x;
				if(y!=0)
				{
					if(cur>=a&&cur<=b&&s.find(cur)==s.end())
					{
						res++;
						s.insert(cur);
					}
				}
			}
		}
		cout<<"Case #"<<test_case+1<<": "<<res/2<<endl;
	}
	return 0;
}
