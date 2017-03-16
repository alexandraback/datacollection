#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define RI(x) scanf("%d", &x)
#define RL(x) scanf("%I64d", &x)
#define RD(x) scanf("%f", &x)

int a[30];
int ans[30];
string s;


void solve(int case_number)
{
    for (int i=0; i<30; ++i)
        a[i] = 0;
    cin >> s;
    for (int i=0; i<s.length(); ++i)
        ++a[s[i]-'A'];
    ans[0] = a['z'-'a'];
    ans[2] = a['w'-'a'];
    ans[4] = a['u'-'a'];
    ans[6] = a['x'-'a'];

    ans[1] = a['o'-'a'] - ans[0] - ans[2] - ans[4];
    ans[7] = a['s'-'a'] - ans[6];
    ans[9] = (a['n'-'a'] - ans[1] - ans[7]) / 2;
    ans[5] = a['v'-'a'] - ans[7];
    ans[3] = a['r'-'a'] - ans[0] - ans[4];
    ans[8] = a['i'-'a'] - ans[5] - ans[6] - ans[9];

    cout << "Case #" << case_number << ": ";
    for (int i=0; i<10; ++i)
        for (int j=0; j<ans[i]; ++j)
            cout << i;
    cout << "\n";
}

int main()
{
    freopen("input1.in", "r", stdin);
    freopen("output1.out", "w", stdout);
    int t;
    cin >> t;
    for (int i=1; i<=t; ++i)
        solve(i);

    return 0;
}

