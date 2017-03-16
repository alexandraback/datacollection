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

string norm(string s)
{
    char c = '=';
    string ret = "";
    for (auto cc: s)
        if (cc != c) {
            c = cc;
            ret += c;
        }
    return ret;
}

int brute(string s)
{
    s = norm(s);
    int n = s.size();
    map<string, int> cache;
    string allhappy = "+";

    queue<string> q;
    auto push = [&](string t, int d) -> void {
        t = norm(t);
        if (cache.count(t))
            return;
        cache[t] = d;
        q.push(t);
    };

    auto flipAndInvert = [](string s, int l) -> string {
        int n = s.size();
        string sl = s.substr(0, l);
        string sr = s.substr(l);
        reverse(sl.begin(), sl.end());
        for (auto &c: sl)
            c = c == '+' ? '-' : '+';
        return norm(sl + sr);
    };

    push(s, 0); 
    while (q.size()) {
        string cur = q.front();
        q.pop();
        if (cur == allhappy)
            break;
        for (int i = cur.size() - 1;i >= 0;i--) {
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
