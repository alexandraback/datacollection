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

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("Dsmall.out", "w", stdout);
	int t; cin >> t;
	int T = t;
    int k, c, s;
	while(t--)
    {
		cin >> k >> c >> s;
		cout << "Case #" << T-t << ": ";
		for(int i = 0; i < k; i++) cout << i + 1 << " ";
		cout << "\n";
    }
	return 0;
}


