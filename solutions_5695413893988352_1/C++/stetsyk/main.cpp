#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <set>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#ifdef lyosha
#define files freopen("input.txt", "r", stdin);
#else
#define files //freopen("howmany.in","r",stdin); freopen("howmany.out","w",sdout);
#endif
using namespace std;
typedef long long ll;
#define y1 fjlwekf
double EPS = 1e-9;
double INF = 1e-9;
const ll mod = 1e9 + 7;
const ll N = 200005;
ll n;
vector<pair<ll, pair<string, string> > > ans;
ll is(char c1, char c2)
{
    if(c1 == '?') return true;
    if(c2 == '?') return true;
    if(c1 == c2) return true;
    return false;
}
bool eq1(string s, string t)
{
    for(ll i = 0; i < n; ++i)
    {
        if(!is(s[i], t[i])) return false;
    }
    return true;
}
bool eq(string &s, string t)
{
    for(ll i = 0; i < n; ++i)
    {
        if(!is(s[i], t[i])) return false;
    }
    for(ll i = 0; i < n; ++i)
    {
        if((s[i] == '?') && (t[i] == '?'))
        {
            s[i] = t[i] = '0';
        }
        else if(s[i] == '?')
        {
            s[i] = t[i];
        }
    }
    return true;
}
ll dif(string s, string t)
{
    ll ans = 0;
    for(ll i = 0; i < n; ++i)
    {
        ans = ans * 10 + (s[i] - t[i]);
    }
    return fabs(ans);
}
void bigg(string s, string t, ll pos, ll rev)
{
    for(ll i = 0; i < pos; ++i)
    {
        if(!is(s[i], t[i])) return;
        if(s[i] == '?' && t[i] == '?')
        {
            s[i] = t[i] = '0';
        }
        else if(s[i] == '?')
        {
            s[i] = t[i];
        }
        else if(t[i] == '?')
        {
            t[i] = s[i];
        }
    }
    if(s[pos] == '?' && t[pos] == '?')
    {
        s[pos] = '1';
        t[pos] = '0';
    }
    else if(s[pos] == '?')
    {
        if(t[pos] == '9') return;
        s[pos] = t[pos] + 1;
    }
    else if(t[pos] == '?')
    {
        if(s[pos] == '0') return;
        t[pos] = s[pos] - 1;
    }
    else
    {
        if(s[pos] <= t[pos]) return;
    }
    for(ll i = pos + 1; i < n; ++i)
    {
        if(s[i] == '?') s[i] = '0';
        if(t[i] == '?') t[i] = '9';
    }
    if(!rev)
        ans.push_back({dif(s, t), {s, t}});
    else
        ans.push_back({dif(s, t), {t, s}});
    return;
}
string f(ll num)
{
    string s = "";
    for(ll i = 0; i < n; ++i)
    {
        s += (num % 10 + '0');
        num /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}
ll brute(string s, string t)
{
    ll ans = 1e9;
    for(ll i = 0; i < 1000; ++i)
    {
        if(eq1(s, f(i)))
            for(ll j = 0; j < 1000; ++j)
            {
                if(eq1(t, f(j)))
                {
                    ans = min(ans, abs(i - j));
                }
            }
    }
    return ans;
}
string s, t;
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    ll T;
    cin >> T;
    for(ll qw = 1; qw <= T; ++qw)
    {
        ans.clear();
        cin >> s >> t;
        n = (ll)s.size();
        cout << "Case #" << qw << ": ";
        if(eq(s, t))
        {
            cout << s << " " << s << "\n";
            continue;
        }
        for(ll i = 0; i < n; ++i)
        {
            bigg(s, t, i, 0);
        }
        for(ll i = 0; i < n; ++i)
        {
            bigg(t, s, i, 1);
        }
        sort(ans.begin(), ans.end());
        /*if(brute(s, t) != ans[0].first){
            cout << brute(s, t) << endl;
            cout << ans[0].first << endl;
            cout << s << " " << t << endl;
            cout << ans[0].second.first << " " << ans[0].second.second << "\n";
        }*/
        cout << ans[0].second.first << " " << ans[0].second.second << "\n";
    }
    return 0;
}
