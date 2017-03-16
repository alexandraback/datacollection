#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define eps 1e-13
#define endl '\n'
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pcc pair<char, char>
#define mp make_pair
#define F first
#define S second
#define pb push_back
ll gcd(ll a, ll b)
{
	if(b == 0)
		return a;
	return gcd(b, a%b);
}
ll modx(ll Base,ll exponent)
{
	ll ans = 1;
	while(exponent)
	{
		if(exponent & 1)
			ans = (ans * Base)%mod;
		Base = (Base * Base)%mod;
		exponent = exponent >> 1;
	}
	return ans;
}
bool cmp()
{

}
ll p2[65], bi[65];
ll out[59][59];
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-0.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    ll t, b, j, i, k, x;
    ll m, ans;
    bool z;
    p2[0] = 1;
    for(j = 1; j <= 50; j++)
        p2[j] = ((ll)2)*p2[j-1];
    cin >> t;
    for(j = 1; j <= t; j++)
    {
        z = false;
        ans = 0;
        cin >> b >> m;
        cout << "Case #" << j << ": ";
        if(m > p2[b-2])
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        cout << "POSSIBLE\n";
        x = 0;
        for(i = 1; i <= b; i++)
        {
            for(k = 1; k <= b; k++)
                out[i][k] = 0;
        }
        for(i = m, k = 1; i > 0; i/=2, k++)
        {
            if(i % 2 == 1)
            {
                bi[k] = 1;
                x = max(x, k);
            }
            else
                bi[k] = 0;
        }
        for(i = 1; i <= x+1; i++)
        {
            if(bi[i] == 1)
                out[i+1][b] = 1;
            for(k = i+1; k <= x+1; k++)
                out[i][k] = 1;
        }
        for(i = 1; i < b; i++)
        {
            for(k = 1; k <= b; k++)
                cout << out[i][k];
            cout << '\n';
        }
        for(i = 1; i <= b; i++)
            cout << "0";
        cout << '\n';
    }
	return 0;
}
