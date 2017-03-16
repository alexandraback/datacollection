#include <bits/stdc++.h>

using namespace std;

void solve(int z)
{
    cout << "Case #" << z << ": ";
    string s;
    cin >> s;
    int n = (int)s.size();
    int cnt[30];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++)
    {
        cnt[(int)(s[i] - 'A')]++;
    }
    vector<int> ans;
    while (cnt[(int)('Z' - 'A')] != 0)
    {
        cnt[(int)('Z' - 'A')]--;
        cnt[(int)('E' - 'A')]--;
        cnt[(int)('R' - 'A')]--;
        cnt[(int)('O' - 'A')]--;
        ans.push_back(0);
    }

    while (cnt[(int)('W' - 'A')] != 0)
    {
        cnt[(int)('T' - 'A')]--;
        cnt[(int)('W' - 'A')]--;
        cnt[(int)('O' - 'A')]--;
        ans.push_back(2);
    }

    while (cnt[(int)('U' - 'A')] != 0)
    {
        cnt[(int)('F' - 'A')]--;
        cnt[(int)('O' - 'A')]--;
        cnt[(int)('U' - 'A')]--;
        cnt[(int)('R' - 'A')]--;
        ans.push_back(4);
    }

    while (cnt[(int)('X' - 'A')] != 0)
    {
        cnt[(int)('S' - 'A')]--;
        cnt[(int)('I' - 'A')]--;
        cnt[(int)('X' - 'A')]--;
        ans.push_back(6);
    }

    while (cnt[(int)('G' - 'A')] != 0)
    {
        cnt[(int)('E' - 'A')]--;
        cnt[(int)('I' - 'A')]--;
        cnt[(int)('G' - 'A')]--;
        cnt[(int)('H' - 'A')]--;
        cnt[(int)('T' - 'A')]--;
        ans.push_back(8);
    }

    while (cnt[(int)('H' - 'A')] != 0)
    {
        cnt[(int)('T' - 'A')]--;
        cnt[(int)('H' - 'A')]--;
        cnt[(int)('R' - 'A')]--;
        cnt[(int)('E' - 'A')]--;
        cnt[(int)('E' - 'A')]--;
        ans.push_back(3);
    }

    while (cnt[(int)('S' - 'A')] != 0)
    {
        cnt[(int)('S' - 'A')]--;
        cnt[(int)('E' - 'A')]--;
        cnt[(int)('V' - 'A')]--;
        cnt[(int)('E' - 'A')]--;
        cnt[(int)('N' - 'A')]--;
        ans.push_back(7);
    }

    while (cnt[(int)('O' - 'A')] != 0)
    {
        cnt[(int)('O' - 'A')]--;
        cnt[(int)('N' - 'A')]--;
        cnt[(int)('E' - 'A')]--;
        ans.push_back(1);
    }

    while (cnt[(int)('F' - 'A')] != 0)
    {
        cnt[(int)('F' - 'A')]--;
        cnt[(int)('I' - 'A')]--;
        cnt[(int)('V' - 'A')]--;
        cnt[(int)('E' - 'A')]--;
        ans.push_back(5);
    }

    while (cnt[(int)('I' - 'A')] != 0)
    {
        cnt[(int)('N' - 'A')]--;
        cnt[(int)('I' - 'A')]--;
        cnt[(int)('N' - 'A')]--;
        cnt[(int)('E' - 'A')]--;
        ans.push_back(9);
    }

    sort(ans.begin(), ans.end());
    for (int i : ans)
    {
        cout << i;
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }
}
