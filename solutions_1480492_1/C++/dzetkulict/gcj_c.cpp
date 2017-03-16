#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

class comparer
{
public:
	bool operator ()(const pair<pair<long long,long long>, pair<int,int> > & a, const pair<pair<long long,long long>, pair<int,int> > & b)
	{
		if (a.first.first*b.first.second==a.first.second*b.first.first) return a.second.first>a.second.second;
		return a.first.first*b.first.second<a.first.second*b.first.first;
	}
};

int main()
{
	long long s[50],p[50];
	long long sp1[50][50],ep1[50][50],sp2[50][50],ep2[50][50];
	char c[50],st[10000];
	int _cn,_cc,i,j,k,m,n,li[50],lbc,pa[50],k3[50][50];
	gets(st);
	sscanf(st,"%d",&_cn);
	for (_cc=1;_cc<=_cn;++_cc)
	{
		gets(st);
		sscanf(st,"%d",&n);
		for (i=0;i<n;++i)
		{
			gets(st);
			sscanf(st,"%c %lld %lld",c+i,s+i,p+i);
		}
		for (i=0;i<n;++i) for (j=0;j<n;++j) if (i!=j && s[i]>=s[j])
		{
			if (p[i]>=p[j]+5)
			{
				sp1[i][j]=sp1[j][i]=-2;
			} else
			{
				if (s[i]==s[j])
				{
					if (p[i]>p[j]-5)
					{
						sp1[i][j]=sp1[j][i]=-1;
						sp2[i][j]=sp2[j][i]=1;
						ep1[i][j]=ep2[j][i]=1000000000000LL;
						ep2[i][j]=ep2[j][i]=1;
					} else
					{
						sp1[i][j]=sp1[j][i]=-2;
					}
				} else
				{
					if (p[i]>p[j]-5)
					{
						sp1[i][j]=sp1[j][i]=-1;
						sp2[i][j]=sp2[j][i]=1;
					} else
					{
						sp1[i][j]=sp1[j][i]=p[j]-5-p[i];
						sp2[i][j]=sp2[j][i]=s[i]-s[j];
					}
					ep1[i][j]=ep1[j][i]=p[j]+5-p[i];
					ep2[i][j]=ep2[j][i]=s[i]-s[j];
				}
			}
		}
		
		vector<pair<pair<long long,long long>, pair<int,int> > > r;
		
		for (i=0;i<n;++i) for (j=i+1;j<n;++j)
		{
			if (sp1[i][j]!=-2)
			{
				r.push_back(make_pair(make_pair(sp1[i][j],sp2[i][j]),make_pair(i,j)));
				r.push_back(make_pair(make_pair(ep1[i][j],ep2[i][j]),make_pair(j,i)));
			}
		}
		
		comparer x;
		sort(r.begin(),r.end(),x);
		
		for (i=0;i<n;++i)
		{
			pa[i]=0;
			for (j=0;j<n;++j) k3[i][j]=0;
		}
		lbc=2;
		
		for (i=0;i<r.size() && r[i].first.first==-1;++i)
		{
			pa[r[i].second.first]++;
			pa[r[i].second.second]++;
			if (c[r[i].second.first]=='L') li[r[i].second.first]=1; else li[r[i].second.first]=-1;
			if (c[r[i].second.second]=='L') li[r[i].second.second]=1; else li[r[i].second.second]=-1;
			k3[r[i].second.first][r[i].second.second]=k3[r[i].second.second][r[i].second.first]=1;
		}
		
		for (;i<r.size();++i)
		{
			if (r[i].second.first>r[i].second.second)
			{ // end
				pa[r[i].second.first]--;
				pa[r[i].second.second]--;
				k3[r[i].second.first][r[i].second.second]=k3[r[i].second.second][r[i].second.first]=0;
			} else
			{
				k3[r[i].second.first][r[i].second.second]=k3[r[i].second.second][r[i].second.first]=1;
				for (j=0;j<n;++j)
				{
					if (k3[j][r[i].second.first]==1 && k3[j][r[i].second.second]) break;
				}
				if (j<n) break;
				if (pa[r[i].second.first]==0 && pa[r[i].second.second]==0)
				{
					li[r[i].second.first]=lbc;
					li[r[i].second.second]=-lbc;
				} else
				{
					if (pa[r[i].second.first]==0)
					{
						li[r[i].second.first]=-li[r[i].second.second];
					} else
					{
						if (pa[r[i].second.second]==0)
						{
							li[r[i].second.second]=-li[r[i].second.first];
						} else
						{
							if (li[r[i].second.second]==li[r[i].second.first]) break;
							if (li[r[i].second.second]!=-li[r[i].second.first])
							{
								k=li[r[i].second.second];
								m=li[r[i].second.first];
								for (j=0;j<n;++j)
								{
									if (li[j]==k) li[j]=m;
									if (li[j]==-k) li[j]=-m;
								}
							}
						}
					}
				}
				pa[r[i].second.first]++;
				pa[r[i].second.second]++;
			}
		}
		
		printf("Case #%d: ",_cc);
		if (i==r.size())
		{
			printf("Possible\n");
		} else
		{
			double s=r[i].first.first/(double)r[i].first.second;
			printf("%.15lf\n",s);
		}
	}
	return 0;
}
