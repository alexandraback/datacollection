#include <iostream>
#include <cstdio>
#include <string>
#include <sstream> 
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define DBG cerr << "debug here" << endl;
#define DBGV(vari) cerr << #vari<< " = "<< (vari) <<endl;

typedef long long ll;
typedef double fl;

ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}
ll p2[41];

int solve(ll p, ll q)
{    
    if(p > q / 2) return 1;
    if(p == 1LL)
    {
        FOR(i, 39) {
            if(p2[i] == q) return i;
        }
    }
    p -= 1;
    q /= 2;
    ll d = gcd(p, q);
    p /= d;
    q /= d;
    return 1 + solve(p, q);
}
int main()
{
    p2[0] = 1LL;
    REP(i, 1, 39) p2[i] = 2 * p2[i - 1];
    int tests;
    cin >> tests;
    REP(t, 1, tests)
    {
        ll p, q;
        char c;
        cin >> p >> c >> q;
        ll d = gcd(p, q);
        p /= d;
        q /= d;        
        if(p == 0)
        {
            cout << "Case #" << t << ": " << 0 << endl;
            continue;
        }
        int found = 0;
        ll k = 0;
        REP(i, 0, 39) 
        {
            if(p2[i] == q) 
            {
                found = 1;
                break;
            }
            k++;
        }
        if(!found || (p % 2 == 0))
        {
            cout << "Case #" << t << ": impossible" << endl;
        }
        else
        {
            cout << "Case #" << t << ": " << solve(p, q) << endl;
        }
    }

    return 0;
}
