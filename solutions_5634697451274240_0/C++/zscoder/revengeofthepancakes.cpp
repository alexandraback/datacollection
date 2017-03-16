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
int pancakes[1001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("Bsmall.out", "w", stdout);
	int t; cin >> t;
	int T = t;
    ll ans = 0; int n;
	while(t--)
    {
		memset(pancakes, 0, sizeof(pancakes));
        ans = 0;
        string s; cin >> s;
        n = s.length();
        for(int i = 0; i < n; i++)
		{
			if(s[i] == '+') pancakes[i] = 1;
		}
        for(int i = 0; i < n; i++)
        {
			if(i == 0) ans++;
			else if(pancakes[i] != pancakes[i-1]) ans++;
		}
		if(pancakes[n-1]) ans--;
		cout << "Case #" << T-t << ": " << ans << "\n";
    }
	return 0;
}


