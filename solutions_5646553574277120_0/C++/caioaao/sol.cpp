#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

#define MAXV 31

using namespace std;
typedef long long L;
typedef double D;
typedef vector<L> vi;
typedef vector<vi> vvi;
typedef pair<L,L> ii;

int d, v;
set<int> ds;


typedef set<int>::iterator sit;
bool hasApp[MAXV];
inline bool check()
{
    for(int i = 1; i <= v; ++i)
    {
        hasApp[i] = 0;
    }
    int nApp = 0;
    sit it;
    int s;
    for(int b = 1; b < (1 << (ds.sz())); ++b)
    {
        it = ds.begin();
        s = 0;
        for(int i = 0; i < (int)ds.sz(); ++i, ++it) if(b & (1 << i))
        {
            s += *it;
        }
        if(s <= v && !hasApp[s])
        {
            hasApp[s] = 1;
            if(++nApp == v) return true;
        }
    }
    
    return false;
}

int maxN;
bool bt(int id)
{
    if(id < maxN)
    {
        bool ret;
        for(int i = 1; i <= v; ++i)
        {
            if(!ds.count(i))
            {
                ds.insert(i);
                ret = bt(id+1);
                ds.erase(i);
                if(ret) return true;
            }
        }
        return false;
    }

    else
    {
        return check();
    }
}

void solve()
{
    int c;
    cin >> c >> d >> v;
    ds.clear();
    int di;
    for(int i = 0; i < d; ++i)
    {
        cin >> di;
        ds.insert(di);
    }    

    for(maxN = 0; maxN < 5; ++maxN)
    {
        if(bt(0))
        {
            cout << maxN << '\n';
            return;
        }
    }
    
    cout << "5\n"; // 1 2 4 8 16
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
}
