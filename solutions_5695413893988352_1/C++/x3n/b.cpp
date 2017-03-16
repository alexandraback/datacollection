#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 18;

pair<string, string> solve(string c, string j)
{
    c = string(max((int)j.size() - (int)c.size(), 0), '0').append(c);
    j = string(max((int)c.size() - (int)j.size(), 0), '0').append(j);

    string d1 = "", d2 = "";
    int state = 0;

    for (int i = 0; i < c.size(); i++) {
        if (state == 0) {
            if (c[i] == '?' && j[i] == '?') {
                d1 += '0'; d2 += '0';
            }
            else if (c[i] == '?' || j[i] == '?') {
                d1 += (c[i] == '?') ? j[i] : c[i];
                d2 += (c[i] == '?') ? j[i] : c[i];
            }
            else {
                d1 += c[i]; d2 += j[i];
                if (d1[i] > d2[i]) state = 1;
                else if (d1[i] < d2[i]) state = -1;
            }
        }
        else if (state == 1) {
            if (c[i] == '?') d1 += '0';
            else d1 += c[i];
            if (j[i] == '?') d2 += '9';
            else d2 += j[i];
        }
        else {
            if (c[i] == '?') d1 += '9';
            else d1 += c[i];
            if (j[i] == '?') d2 += '0';
            else d2 += j[i];
        }
    }

    return std::make_pair(d1, d2);
}

int main()
{
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        string ans1, ans2;
        tie(ans1, ans2) = solve(s1, s2);

        printf("Case #%d: %s %s\n", i, ans1.c_str(), ans2.c_str());
    }

    return 0;
}
