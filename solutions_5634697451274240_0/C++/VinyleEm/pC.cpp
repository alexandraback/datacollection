#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <functional>
#include <algorithm>
#include <utility>

#include "common.h"

using namespace std;

int greedy(string s)
{
    int flips = 0, n = s.size();
    for (int i = n - 1;i >= 0; i--)
        if (s[i] == '-') {
            if (i == 0) {
                flips++;
                continue;
            }

            if (s[0] == '+') {
                flips++;
                s[0] = '-';
            }
            reverse(s.begin(), s.begin() + i + 1);
            for (int j = 0;j <= i; j++)
                s[j] = s[j] == '+' ? '-' : '+';
            flips++;
        }

    return flips;
}

int brute(string s)
{
    int n = s.size();
    map<string, int> cache;
    string allhappy = "";
    for (int i = 1;i <= n; ++i)
        allhappy += "+";

    queue<string> q;
    auto push = [&](string t, int d) -> void {
        if (cache.count(t))
            return;
        cache[t] = d;
        q.push(t);
    };

    auto flipAndInvert = [](string s, int l) -> string {
        int n = s.size();
        string sl = s.substr(0, l);
        string sr = s.substr(l);
        for (auto &c: sl)
            c = c == '+' ? '-' : '+';
        return sl + sr;
    };

    push(s, 0);
    while (q.size()) {
        string cur = q.front();
        q.pop();
        if (cur == allhappy)
            return cache[cur];
        for (int i = n - 1;i >= 0;i--) {
            string nxt = flipAndInvert(cur, i + 1);
            push(nxt, cache[cur] + 1);
        }
    }

    return cache[allhappy];
}

int main(int argc, char **argv)
{
    int T;
    cin >> T;

    for (int t = 1;t <= T; t++) {
        string s;
        cin >> s;
        cout << "Case #" << t << ": " << brute(s) << endl;
    }

    return 0;
}
