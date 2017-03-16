#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <list>
#include <set>
#include <ctime>
#include <list>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define vi vector<int>
#define vd vector<double>
#define pii pair<int,int>
#define pdd pair<double,double>
#define ll long long
#define INF (1<<30)
using namespace std;

void solve_case(int case_id)
{
    printf("Case #%d: ", case_id);
    ll P = 0, Q = 0;
    string s;
    cin >> s;
    bool first = true;
    for(int i = 0; i < s.length(); ++i)
    {
        if(s[i] == '/')
        {
            first = false;
            continue;
        }
        if(first) P = 10 * P + (ll) (s[i] - '0');
        else Q = 10 * Q + (ll) (s[i] - '0');
    }
    ll d = __gcd(P, Q);
    P /= d;
    Q /= d;
    if(Q == 1)
    {
        if(P == 0) cout << "impossible\n";
        else cout << "0\n";
        return;
    }
    ll qq = Q;
    while(qq > 1)
    {
        if(qq % 2 != 0)
        {
            cout << "impossible\n";
            return;
        }
        qq /= 2;
    }
    int steps = 0;
    while(Q > 1)
    {
        if(P >= Q / 2 && P <= Q)
        {
            if(P < Q) ++steps;
            break;
        }
        Q /= 2;
        ++steps;
    }
    if(steps > 40) cout << "impossible\n";
    else cout << steps << '\n';
}

int main()
{
    int i, t;
    scanf("%d", &t);
    for(i = 1; i <= t; ++i) solve_case(i);
    return 0;
}
