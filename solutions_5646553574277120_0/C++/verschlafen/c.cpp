#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

typedef long long int ll;
typedef unsigned char byte;

int main(int argc, char *argv[])
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        ll c, d, v;
        cin >> c >> d >> v;
        vector<ll> ex(d);
        for (int i = 0; i < d; ++i) cin >> ex[i];

        set<ll> poss;
        for (int i = 0; i < d; ++i)
        {
            set<ll> nxtposs;
            for (int j = 0; j <= c; ++j)
                if (ex[i] * j <= v)
                {
                    if (j) nxtposs.insert(ex[i] * j);
                    for (set<ll>::iterator it = poss.begin(); it != poss.end(); ++it)
                        if (ex[i] * j + *it <= v)
                            nxtposs.insert(ex[i] * j + *it);
                }
            poss = nxtposs;
        }

        ll ret = 0;
        ll curMax = 0;

        set<ll> q = poss;

        while (!q.empty() && curMax < v)
        {
            ll cur = *q.begin();
            if (cur == curMax + 1)
            {
                ++curMax;
                q.erase(q.begin());
            }
            else
            {
                ll req = curMax + 1;
                set<ll> nxtposs;
                for (int j = 0; j <= c; ++j)
                    if (req * j <= v)
                    {
                        if (j) nxtposs.insert(req * j);
                        if (j) q.insert(req * j);
                        for (set<ll>::iterator it = poss.begin(); it != poss.end(); ++it)
                        {
                            ll val = req * j + *it;
                            if (val <= v)
                                nxtposs.insert(val);
                            if (req <= val && val <= v)
                                q.insert(val);
                        }
                    }
                ++ret;
                poss = nxtposs;
            }
        }

        while (curMax < v)
        {
            ll nxt = curMax + 1;
            curMax = nxt * c + curMax;
            ++ret;
        }

        cout << "Case #" << i + 1 << ": " << ret << endl;
    }

    return 0;
}


