#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Pair;

#define var_dump(x) cerr<<#x<<": "<<x<<'\n'
#define arr_dump(x, n) {cerr<<#x<<"[]: ";for(int i=1;i<=n;++i) cerr<<x[i]<<" ";cerr<<'\n';}

const int MAXN = 100000;

vector<string> Numbers = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
vector<int> Num = {8, 3, 2, 4, 5, 0, 1, 7, 6, 9};
vector<char> Char = {'G', 'H', 'T', 'U', 'F', 'R', 'O', 'V', 'S', 'I'};
int Count[256];

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);


    int t;
    cin >> t;

    for(int tt = 1; tt <= t; ++tt) {
        string str;
        cin >> str;
        for(auto c : str)
            Count[c] += 1;

        vector<int> Ans;

        for(int i = 0; i < 10; ++i) {
            while(Count[Char[i]] > 0) {
                Ans.push_back(Num[i]);
                for(auto x : Numbers[Num[i]])
                    Count[x] -= 1;
            }
        }

        sort(Ans.begin(), Ans.end());

        cout << "Case #" << tt << ": ";
        for(auto x : Ans) cout << x;
        cout << '\n';
    }

    return 0;
}
