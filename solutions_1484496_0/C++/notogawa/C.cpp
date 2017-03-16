#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

void print(const set< int >& s)
{
    for (set< int >::const_iterator i = s.begin(); i != s.end(); ++i)
        cout << *i << " ";
    cout << endl;
}

void solve()
{
    int n = 0;
    cin >> n;
    vector< int > ns(n);
    map< int, set< int > > m;
    for (int i = 0; i < n; ++i)
    {
        cin >> ns[i];
        set< int > s;
        s.insert(ns[i]);
        m[ns[i]] = s;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            map< int, set< int > > _m = m;
            for (map< int, set< int > >::iterator i = _m.begin();
                 i != _m.end(); ++i)
            {
                if (i->second.find(ns[j]) != i->second.end()) continue;
                set< int > s = i->second;
                s.insert(ns[j]);
                if (m.find(i->first+ns[j]) == m.end())
                {
                    m[i->first+ns[j]] = s;
                    continue;
                }
                if (m[i->first+ns[j]] == s) continue;
                print(m[i->first+ns[j]]);
                print(s);
                return;
            }
        }
    }
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cout << "Case #" << (i+1) << ":" << endl;
        solve();
    }
}
