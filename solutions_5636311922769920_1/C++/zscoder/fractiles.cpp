#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld;
const int MOD = 1e9 + 7;
#define fi first
#define se second
#define pb push_back
#define mp make_pair

int divide(int x, int y)
{
	int ans = x/y;
	if(x % y == 0) return ans;
	else return (ans + 1);
}
int a[101];
ll powers[101];
ll permvalue(int n)
{
	ll res = 0;
	for(int i = 0; i < n; i++)
	{
		a[i]--;
		res += powers[n-1-i]*a[i];
	}
	res++;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("D-large.in", "r", stdin);
	freopen("Dlarge.out", "w", stdout);
	int t; cin >> t;
	int T = t;
    int k, c, s;
	while(t--)
    {
		cin >> k >> c >> s;
		int cnt = 1;
		memset(powers, 0, sizeof(powers));
		memset(a, 0, sizeof(a));
		powers[0] = 1;
		for(ll i = 1; i <= c; i++)
		{
			powers[i] = k*powers[i-1];
		}
		cout << "Case #" << T-t << ": ";	
		if(s < divide(k, c)) cout << "IMPOSSIBLE";
		else
		{
			for(int j = 0; j < divide(k, c); j++)
			{
				for(int i = 0; i < c; i++)
				{
					a[i] = cnt;
					cnt++;
					if(cnt > k) cnt = 1;
					//cout << a[i] << " ";
				}
				cout << permvalue(c) << " ";
			}
		}
		cout << "\n";
    }
	return 0;
}


