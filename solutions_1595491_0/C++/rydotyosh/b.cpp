
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int s,p;
vector<int> totals;

void load()
{
	int t;
	cin>>t>>s>>p;
	totals.resize(t);
	for(int i=0;i<t;++i)
	{
		cin>>totals[i];
	}
}

int dbg()
{
	cout<<"s "<<s<<endl;
	cout<<"p "<<p<<endl;
	cout<<"totals"<<endl;
	for(int i=0;i<totals.size();++i)
	{
		cout<<totals[i]<<endl;
	}
}

int solve()
{
	load();

	sort(totals.begin(),totals.end(),greater<int>());

	int cnt=0;
	int remainsurp = s;
	for(int i=0;i<totals.size();++i)
	{
		int tt=totals[i];
		int least=tt/3;
		int rem=tt%3;

		// not surp best assum
		int ns=least+((rem>0)?1:0);
		if(ns>=p)
		{
			++cnt;
			continue;
		}

		if(!remainsurp)
			break;

		if(tt<=1)
			break;

		// surp best assum
		int surp=least+((rem>1)?2:1);
		if(surp>=p)
		{
			++cnt;
			--remainsurp;
		}
	}
	return cnt;
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cout<<"Case #"<<i+1<<": "<<solve()<<endl;
	}
	return 0;
}
