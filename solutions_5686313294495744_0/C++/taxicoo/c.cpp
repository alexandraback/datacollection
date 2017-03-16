#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define RI(x) scanf("%d", &x)
#define RL(x) scanf("%I64d", &x)
#define RD(x) scanf("%f", &x)

string a[1007], b[1007];
set<string> fake, reall;



void solve(int case_number)
{
    int n;
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i] >> b[i];

    int ans = 0;
    for (int mask=0; mask < (1 << n); ++mask)
    {
        fake.clear();
        reall.clear();
        for (int i=0; i<n; ++i)
        {
            if ((mask & (1 << i)) == 0)
            {
                fake.insert(a[i]);
                fake.insert(b[i]+'2');
            }
            else
            {
                reall.insert(a[i]);
                reall.insert(b[i]+'2');
            }
        }
        bool ok = true;
        for (auto it : fake)
        {
            if (reall.find(it) == reall.end())
            {
                ok = false;
                break;
            }
        }
        if (!ok)
            continue;
        int cur = 0;
        for (int i=0; i<n; ++i)
            if ((mask & (1 << i)) == 0)
                ++cur;
        ans = max(ans, cur);
    }

    cout << "Case #" << case_number << ": " << ans << "\n";
}

int main()
{
    freopen("input3.in", "r", stdin);
    freopen("output3.out", "w", stdout);
    int t;
    cin >> t;
    for (int i=1; i<=t; ++i)
        solve(i);

    return 0;
}

