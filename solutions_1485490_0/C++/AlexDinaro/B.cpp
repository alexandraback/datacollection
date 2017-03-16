#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cctype>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define mp make_pair
#define pb push_back

void prepare()
{
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}

struct din
{
	long long tinb, cur_box, cur_toy; 
};

struct tt
{
	long long count;
	int type;
};

void solve()
{
	int tests;
	cin>>tests;
	for (int test=1; test<=tests; ++test)
	{
		cerr<<test<<endl;
		long long ans=0;
		int n,m;
		cin>>n>>m;
		vector<tt> box(n+1), toy(m+1);
		tt temp;
		for (int i=0;i<n;++i)
		{
			cin>>temp.count>>temp.type;
			box[i]=temp;
		}
		for (int i=0;i<m;++i)
		{
			cin>>temp.count>>temp.type;
			toy[i]=temp;
		}
		temp.count=-1;
		temp.type=-1;
		box[n]=toy[m]=temp;
		din tmp;
		tmp.tinb=0;
		tmp.cur_box=0;
		tmp.cur_toy=0;
		vector< vector< list<din> > > dp(n+1, vector<list<din>>(m+1));
		tmp.cur_box=box[0].count;
		tmp.cur_toy=toy[0].count;
		dp[0][0].push_back(tmp);
		for (int i=0;i<n;++i)
			for (int j=0;j<m;++j)
			{
				for (auto it = dp[i][j].begin(); it!=dp[i][j].end(); ++it)
				{
					if (box[i].type == toy[j].type)
					{
						if ((*it).cur_box==(*it).cur_toy)
						{
							tmp = (*it);
							tmp.tinb += tmp.cur_box;
							tmp.cur_box=box[i+1].count;
							tmp.cur_toy=toy[j+1].count;
							dp[i+1][j+1].push_back( tmp);
							if (ans<tmp.tinb)
								ans=tmp.tinb;
						}
						else if ((*it).cur_box > (*it).cur_toy)
						{
							tmp = (*it);
							tmp.tinb += tmp.cur_toy;
							tmp.cur_box-=tmp.cur_toy;
							tmp.cur_toy=toy[j+1].count;
							//if (tmp.tinb!=0)
								dp[i][j+1].push_back( tmp);		
							if (ans<tmp.tinb)
								ans=tmp.tinb;				
						}
						else
						{
							tmp = (*it);
							tmp.tinb += tmp.cur_box;
							tmp.cur_toy-=tmp.cur_box;
							tmp.cur_box=box[i+1].count;
							//if (tmp.tinb!=0)
								dp[i+1][j].push_back( tmp);
							if (ans<tmp.tinb)
								ans=tmp.tinb;
						}
					}
					else
					{
						tmp = (*it);
						tmp.cur_toy=toy[j+1].count;
							//if (tmp.tinb!=0)
								dp[i][j+1].push_back( tmp);
						if (ans<tmp.tinb)
							ans=tmp.tinb;

						tmp = (*it);
						tmp.cur_box=box[i+1].count;
							//if (tmp.tinb!=0)
								dp[i+1][j].push_back( tmp);
						if (ans<tmp.tinb)
							ans=tmp.tinb;
					}
				}
			}
		//	cout<<endl;
		//for (int i=0;i<=n ;++i)
		//{
		//	for (int j=0;j<=m; ++ j)
		//		cout<<dp[i][j].tinb<<" ";
		//	cout<<endl;
		//}
		cout<<"Case #"<<test<<": "<<ans<<endl;
	}
}

int main()
{
	prepare();
	solve();
	return 0;
}