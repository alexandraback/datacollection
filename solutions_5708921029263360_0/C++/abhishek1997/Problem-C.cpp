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
map < pll , ll> x1;
map < pll , ll> x2;
map < pll , ll> x3;
struct node
{
    ll a1, a2, a3;
}yo[1000009];
ll in;
ll func(ll j, ll p, ll s, ll k)
{
    ll ans = 0, a, b, c;
    in = 0;
    /*for(a = 1; a <= j; a++)
    {
        for(b = 1; b <= p; b++)
        {
            x1[mp(a,b)] = 0;
            for(c = 1; c <= s; c++)
            {
                x2[mp(b,c)] = 0;
                x3[mp(a,c)] = 0;
            }
        }
    }*/
    for(a = 1; a <= j; a++)
    {
        for(b = 1; b <= p; b++)
            x1[mp(a,b)] = 0;
    }
    for(a = 1; a <= j; a++)
    {
        for(c = 1; c <= s; c++)
            x2[mp(a,c)] = 0;
    }
    for(c = 1; c <= s; c++)
    {
        for(b = 1; b <= p; b++)
            x2[mp(b,c)] = 0;
    }
    for(a = 1; a <= j; a++)
    {
        for(b = 1; b <= p; b++)
        {
            for(c = 1; c <= s; c++)
            {
                if(x1[mp(a,b)] == k)
                    break;
                else if(x2[mp(b,c)] == k || x3[mp(a,c)] == k)
                    continue;
                else
                {
                    x1[mp(a,b)]++;
                    x2[mp(b,c)]++;
                    x3[mp(a,c)]++;
                    yo[in].a1 = a;
                    yo[in].a2 = b;
                    yo[in].a3 = c;
                    in++;
                    ans++;
                }
            }
        }
    }
    return ans;
}
int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C-small-1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    ll t, co, j, p, s, k, ans, i;
    cin >> t;
    for(co = 1; co <= t; co++)
    {
        cin >> j >> p >> s >> k;
        ans = 0;
        cout << "Case #" << co << ": ";
        ans = func(j, p, s, k);
        cout << ans << '\n';
        for(i = 0; i < in; i++)
            cout << yo[i].a1 << " " << yo[i].a2 << " " << yo[i].a3 << '\n';
    }
	return 0;
}
