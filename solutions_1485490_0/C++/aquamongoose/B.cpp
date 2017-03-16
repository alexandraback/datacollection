#include <vector>
#include <list>
#include <cassert>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef pair <int,int> pii;
typedef vector <int> vi;
typedef vector <string> vs;
typedef long long ll;
const int INF = 0x3f3f3f3f;

inline int toInt(string& s)
{
    stringstream ss;
    int ret;
    ss << s;
    ss >> ret;
    return ret;
}

inline string toStr(int& i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}

/************************************************************************
******************** Code written during the contest ********************
************************************************************************/

const int MAXN = 110;
int n,m;
ll an[MAXN], at[MAXN];
ll bn[MAXN], bt[MAXN];
map <pair < pair <int,int>, pair <ll,ll> > , ll> memo;

ll find(int a, int b, ll fn, ll sn)
{
    pair < pair <int,int>, pair <ll,ll> > cur = make_pair(make_pair(a,b),make_pair(fn,sn));

    if (memo[cur]) return memo[cur];

    if (a >= n || b >= m) return 0;
    if (at[a] == bt[b])
    {
        if (fn > sn)
            return memo[cur] = sn + find(a,b+1,fn-sn,bn[b+1]);
        else if (fn < sn)
            return memo[cur] = fn + find(a+1,b,an[a+1],sn-fn);
        else
            return memo[cur] = fn + find(a+1,b+1,an[a+1],bn[b+1]);
    }
    return memo[cur] = max(find(a,b+1,fn,bn[b+1]),find(a+1,b,an[a+1],sn));
}

void solve()
{
    memset(an,0,sizeof(an));
    memset(at,0,sizeof(at));
    memset(bn,0,sizeof(bn));
    memset(bt,0,sizeof(bt));
    memo.clear();
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> an[i] >> at[i];
    for (int i=0; i<m; i++)
        cin >> bn[i] >> bt[i];
    
    cout << find(0,0,an[0],bn[0]) << endl;
}

int main()
{
    int t; cin >> t;
    for (int kase=1; kase<=t; kase++)
    {
        cout << "Case #" << kase << ": ";
        solve();
    }
    return 0;
}
