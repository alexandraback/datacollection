#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

pair<int, int> test(string& s, string& t, int at, int k)
{
    if (at + s.size() > t.size())
        return make_pair(-1, -1);

    int prev = -k, res = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != t[at + i]) {
            if (i - prev < 5)
                return make_pair(-1, -1);
            prev = i;
            res++;
        }
    }
    return make_pair(res, (int)s.size() - prev);
}

int dp[55][6];

int main()
{
    ifstream dict("garbled_email_dictionary.txt");
    string word;
    vector<string> words;
    while (dict >> word)
        words.push_back(word);

    int T; cin >> T;
    for (int t = 0; t < T; ++t) {
        string target;
        cin >> target;
        for (int i = 0; i < 55; ++i) 
            for (int j = 0; j < 6; ++j)
                dp[i][j] = 100000;

        for (int j = 0; j < 6; ++j)
            dp[0][j] = 0;

        int n = target.size();
        for (int at = 0; at < n; ++at) {
            for (int j = 0; j < words.size(); ++j) {
                string& w = words[j];
                for (int err = 0; err < 6; ++err) {
                    pair<int,int> p = test(w, target, at, err);
                    if (p.first >= 0) {
                        int cost = min(p.second, 5);
                        int& res = dp[at + w.size()][cost];
                        if (res > dp[at][err] + p.first) {
                            res = dp[at][err] + p.first;
                        }
                    }
                }
            }
        }

        int res = 10000;
        for (int err = 0; err < 6; ++err)
            res = min(res, dp[target.length()][err]);
        cout << "Case #" << t + 1 << ": " << res << endl;
    }

    return 0;
}


