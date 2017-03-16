#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    cout.setf(ios::fixed);
    cout.precision(10);

    for (int tt=1; tt<=t; tt++)
    {
        int n;
        cin >> n;

        vector<pair<int, int> > v;

        for (int i=0; i<n; i++)
        {
            int x, y;
            cin >> x >> y;
            v.push_back(make_pair(x, y));
        }

        int r = 0;
        int ans = 0;

        for (;;)
        {
            int i;
            for (i=0; i<v.size(); i++)
                if (v[i].second <= r)
                {
                    ans++;
                    r++;
                    r += v[i].first >= 0;
                    v.erase(v.begin() + i);
                    i = -1;
                    break;
                }

            if (i < 0)
                continue;

            int j = -1;

            for (i=0; i<v.size(); i++)
                if (v[i].first <= r && v[i].first != -1 && (j == -1 || v[j].second < v[i].second))
                    j = i;

            if (j < 0)
                break;

            ans++;
            r++;
            v[j].first = -1;
        }

        cout << "Case #" << tt << ": ";
        if (r < 2 * n)
            cout << "Too Bad" << endl;
        else
            cout << ans << endl;
    }

    return 0;
}
