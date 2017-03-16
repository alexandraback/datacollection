#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <stack>
#include <cstring>
#include <ctime>
using namespace std;
#define pb push_back
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
inline void pisz(int n) { printf("%d\n",n); }
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define DBG cerr << "debug here" << endl;
#define DBGV(vari) cerr << #vari<< " = "<< (vari) <<endl;

typedef long long num;
const num BOUND = 100000000000000;
vector<pair<num, num> > v;

bool is_palindrom(num n)
{
    string s = "";
    while(n > 0)
    {
        s += (char) (n % 10);
        n /= 10;
    }
    for(int i = 0; i < s.length() / 2.0; i++)
    {
        if(s[i] != s[s.length() - 1 - i]) return 0;
    }
    return 1;
}
int current_test;
void output(num res)
{
    cout << "Case #" << current_test << ": " << res << "\n";
}
num bin_search(num x, int s, int e)
{
    if(s == e) return v[s].se;
    int m = (int) ceil((s + e) / 2.0);
    if(v[m].fi == x) return v[m].se;
    if(v[m].fi > x) return bin_search(x, s, m - 1);
    return bin_search(x, m, e);
}
int main()
{
    ios_base::sync_with_stdio(0);
    v.pb(mp(0, 1));
    for(num i = 1; i * i <= BOUND; i++)
    {
        num n = i * i;
        if(is_palindrom(i) && is_palindrom(n)) v.pb(mp(n, v.back().se + 1));
    }
    int t;
    cin >> t;
    num a, b;
    for(current_test = 1; current_test <= t; current_test++)
    {
        cin >> a >> b;
        output(bin_search(b, 0, v.size() - 1) - bin_search(a - 1, 0, v.size() - 1));
    }
    return 0;
}
