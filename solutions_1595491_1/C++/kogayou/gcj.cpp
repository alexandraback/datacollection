#include <iostream>
#include <cstdio>
using namespace std;
int n,s,p,t1,t2,s1,s2,x;
int main()
{
	freopen("gcj.out","w",stdout);
	int T;
	cin>>T;
	for (int casenum=1;casenum<=T;casenum++)
	{
		cout<<"Case #"<<casenum<<": ";
		cin>>n>>s>>p;
		s1=s2=0;
		for (int i=1;i<=n;i++)
		{
			cin>>x;
			if (x%3==0)
			{
				t1=x/3;
				if (x>0) t2=x/3+1;
				else t2=0;
			}
			if (x%3==1)
			{
				t1=t2=x/3+1;
			}
			if (x%3==2)
			{
				t1=x/3+1;
				t2=x/3+2;
			}
			if (t1>=p) s1++;
			else if (t2>=p) s2++;
		}
		cout<<s1+min(s2,s)<<endl;
	}
}
