// C.cpp

// read in dict, set<string>
//
// calc(int l, int r) returns
// min num of op to make S[l..r) words
// or -1 if impossible

#include <fstream>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int D = 5;
const int NOTUSED = -2;
const int INF = -1;

vector<string> dict;
int dp[60][60];
int cost[60][60];
string S;

int change(int l, int r)
{
    string word = S.substr(l, r-l);
    int len = word.length();
    int ans = len + 1;
    for (int k = 0; k < dict.size(); ++k)
    if (dict[k].length() == word.length())
    {
        int curr = 0;
        int p = -100;
        for (int i = 0; i < word.length(); ++i) {
            if (word[i] != dict[k][i]) {
                if (i-p > D) { curr++; p = i; }
                else { curr = len+1; break; }
            }
        }
        ans = min(ans, curr);
    }
    return ans;
}

int calc(int l, int r)
{
    assert(l < r);
    if (dp[l][r] != NOTUSED) return dp[l][r];
    // one word
    int ans = cost[l][r];

    // split
    for (int k = l+1; k < r; ++k) {
        int s1, s2;
        s1 = calc(l, k);
        s2 = calc(k, r);
        if (s1 != INF && s2 != INF) {
            ans = min(ans, s1 + s2);
        }
    }

    int len = r - l;
    if (ans > len) return dp[l][r] = INF;
    else return dp[l][r] = ans;
}

void solve(int tcase)
{
    cin >> S;
    int N = S.length();
    for (int l = 0; l < N; ++l)
    for (int r = l+1; r <= N; ++r)
        cost[l][r] = change(l, r);

    for (int l = 0; l < N; ++l)
    for (int r = l+1; r <= N; ++r)
        dp[l][r] = NOTUSED;

    int ans = calc(0, S.length());
    cout << "Case #" << tcase << ": ";
    cout << ans << endl;
}

void init()
{
    ifstream fin("dict.txt");
    string w;
    while (fin >> w)
        dict.push_back(w);
}

int main()
{
    init();
    int T; cin >> T;
    for (int t = 1; t <= T; ++t)
        solve(t);
}
