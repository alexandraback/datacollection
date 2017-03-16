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
	for(int i=0;i<t;i++)
	{
		int n;
		vector<int>vec;
		int t = 0;
		cin >> n;
		for(int j=0;j<n;j++)
		{
			int x; cin >> x;
			vec.pb(x);
		}
		int res = INF;
		for(int r=1;r<=1000;r++)
		{
			multiset<int>se;
			for(int i=0;i<vec.size();i++) se.insert(vec[i]);
			int div = 0;
			while(*se.rbegin() > r)
			{
				div++; int x = *se.rbegin();
				multiset<int>::iterator it=se.end();
				it--;
				se.erase(it);
				se.insert(r);
				se.insert(x-r);
			}
			res = min(res,r+div);
		}
		cout << "Case #" << i+1 << ": " << res << endl;
	}
}