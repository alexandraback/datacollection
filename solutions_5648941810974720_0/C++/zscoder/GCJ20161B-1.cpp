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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

map<char, int> ma;
int ans[10];
string dig[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int a[10] = {0, 6, 2, 7, 5, 4, 8, 3, 9, 1};
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("GCJ20161B-1.out", "w", stdout);
	int t; cin >> t;
	int T = 0;
	while(t--)
	{
		string s;
		cin >> s;
		ma.clear();
		for(int i = 0; i < int(s.length()); i++)
		{
			ma[s[i]]++;
		}
		memset(ans, 0, sizeof(ans));
		for(int i = 0; i < 10; i++)
		{
			bool possible = true;
			while(possible)
			{
				for(int j = 0; j < dig[a[i]].length(); j++)
				{
					ma[dig[a[i]][j]]--;
					//cout << i << ' ' << dig[i][j] << ' ' << ma[dig[i][j]] << endl;
					if(ma[dig[a[i]][j]] < 0)
					{
						possible = false;
					}
				}
				if(possible)
				{
					ans[a[i]]++;
				}
				else
				{
					for(int j = 0; j < dig[a[i]].length(); j++)
					{
						ma[dig[a[i]][j]]++;
					}
				}
			}
		}
		for(int i = 0; i < 26; i++)
		{
			if(ma[i+'A'] != 0) cout << T + 1 << ' ' << s << endl;
		}
		T++;
		cout << "Case #" << T << ": ";
		for(int i = 0; i < 10; i++)
		{
			for(int j = 0; j < ans[i]; j++)
			{
				cout << i;
			}
		}
		cout << '\n';
	}
	return 0;
}
