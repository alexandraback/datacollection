#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int t;
int n, m;
vector<pair<long long , long long > > a, b, tmpb;
long long  maxval = 0;
vector <pair<long long , pair<long long  ,long long > > > now;
vector <bool> used;


void Go(int num, int lastnum)
{
    if (num >= n)
    {
        long long  res = 0;

        vector <pair<long long , pair<long long  ,long long > > > tmp = now;
        tmpb = b;
        //sort(tmp.begin(), tmp.end());
        for (int i = 0; i < m; i++)
            for (int j = 0; j < tmp.size(); j++)
            {
                if (i >= tmp[j].first && (i <= tmp[j + 1].first || j + 1 >= tmp.size())
                    && b[i].second == tmp[j].second.second)
                {
                    long long add = min(tmp[j].second.first, tmpb[i].first);
                    res += add;
                    tmp[j].second.first -= add;
                    tmpb[i].first -= add;
                }
            }
       /*for (int i = 0; i < now.size(); i++)
            cout << now[i].first << ' ';
        cout << res << endl;*/

        maxval = max(maxval, res);
        return;
    }

    for (int i = lastnum; i < m; i++)
    {
        now.push_back(make_pair(i, a[num]));
        Go(num + 1, i);
        now.pop_back();
    }

    Go(num + 1, lastnum);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        a.resize(n);
        b.resize(m);
        now.clear();
        used.assign(m, false);
        maxval = 0;

        for (int j = 0; j < n; j++)
            cin >> a[j].first >> a[j].second;
        for (int j = 0; j < m; j++)
            cin >> b[j].first >> b[j].second;

        vector <pair <long long , long long > > ftmp;
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || a[i].second != a[i - 1].second)
                ftmp.push_back(a[i]);
            else
                ftmp.back().first += a[i].first;
        }

        a = ftmp;
        n = a.size();

        ftmp.clear();
        for (int i = 0; i < m; i++)
        {
            if (i == 0 || b[i].second != b[i - 1].second)
                ftmp.push_back(b[i]);
            else
                ftmp.back().first += b[i].first;
        }

        b = ftmp;
        m = b.size();

        Go(0, 0);
        cout << "Case #" << i + 1 << ": " << maxval << endl;
    }

    return 0;
}
