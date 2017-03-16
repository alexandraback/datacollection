#include <bits/stdc++.h>
using namespace std;
//@author Vidur Katyal
#define endl '\n'
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef vector <int> vi;
typedef vector < pii > vpii;
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define FAST1 ios_base::sync_with_stdio(0)
#define FAST2 cin.tie(0);cout.tie(0); cerr.tie(0)
const long double PI = acos(-1.0);
const long double EPS = 1e-9;
const LL MOD = 1000000007;
const LL MAXN = 100010;


vector <string> rec(string s, int i)
{
	vector <string> res;
	if(i == s.length())
	{
		res.push_back(s);
		return res;
	}
	if(s[i] == '?')
	{
		for(int x = 0; x <= 9; ++x)
		{
			s[i] = x+48;
			vector <string> get = rec(s, i+1);
			res.insert(res.end(), get.begin(), get.end());
		}
		s[i] = '?';
	}
	else
	{
		vector <string> get = rec(s, i+1);
		res.insert(res.end(), get.begin(), get.end());
	}
	return res;
}

int main()
{
	/*FAST1;
	FAST2;*/
	int T;
	cin>>T;
	for (int t = 1; t <= T; ++t)
	{
		string sc, sj;
		cin>>sc>>sj;
		vector <string> stc = rec(sc, 0);
		vector <string> stj = rec(sj, 0);
		/*for(auto i:stc)
		{
			cout<<i<<" ";
		}
		cout<<endl;
		for(auto i:stj)
		{
			cout<<i<<" ";
		}
		cout<<endl;*/
		map <LL, pair<string, string> > RES;
		for(int i = 0; i < stc.size(); ++i)
		{
			for(int j = 0; j < stj.size(); ++j)
			{
				int ic = stoi(stc[i]);
				int ij = stoi(stj[j]);
				int diff = abs(ic-ij);
				if(RES.find(diff) == RES.end())
				{
					RES[diff] = make_pair(stc[i], stj[j]);
				}
				else if(stc[i] < RES[diff].first)
				{
					RES[diff] = make_pair(stc[i], stj[j]);
				}
				else if(stc[i] == RES[diff].first)
				{
					if(stj[j] < RES[diff].second)
						RES[diff] = make_pair(stc[i], stj[j]);
				}

			}
		}
		
		int diff = RES.begin()->first;
		cout<<"Case #"<<t<<": "<<RES[diff].first<<" "<<RES[diff].second<<endl;
	}
	return 0;
}