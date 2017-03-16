#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define FOR(i,s,n) for(int i=(s);i<(n);++i)
#define REP(i,n) FOR(i,0,(n))
#define PB(x) push_back((x))
#define CLR(a,v) memset((a),(v),sizeof((a)))
typedef long long ll;


void f(string & a, string & b)
{
    int n=SZ(a);
    bool eq = 1, aless = 0;

    REP(i,n)
    {
        if (eq)
        {
            if(a[i]=='?'&&b[i]=='?')a[i]=b[i]='0';
            else if (a[i]=='?') a[i] = b[i];
            else if (b[i]=='?') b[i] = a[i];
            else if (a[i] != b[i]) eq = 0, aless = a[i] < b[i];
        }
        else
        {
            if (a[i] == '?') a[i] = aless ? '9' : '0';
            if (b[i] == '?') b[i] = aless ? '0' : '9';
        }
    }
}

ll h(string & x)
{
    ll res = 0;
    int n = SZ(x);
    REP(i,n)
    {
        res *= 10;
        res += x[i]-'0';
    }

    return res;
}

void g(string & a1, string & b1, string & a2, string & b2)
{
    ll x1 = h(a1), x2 = h(a2);
    ll y1 = h(b1), y2 = h(b2);
    ll d1 = abs(x1-y1), d2 = abs(x2 - y2);

    if (d1 != d2)
    {
        if (d2 > d1)swap(a1, a2), swap(b1, b2);
        return;
    }

    if (x1 != x2)
    {
        if (x2 > x1)swap(a1, a2), swap(b1, b2);
        return;
    }

    if (y2 > y1)swap(a1, a2), swap(b1, b2);
}


void solve()
{
    string a,b;
    cin>>a>>b;

    int n=SZ(a);

    string ra = a, rb = b;
    f(ra, rb);

    REP(i,n)
    {
        if(a[i]=='?' && b[i] != '?' && b[i] != '0')
        {
            string xa = a, xb = b;
            xa[i] = xb[i] - 1;
            f(xa, xb);
            g(xa, xb, ra, rb);
        }

        if(b[i]=='?' && a[i] != '?' && a[i] != '0')
        {
            string xa = a, xb = b;
            xb[i] = xa[i] - 1;
            f(xa, xb);
            g(xa, xb, ra, rb);
        }
    }

    REP(i,n)
    {
        if(a[i]=='?' && b[i] != '?' && b[i] != '9')
        {
            string xa = a, xb = b;
            xa[i] = xb[i] + 1;
            f(xa, xb);
            g(xa, xb, ra, rb);
        }

        if(b[i]=='?' && a[i] != '?' && a[i] != '9')
        {
            string xa = a, xb = b;
            xb[i] = xa[i] + 1;
            f(xa, xb);
            g(xa, xb, ra, rb);
        }
    }

    REP(i,n)
    {
        if(a[i]=='?' && b[i] == '?')
        {
            string xa = a, xb = b;
            xa[i] = '0', xb[i]='1';
            f(xa, xb);
            g(xa, xb, ra, rb);
        }

        if(a[i]=='?' && b[i] == '?')
        {
            string xa = a, xb = b;
            xa[i] = '1', xb[i]='0';
            f(xa, xb);
            g(xa, xb, ra, rb);
        }
    }


    cout << ra << " " << rb << endl;
}


int main()
{
    //freopen("../input.txt", "r", stdin);
    freopen("../data/B-large.in", "r", stdin);
    freopen("../output.txt", "w+", stdout);

    int T;
    scanf("%d", &T);
    REP(i, T)
    {
        printf("Case #%d: ", i+1);
        solve();
    }

    return 0;
}
