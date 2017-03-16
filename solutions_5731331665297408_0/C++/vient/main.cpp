#include <iostream>
#include <fstream>
#include <set>
#include <cstdlib>
#include <array>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string Ans;
int n;

void dfs(int now, vector<int> & Prev, vector<bool> & Was, vector<vector<int> > & V, vector<string> & Zip, string ans, bool can)
{
    if (can)
        ans += Zip[now];
    Was[now] = true;
    Prev.push_back(now);
    if (ans.size() == n * 5)
    {
        if (Ans == "")
            Ans = ans;
        else
            Ans = min(Ans, ans);
        ans.erase(ans.size() - 5, 5);
        Was[now] = false;
        Prev.pop_back();
    }
    else
    {
        for (auto i : V[now])
            if (!Was[i])
                dfs(i, Prev, Was, V, Zip, ans, true);
        Prev.pop_back();
        if (Prev.size())
        {
            int next = Prev[Prev.size() - 1];
            Prev.pop_back();
            dfs(next, Prev, Was, V, Zip, ans, false);
            Prev.push_back(next);
        }
        if (can)
            Was[now] = false;
        if (can)
            ans.erase(ans.size() - 5, 5);
    }
}

int main()
{
    ifstream cin("C-small-attempt2.in");
    ofstream cout("output.txt");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    for (int case_num = 1; q; q--, case_num++)
    {
        cout << "Case #" << case_num << ": ";
        Ans = "";
        int m, x, y;
        string s;
        cin >> n >> m;
        vector<string> S(n);
        for (int i = 0; i < n; i++)
            cin >> S[i];
        vector<vector<int> > V(n);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            V[x - 1].push_back(y - 1);
            V[y - 1].push_back(x - 1);
        }
        vector<bool> Was(n, false);
        vector<int> Prev;
        for (int i = 0; i < n; i++)
            dfs(i, Prev, Was, V, S, s, true);
        cout << Ans;
        cout << '\n';
        cerr << case_num << '\n';
    }
    return 0;
}
