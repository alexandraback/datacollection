#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	long long tc,t,e,r,n,i,j,k,p,rr;
	scanf("%lld\n",&t);
	for (tc=0;tc<t;++tc)
	{
		rr=0;
		set<int> x;
		vector<pair<int,int> > y;
		scanf("%lld %lld %lld",&e,&r,&n);
		for (i=0;i<n;++i) { scanf("%lld",&p); y.push_back(make_pair(-p,i)); }
		sort(y.begin(),y.end());
		for (size_t ii=0;ii<y.size();++ii)
		{
			set<int>::iterator it=x.upper_bound(y[ii].second);
				long long d=0;
				if (it!=x.end())
				{
					d=e-r*(*it-y[ii].second);
				}
				if (d<0) d=0;
				long long h=e;
				if (it!=x.begin())
				{
					--it;
					h=r*(y[ii].second-(*it));
					if (h>e) h=e;
				}
				if (h>d) rr-=(h-d)*(long long)y[ii].first;
			x.insert(y[ii].second);
		}
		printf("Case #%lld: %lld\n",tc+1,rr);
	}
	return 0;
}
