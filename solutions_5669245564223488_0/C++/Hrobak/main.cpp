#include <bits/stdc++.h>
#include <QtCore>

using namespace std;

int mas [10];

int main ()
{
    ios_base::sync_with_stdio(false);
    ifstream cin ("/home/misha/B-small-attempt1.in");
    ofstream cout ("/home/misha/bOuTtTLl");



    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cout << "Case #" << i + 1 << ": ";
        int n;
        cin >> n;
        vector <int> v(n);
        vector <string> vv (n);
        for (int j = 0; j < n; ++j)
        {
            cin >> vv[j];
        }

        vector <string> vec (n);
        for (int j = 0; j < n; ++j)
        {
            char prc = vv[j][0];
            vec[j].push_back (prc);
            for (int k = 1; k < vv[j].size(); ++k)
            {
                if (vv[j][k] != prc)
                {
                    vec[j].push_back (vv[j][k]);
                    prc = vv[j][k];
                }
            }
        }

        iota (v.begin(), v.end(), 0);
        int cnt = 0;
        do {
            bool ok = true;
            char prc = vec[v[0]][0];
            unordered_map <char, bool> used;
            for (int j = 0; j < n; ++j)
            {
                for (int k = 0; k < vec[v[j]].size(); ++k)
                {
                    if (vec[v[j]][k] != prc && used[vec[v[j]][k]])
                    {
                        ok = false;
                        break;
                    }
                    prc = vec[v[j]][k];
                    used[vec[v[j]][k]] = true;
                }
            }
            if (ok) ++cnt;
        } while (next_permutation(v.begin(), v.end()));
        cout << cnt << endl;
    }
}
