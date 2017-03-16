#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wmissing-declarations"

#define FINAL_OUT(x) {cout << x << '\n'; exit(0);}

void solve(int numtest)
{
    string s;
    cin >> s;
    string tmp[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    int order[10] = {0, 6, 2, 4, 8, 3, 1, 5, 7, 9};

    vector<int> mask(300, 0);
    for(char c: s)
        ++mask[c];

    string ans;
    for(int i = 0; i < 10; ++i)
    {
        int cur = order[i];

        vector<int> need(300, 0);
        for(char c: tmp[cur])
            ++need[c];

        while (true)
        {
            bool exit = false;
            for(int c = 'A'; c <= 'Z'; ++c)
            {
                if (mask[c] < need[c])
                {
                    exit = true;
                    break;
                }
            }
            if (exit)
                break;

            for(int c = 'A'; c <= 'Z'; ++c)
                mask[c] -= need[c];
            ans.push_back('0' + cur);
        }
    }
    sort(ans.begin(), ans.end());
    cout << "Case #" << numtest << ": " << ans <<'\n';
}

int main()
{
//    freopen("in.txt", "r", stdin);
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i)
        solve(i);
}

