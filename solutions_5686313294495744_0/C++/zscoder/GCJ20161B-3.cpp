#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef pair<int,int> ii;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

set<string> se;
string l1[1001];
string l2[1001];
vector<string> v;
ii L[1001];

pbds good;
pbds bad;
map<ii, bool> ma;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("GCJ20161B-3.out", "w", stdout);
	int t; cin >> t;
	int T = 0;
	while(t--)
	{
		int n; cin >> n;
		string a, b;
		for(int i = 0; i < n; i++)
		{
			cin >> a >> b;
			se.insert(a);
			se.insert(b);
			l1[i] = a;
			l2[i] = b;
		}
		for(set<string>::iterator it = se.begin(); it != se.end(); it++)
		{
			v.pb(*it);
		}	
		for(int i = 0; i < n; i++)
		{
			L[i] = ii(lower_bound(v.begin(), v.end(), l1[i]) - v.begin(), lower_bound(v.begin(), v.end(), l2[i]) - v.begin());
			//cout << L[i].fi << ' ' << L[i].se << '\n';
		}
		//cout << "----------------------------------------------" << '\n';
		int ans = 0;
		for(int i = 0; i < (1<<n); i++)
		{
			bool possible = false; 
			int tmp = i;
			for(int j = 0; j < n; j++)
			{
				if(tmp&1) bad.insert(L[j]);
				else good.insert(L[j]);
				tmp >>= 1;
			}
			int tmpans = good.size();
			for(int j = 0; j < bad.size(); j++)
			{
				for(int k = 0; k < bad.size(); k++)
				{
					if(j != k)
					{
						ii x = *bad.find_by_order(j);
						ii y = *bad.find_by_order(k);
						if(x.fi != y.fi && x.se != y.se)
						{
							ii z;
							z.fi = x.fi; z.se = y.se;
							ma[z] = true;
						}
					}
				}
			}
			bool exist = true;
			while(exist)
			{
				exist = false;
				int tmp;
				for(int i = 0; i < good.size(); i++)
				{
					ii tmp2 = *good.find_by_order(i);
					if(ma[tmp2])
					{
						exist = true;
						tmp = i;
						break;
					}
				}
				if(exist)
				{
					for(int j = 0; j < bad.size(); j++)
					{
						ii x = *bad.find_by_order(j);
						ii y = *good.find_by_order(tmp);
						if(x.fi != y.fi && x.se != y.se)
						{
							ii z;
							z.fi = x.fi; z.se = y.se;
							ma[z] = true;
							z.fi = x.se; z.se = y.fi;
							ma[z] = true;
						}
					}
					ii TMP = *good.find_by_order(tmp);
					bad.insert(TMP);
					good.erase(TMP);
				}
			}
			if(good.size() == 0) 
			{
				/*
				bad.clear();
				good.clear();
				int tmp = i;
				for(int j = 0; j < n; j++)
				{
					if(tmp%2) bad.insert(L[j]);
					else good.insert(L[j]);
					tmp >>= 1;
				}
				
				for(int j = 0; j < bad.size(); j++)
				{
					ii tmp2 = *bad.find_by_order(j);
					cout << tmp2.fi << ' ' << tmp2.se << '\n';
				}
				cout << good.size() << endl;
				for(int j = 0; j < good.size(); j++)
				{
					ii tmp2 = *good.find_by_order(j);
					cout << tmp2.fi << ' ' << tmp2.se << '\n';
				}
				*/
				ans = max(ans,tmpans);
			}
			bad.clear();
			good.clear();
			ma.clear();
		}
		T++;
		cout << "Case #" << T << ": ";
		cout << ans;
		cout << '\n';
		se.clear();
		v.clear();
	}
	return 0;
}
