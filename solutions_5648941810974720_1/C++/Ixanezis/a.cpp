#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

const map<int, string> m = {
    {0, "ZERO"},
    {1, "ONE"},
    {2, "TWO"},
    {3, "THREE"},
    {4, "FOUR"},
    {5, "FIVE"},
    {6, "SIX"},
    {7, "SEVEN"},
    {8, "EIGHT"},
    {9, "NINE"},
};

void solve(int e) {
    string s; cin >> s;

    map<int, string> mm = m;

    string ans;

    for (int i=0; i<10 && s.size(); ++i) {
        char uniq = 'a';
        map<char, int> cnt;

        for (const auto& p : mm) {
            for (const char c : p.second) {
                ++cnt[c];
            }
        }

        for (const auto& p : cnt) {
            if (p.second == 1) {
                uniq = p.first;
                break;
            }
        }

        cerr << "uniq: " << uniq << endl;

        int howmany = count(s.begin(), s.end(), uniq);

        int num;
        for (const auto& p : mm) {
            for (const char c : p.second) {
                if (c == uniq) {
                    num = p.first;
                    break;
                }
            }
        }

        for (int u=0; u<howmany; ++u)
            ans += char(num + '0');

        string d;
        map<size_t, int> removed;

        for (char c : s) {
            bool r = false;
            for (size_t u=0; u<mm[num].size(); ++u) {
                if (c == mm[num][u] && removed[u] < howmany) {
                    ++removed[u];
                    r = true;
                    break;
                }
            }
            if (!r)
                d += c;
        }

        mm.erase(num);

        s = d;
        cerr << "s: " << s << endl;
    }

    sort(ans.begin(), ans.end());

    cout << "Case #" << e << ": " << ans << endl;
}

int main() {
    int t; cin >> t;
    for (int e=0; e<t; ++e)
        solve(e+1);
}
