#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define RI(x) scanf("%d", &x)
#define RL(x) scanf("%I64d", &x)
#define RD(x) scanf("%f", &x)

string c, j;
vector<int> v1, v2;
int n;

void gen1(int pos, int x)
{
    if (pos == n)
        v1.pb(x);
    else
    {
        if (c[pos] != '?')
            gen1(pos+1, x * 10 + (c[pos]-'0'));
        else
        {
            for (int i=0; i<10; ++i)
                gen1(pos+1, x*10 + i);
        }
    }
}

void gen2(int pos, int x)
{
    if (pos == n)
        v2.pb(x);
    else
    {
        if (j[pos] != '?')
            gen2(pos+1, x * 10 + (j[pos]-'0'));
        else
        {
            for (int i=0; i<10; ++i)
                gen2(pos+1, x*10 + i);
        }
    }
}

void solve(int case_number)
{
    v1.clear();
    v2.clear();
    cin >> c >> j;
    n = c.length();
    gen1(0, 0);
    gen2(0, 0);
    int ans1=0, ans2=0;
    for (int i=0; i<v1.size(); ++i)
    {
        for (int j=0; j<v2.size(); ++j)
        {
            if (abs(v1[i] - v2[j]) < abs(v1[ans1] - v2[ans2]))
            {
                ans1 = i;
                ans2 = j;
            }
            else if (abs(v1[i] - v2[j]) == abs(v1[ans1] - v2[ans2]))
            {
                if (v1[i] < v1[ans1])
                {
                    ans1 = i;
                    ans2 = j;
                }
                else if (v1[i] == v1[ans1])
                {
                    if (v2[j] < v2[ans2])
                    {
                        ans1 = i;
                        ans2 = j;
                    }
                }
            }
        }
    }

    cout << "Case #" << case_number << ": ";
    int x = v1[ans1];
    int y = v2[ans2];
    v1.clear();
    v2.clear();
    for (int i=0; i<n; ++i)
    {
        v1.pb(x % 10);
        v2.pb(y % 10);
        x /= 10;
        y /= 10;
    }
    for (int i=n-1; i>-1; --i)
        cout << v1[i];
    cout << ' ';
    for (int i=n-1; i>-1; --i)
        cout << v2[i];
    cout << "\n";
}

int main()
{
    freopen("input2.in", "r", stdin);
    freopen("output2.out", "w", stdout);
    int t;
    cin >> t;
    for (int i=1; i<=t; ++i)
        solve(i);

    return 0;
}

