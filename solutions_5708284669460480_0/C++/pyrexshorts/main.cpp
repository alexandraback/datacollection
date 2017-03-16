#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cout << fixed << setprecision(7);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, k, l, s;
    string keys, tar;
    cin >> t;
    for(int tt = 1; tt <= t; tt++)
    {
        cin >> k >> l >> s;
        cin >> keys >> tar;
        vector <string> v;
        vector <int> occ;
        queue <string> q;
        q.push("");
        while(!q.empty())
        {
            string str = q.front();
            if(str.size() == s)
            {
                q.pop();
                v.push_back(str);
                continue;
            }
            q.pop();
            for(int i = 0; i < k; i++)
                q.push(str + keys[i]);
        }
        double m = 0;
        for(int i = 0; i < v.size(); i++)
        {
            double buf = 0;
            if(v[i].size() >= tar.size())
            {
                for(int j = 0; j <= v[i].size() - tar.size(); j++)
                    if(v[i].substr(j, tar.size()) == tar)
                        buf++;
            }
            occ.push_back(buf);
            m = max(m, buf);
        }
//        for(int i = 0; i < occ.size(); i++)
//            cout << occ[i] << " ";
        //cout << "\n";
        double exp = 0;
        for(int i = 0; i < occ.size(); i++)
            exp += occ[i] / (double)occ.size();
        cout << "Case #" << tt << ": " << m - exp << "\n";
    }

    return 0;
}
