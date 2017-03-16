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

const ll M = 1000000000 + 7;
vector<pii> v;
ll res;
int n;

int visited[20];
vector<pii> ans;
void solve(int k, int b, int cnt)
{
    if(cnt == n) 
    {
        string s;
        FOR(i, n)
        {
            int b = ans[i].se;
            if(!b)
            {
                s += v[ans[i].fi].fi;
                s += v[ans[i].fi].se;
            }
            else
            {
                s += v[ans[i].fi].se;
            }
        }
        set<char> sc;
        char prev = s[0];
        sc.insert(prev);
        int fail = 0;
        REP(i, 1, s.length() - 1)
        {
            if(s[i] != prev && sc.find(s[i]) != sc.end())
            {
                fail = 1;
            }
            sc.insert(s[i]);
            prev = s[i];
        }
        if(!fail) res = (res + 1) % M;
        return;
    }
    FOR(i, n)
    {
        if(!visited[i])
        {
            visited[i] = 1;
            ans.pb(mp(i, 0));
            solve(i, 0, cnt + 1);
            ans.pop_back();
            visited[i] = 0;
        }
    }
}
int main()
{
    int tests;
    cin >> tests;
    REP(t, 1, tests)
    {
        cin >> n;
        v.clear();
        string s;
        int fail = 0;
        FOR(i, n)
        {                                    
            cin >> s;
            set<char> sc;
            char prev = s[0];
            sc.insert(prev);
            REP(i, 1, s.length() - 1)
            {
                if(s[i] != prev && sc.find(s[i]) != sc.end())
                {
                    fail = 1;
                }
                sc.insert(s[i]);
                prev = s[i];
            }
            if(sc.size() > 2) fail = 1;
            v.pb(mp(s[0], s[s.length() - 1]));
        }
        res = 0LL;
        if(fail)
        {
            cout << "Case #" << t << ": " << res << endl;
            continue;
        }
        memset(visited, 0, 20 * sizeof(int));
        FOR(i, n)
        {
            visited[i] = 1;
            ans.pb(mp(i, 0));
            solve(i, 0, 1);
            ans.pop_back();
            visited[i] = 0;
        } 
        cout << "Case #" << t << ": " << res << endl;
    }

    return 0;
}
