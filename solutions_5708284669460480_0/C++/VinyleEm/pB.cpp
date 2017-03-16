#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <string>

using namespace std;

string format(double ans)
{
    char ret[64];
    sprintf(ret, "%.7lf", ans);
    return string(ret);
}

string solve(const string L, const string T, int S)
{
    map<char, int> counts;
    for (auto c : L)
        counts[c]++;

    for (auto c : T)
        if (!counts.count(c))
            return format(0);

    set<string> prefixes;
    for (int i = 0;i <= T.size(); ++i) {
        prefixes.insert(T.substr(0, i));
    }

    int maxRes = 0;
    string pref = "";
    for (int i = 0;i <= S; ++i) {
        if (pref == T)
            maxRes++;
        string pref2 = "";
        for (auto c : L) {
            string s = pref + c;
            int maxPrefSize = 0;
            for (int a = 0;a <= s.size(); a++)
                if (prefixes.count(s.substr(s.size() - a))) {
                    maxPrefSize = a;
                }

            if (maxPrefSize > pref2.size())
                pref2 = s.substr(s.size() - maxPrefSize);
        }

        pref = pref2;
    }

    double prob = 1;
    for (auto c : T) {
        int total = L.size();
        prob *= counts[c] * 1.0 / total;
    }

    return format(maxRes - prob * (S + 1 - T.size()));
}

int main(int argc, char **argv)
{
    int T;
    cin >> T;

    for (int t = 1;t <= T; t++) {
        int K, L, S;
        cin >> K >> L >> S;

        string letters, target;
        cin >> letters >> target;

        cout << "Case #" << t << ": " << solve(letters, target, S) << endl;
    }

    return 0;
}
