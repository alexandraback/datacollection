#include <bits/stdc++.h>
using namespace std;


int main() 
{
	int t,j=1;
	cin>>t;
	while(t--)
	{
		int k,l,s,r;
		cin>>k>>l>>s;
		vector <char> c(k);
		for(int i=0;i<k;i++)
			cin>>c[i];
		string u;
		cin>>u;
		r=s;
		int nu=1;
		while(r--)
			nu*=k;
		vector <string> v(nu);
		nu/=k;
		for(int i=0;i<s;i++)
		{
			for(int p=0;p<v.size();p++)
			{
				v[p]+=c[(p/nu)%k];
			}
			nu/=k;
		}
		size_t sz=0;
		int y=s-l+1;
		int ma=0,su=0,cur;
		for(int i=0;i<v.size();i++)
		{
			cur=0;
			for(int j=0;j<y;j++)
			{
				sz=v[i].find(u,j);
				if(sz!=string::npos)
				{
					j=sz;
					cur++;
				}
			}
			ma=max(ma,cur);
			su+=cur;
		}
		long double ans=ma*v.size();
		ans-=su;
		ans/=v.size();
		cout<<"Case #"<<j++<<": "<<fixed<<setprecision(8)<<ans<<endl;
	}
	return 0;
}