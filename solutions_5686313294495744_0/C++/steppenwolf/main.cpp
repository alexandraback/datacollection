#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int cols[2][17];

int getWordNum(map<string, int>& words, const string& s)
{
    if (words.count(s)) {
        return words[s];
    }
    else {
        int k = words.size();
        words[s] = k;
        return k;
    }
}

int main()
{
    int T;
    cin >> T;

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(6);

    for (int test = 1; test <= T; ++test) {
        map<string, int> words[2];
        vector<pair<int, int>> wordsList;

        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            string s1, s2;
            cin >> s1 >> s2;

            int w1 = getWordNum(words[0], s1);
            int w2 = getWordNum(words[1], s2);
            wordsList.push_back(make_pair(w1, w2));
        }

        int res = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            memset(cols, 0, sizeof(cols[0]) * 2);

            int checked = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    checked++;
                    cols[0][wordsList[i].first] = 1;
                    cols[1][wordsList[i].second] = 1;
                }
            }

            bool can = true;
            for (int i = 0; i < n; ++i) {
                if (!(mask & (1 << i))) {
                    if (!cols[0][wordsList[i].first] || !cols[1][wordsList[i].second]) {
                        can = false;
                        break;
                    }
                }
            }

            if (can) {
                res = max(res, n - checked);
            }
        }


        cout << "Case #" << test << ": " << res << endl;
    }

    return 0;
}
