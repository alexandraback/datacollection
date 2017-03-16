#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long LINT;



struct Attack
{
	int n,w,e,s;
};
bool operator< (const Attack& a1, const Attack& a2)
{
	return a1.n<a2.n;
}

void main()
{
	int t;
	cin>>t;
	for(int ii=0; ii<t; ii++)
	{
		vector<pair<int,Attack> > v;
		int nn;
		cin>>nn;
		for(int i=0; i<nn; i++)
		{
			int d,n,w,e,s,dd,dp,ds;
			cin>>d>>n>>w>>e>>s>>dd>>dp>>ds;
			for(int j=0; j<n; j++)
			{
				int cd=d+dd*j;
				Attack at;
				at.n=n;
				at.w=w+dp*j;
				at.e=e+dp*j;
				at.s=s+ds*j;
				v.push_back(make_pair(cd,at));
			}
		}
		sort(v.begin(),v.end());
		int height[10000]={0,};
		int cnt=0;

		for(int i=0; i<v.size(); i++)
		{
			Attack at=v[i].second;
			int w=at.w*2+5000;
			int e=at.e*2+5000;

			int j;
//			cout<<endl<<v[i].first<<endl;
			for(j=w; j<=e; j++)
			{
//				cout<<' '<<(j-5000)/2.0<<":"<<height[j]<<','<<at.s<<' ';
				if(height[j]<at.s)
				{
					break;
				}
			}
			if(j<=e)
				cnt++;

			if(i+1<v.size() && v[i+1].first!=v[i].first)
			{
				for(int k=i; k>=0; k--)
				{
					if(v[k].first!=v[i].first)
						break;

					Attack at=v[k].second;
					int w=at.w*2+5000;
					int e=at.e*2+5000;

					int j;
					for(j=w; j<=e; j++)
						height[j]=max(at.s,height[j]);
				}
			}
		}

				
		cout<<"Case #"<<ii+1<<": "<<cnt<<endl;
	}
}