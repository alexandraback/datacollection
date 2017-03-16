#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int INF = 1e9;

typedef pair<int,int> pii;


ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    else return gcd(b, a%b);
}

bool powerof2(ll y)
{
    if (y==1) return true;
    if (y&1) return false;
    else return powerof2(y>>1);
}

int solve(ll x, ll y)
{
    ll p = y/2;
    if (x > y)return -1;
    if (x >= p)return 1;
    ll ans = solve(x,p);
    if (ans==-1)return -1;
    return ans+1;
}

int main()
{
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int t, T;
    cin>>T;
    ll x,y;
    char c;
    for (int t = 1; t <= T; t++){
        cin >> x >> c >> y;
        cerr << x << ' ' << y << endl;
        ll g = gcd(x,y);
        x/=g;
        y/=g;
        ll ans = powerof2(y) ? solve(x,y) : -1;
        if (ans == -1)
            cout << "Case #" << t << ": impossible\n";
        else
            cout << "Case #" << t << ": " << ans << "\n";

    }
}
