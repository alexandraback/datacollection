#include <iostream>
#include <cstdio>
using namespace std;

bool check(int a,int b,int c,int p)
{
	if(a==b&&a==c)
		if(b&&c+1==p)
			return true;
	if(b==c)
		if(b&&c+1==p)
			return true;
	return false;
}

int main()
{
	int T;
	//freopen("b.in","r",stdin);
	//freopen("b.res","w+",stdout);
	cin>>T;
	for(int tt=1;tt<=T;tt++)
	{
		int N,S,p,t;
		cin>>N>>S>>p;
		int cnt=0;
		for(int i=0;i<N;i++)
		{
			cin>>t;
			int a,b,c;
			a=b=c=t/3;
			if(t%3==2)
			{
				b++;c++;
			}
			else if(t%3==1)
				c++;
			if(c>=p)
			{
				cnt++;
				continue;
			}
			else if(S)
			{
				if(check(a,b,c,p))
				{
					S--;
					cnt++;
				}
			}
		}
		cout<<"Case #"<<tt<<": "<<cnt<<endl;
	}
	return 0;
}
