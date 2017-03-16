#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> P;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define INF 1000000000
int main()
{
	int t; cin >> t;
	map<char,int>ma;
	ma['i'] = 0;
	ma['j'] = 1;
	ma['k'] = 2;
	for(int i=0;i<t;i++)
	{
		cout << "Case #" << i+1 << ": ";
		ll n,r;
		string s;
		cin >> n >> r >> s;
		int x = INF; bool minus = false;
		for(int kk=0;kk<n*(r%4);kk++)
		{
			int k = kk%n;
			if(x == INF)
			{
				x = ma[s[k]];
			}
			else
			{
				if(x == ma[s[k]])
				{
					x = INF;
					minus ^= 1;
				}
				else if((x+1)%3 == ma[s[k]])
				{
					x = (x+2)%3;
				}
				else
				{
					x = (x+1)%3;
					minus ^= 1;
				}
			}
		}
		if(!(x==INF && minus))
		{
			puts("NO"); continue;
		}
		minus = false;
		x = INF;
		int nx = 0;
		ll q = min(120005ll,n*r);
		int rp = (int)q;
		for(int kk=0;kk<rp;kk++)
		{
			int k = kk%n;
			if(x == INF)
			{
				x = ma[s[k]];
			}
			else
			{
				if(x == ma[s[k]])
				{
					x = INF;
					minus ^= 1;
				}
				else if((x+1)%3 == ma[s[k]])
				{
					x = (x+2)%3;
				}
				else
				{
					x = (x+1)%3;
					minus ^= 1;
				}
			}
			if(x == nx)
			{
				nx++; if(nx == 3) break;
				x = INF; minus = false;
			}
		}
		puts(nx==3?"YES":"NO");
	}
}