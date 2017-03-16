#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;
	cin>>t;
	for (int ii=0;ii<t;ii++)
	{
		long long p=0,q=0;
		string s;
		cin>>s;
		char ch=s[0];
		int i=0;
		while (ch!='/')
		{
			p*=10;
			p+=ch-48;
			i++;
			ch=s[i];
		}
		i++;
		ch=s[i];
		while (i<s.length())
		{
			q*=10;
			q+=ch-48;
			i++;
			ch=s[i];
		}
		long long r=q;
		cout<<"Case #"<<ii+1<<": ";
		while (r % 2==0) r/=2;
		if (r!=0 && p % r!=0) cout<<"impossible"<<endl;
		else
		{
			r=1;
			int ans=0;
			while (p*r<q)
			{
				ans++;
				r*=2;
			}
			cout<<ans<<endl;
		}
	}
}