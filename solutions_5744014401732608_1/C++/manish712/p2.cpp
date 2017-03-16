#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <set>
#include <utility>
#include <stack>
#include <cmath>
#include <climits>
#include <cassert>
#define sort(v) sort(v.begin(),v.end())
#define null NULL
#define len(x) (sizeof(x)/sizeof(x[0]))
using namespace std;
typedef long long int ll;

int ans[55][55];
ll t,n,m;
int done[55];

void getAns(ll n,ll m)
{
	if(done[n])
	{
		return;
	}
	if(m == (1<<(n-2)))
	{
		ans[1][n] = 1;
		m = m-1;
	}
	for(ll i=2;i<n;i++)
	{
		ans[i][n] = m&1;
		if(ans[i][n] == 1)
		{
			getAns(i,(1<<(i-2)));
		}
		m = m>>1;
	}
	done[n] = 1;
}

void init()
{
	for(int i=0;i<=n;i++)
	{
		for (int j = 0; j <=n; j++)
		{
			ans[i][j] = 0;
		}
	}
	done[0] = 1;
	done[1] = 1;
	for(int i=2;i<=n;i++)
	{
		done[i] = 0;
	}
}

int main()
{
	cin>>t;
	for (int tt = 0; tt < t; tt++)
	{
		cin>>n>>m;
		init();
		if(m > (1<<(n-2)))
		{
			cout<<"Case #"<<tt+1<<": IMPOSSIBLE\n";
		}
		else
		{
			cout<<"Case #"<<tt+1<<": POSSIBLE\n";
			getAns(n,m);
			for(int i=1;i<=n;i++)
			{
				for (int j = 1; j <=n; j++)
				{
					cout<<ans[i][j]<<"";
				}
				cout<<"\n";
			}
		}
	}
}
