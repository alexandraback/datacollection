#include <stdio.h>
#include <functional>
#include <bitset>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#include <string.h>
#include <numeric>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long ll;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define INF 1000000000000000LL
#define EPS 1e-5

string toString (ll n)
{
	if (n == 0) return "0";
	string s;
	while (n)
	{
		s += (n%10) + '0';
		n /= 10;
	}
	reverse(all(s));
	return s;
}

ll solve (string s)
{
	if (sz(s) == 1) return s[0] - '0';
	if (s[0] == '1')
	{
		ll K = 0;
		for (int i=sz(s)-1 ; i>=1 ; i--)
		{
			K *= 10LL;
			K += (s[i] - '0');
		}
		K++;

		int n = sz(s)-1;
		s.clear();
		for (int i=0 ; i<n ; i++) s += '9';
		return K + solve(s);
	}
	else
	{
		int d = s[sz(s)-1] - '1';
		s[sz(s) - 1] = '1';
		reverse(all(s));
		return d + 1 + solve(s);
	}
}

ll dp[1000010];

bool checkRevSmall (ll n)
{
	if (n %10 == 0) return 0;
	string s1 = toString(n);
	string s2 = s1;
	reverse(all(s2));
	return s2 < s1;
}

ll getRev (ll n)
{
	ll ans = 0;
	while (n)
	{
		ans *= 10;
		ans += n%10;
		n/=10;
	}
	return ans;
}

ll solvedp (ll n)
{
	if (n == 1) return 0;
	if (dp[n] != -1) return dp[n];

	ll ret = 1000000000000000000LL;
	if (checkRevSmall(n))
	{
		ret = 1 + solvedp(getRev(n));
	}
	ret = min(ret , 1 + solvedp(n-1));

	return dp[n] = ret;
}

int main() {
    freopen ("txt.in","r",stdin);
    freopen ("txt.out","w",stdout);

    int TC;
    cin >> TC;
    int CC = 1;
    memset(dp,-1,sizeof dp);
    while (TC--)
    {
    	ll N;
    	cin >> N;
    	int f = 0;
//    	if (N%10 == 0) N-- , f=1;
    	string s = toString(N);
    	printf("Case #%d: ",CC++);
//    	cout << s << endl;
//    	cout << solve(s) + f << endl;
    	cout << solvedp(N) + 1 << endl;
    }
}
