//Eldar Gaynetdinov
#include <bits/stdc++.h>
using namespace std;

int MI = INT_MAX;
string MIS;

void dfs(string S, size_t k)
{
    if(k == S.length())
    {
        stringstream ss(S);

        int C, J; ss >> C >> J;

        int diff = abs(C - J);

        if(diff < MI)
        {
            MI = diff;

            MIS = S;
        }

        return;
    }

    if(S[k] != '?')
    {
        dfs(S, k + 1);
        return;
    }

    for(char c = '0'; c <= '9'; c++)
    {
        S[k] = c;
        dfs(S, k + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;

    for(int t = 1; t <= T; t++)
    {
        string C, J; cin >> C >> J;

        string S = C + " " + J;

        MI = INT_MAX;
        MIS = "";

        dfs(S, 0);

        cout << "Case #" << t << ": " << MIS << endl;
    }

    return 0;
}
