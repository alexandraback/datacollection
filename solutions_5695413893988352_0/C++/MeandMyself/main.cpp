#include <iostream>

#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <cmath>
#include <algorithm>

#include <fstream>

using namespace std;


// "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"

vector < int > solve (const string &s) {
    vector < int > ans (10 , 0);
    vector < int > al (30, 0);
    for (int i = 0; i < s.size(); ++i) {
        al[s[i] - 'A']++;
    }
    ans[0] += al['Z' - 'A'];
    al['Z' - 'A'] -= ans[0];
    al['E' - 'A'] -= ans[0];
    al['R' - 'A'] -= ans[0];
    al['O' - 'A'] -= ans[0];
    ans[2] += al['W' - 'A'];
    al['T' - 'A'] -= ans[2];
    al['W' - 'A'] -= ans[2];
    al['O' - 'A'] -= ans[2];
    ans[6] += al['X' - 'A'];
    al['S' - 'A'] -= ans[6];
    al['I' - 'A'] -= ans[6];
    al['X' - 'A'] -= ans[6];
    ans[7] += al['S' - 'A'];
    al['S' - 'A'] -= ans[7];
    al['E' - 'A'] -= ans[7];
    al['V' - 'A'] -= ans[7];
    al['E' - 'A'] -= ans[7];
    al['N' - 'A'] -= ans[7];
    ans[5] += al['V' - 'A'];
    al['F' - 'A'] -= ans[5];
    al['I' - 'A'] -= ans[5];
    al['V' - 'A'] -= ans[5];
    al['E' - 'A'] -= ans[5];
    ans[4] += al['F' - 'A'];
    al['F' - 'A'] -= ans[4];
    al['O' - 'A'] -= ans[4];
    al['U' - 'A'] -= ans[4];
    al['R' - 'A'] -= ans[4];
    ans[8] += al['G' - 'A'];
    al['E' - 'A'] -= ans[8];
    al['I' - 'A'] -= ans[8];
    al['G' - 'A'] -= ans[8];
    al['H' - 'A'] -= ans[8];
    al['T' - 'A'] -= ans[8];
    ans[1] += al['O' - 'A'];
    al['O' - 'A'] -= ans[1];
    al['N' - 'A'] -= ans[1];
    al['E' - 'A'] -= ans[1];
    ans[3] += al['R' - 'A'];
    al['T' - 'A'] -= ans[3];
    al['H' - 'A'] -= ans[3];
    al['R' - 'A'] -= ans[3];
    al['R' - 'A'] -= ans[3];
    al['E' - 'A'] -= ans[3];
    ans[9] += al['I' - 'A'];
    al['N' - 'A'] -= ans[9];
    al['I' - 'A'] -= ans[9];
    al['N' - 'A'] -= ans[9];
    al['E' - 'A'] -= ans[9];
    return ans;

}

int solve2(string s1, string s2) {
    int firstmin = -1;
    //auto p = solve(s);
    string ans1 = s1, ans2 = s2;
    for (int i = 0; i < s1.size(); ++i) {
        if (firstmin == -1) {
            if (s1[i] == '?' && s2[i] == '?') {
                ans1[i] = '0';
                ans2[i] = '0';
            }
            if (s1[i] != '?' && s2[i] == '?') {
                ans2[i] = ans1[i];
            }
            if (s1[i] == '?' && s2[i] != '?') {
                ans1[i] = ans2[i];
            }
            if (s1[i] != '?' && s2[i] != '?') {
                if (s1[i] > s2[i]) {
                    firstmin = 1;
                }
                if (s1[i] < s2[i]) {
                    firstmin = 0;
                }
            }
        }
        if (firstmin == 0) {
            if (s1[i] == '?') {
                ans1[i] = '9';
            }
            if (s2[i] == '?') {
                ans2[i] ='0';
            }
        }
        if (firstmin == 1) {
            if (s1[i] == '?') {
                ans1[i] = '0';
            }
            if (s2[i] == '?') {
                ans2[i] ='9';
            }
        }
    }
}


string tostr (int num) {
    string ans = "";
    while (num != 0) {
        ans = char(num % 10 + '0') + ans;
        num /= 10;
    }
    return ans;
}

int main()
{
    ifstream cin ("/Users/Roman/ClionProjects/Calculations/input.txt");
    ofstream cout ("/Users/Roman/ClionProjects/Calculations/output.txt");

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cout.setf(ios_base::fixed);
    cout.precision(28);

    int tt;
    cin >> tt;
    //cout << tt;
    for (int t = 0; t < tt; ++t) {
        string s1, s2;
        cin >> s1 >> s2;
        int k = s2.length();
        int mx = 1;
        for (int i = 0; i < k; ++i) {
            mx *= 10;
            //cout << s1 << s2 << endl;
        }
        // cout << mx << endl;
        string res1, res2;
        int r1 = 999, r2 = 0;
        for (int i = 0; i < mx; ++i) {
            auto ans1 = to_string(i);
            while (ans1.length() != k) {
                ans1 = "0" + ans1;
            }
            //cout << ans1 << endl;
            bool ok = true;
            for (int j = 0; j < k; ++j) {
                if (s1[j] == '?') {
                    continue;
                }
                if (s1[j] != ans1[j]) {
                    ok = false;
                }
            }
            if (ok) {
                // cout << i << endl;
                for (int ii = 0; ii < mx; ++ii) {
                    auto ans2 = to_string(ii);
                    while (ans2.length() != k) {
                        ans2 = "0" + ans2;
                    }
                    ok = true;
                    for (int j = 0; j < k; ++j) {
                        if (s2[j] == '?') {
                            continue;
                        }
                        if (s2[j] != ans2[j]) {
                            ok = false;
                        }
                    }
                    if (ok) {
                        // cout << i << " " << ii << endl;
                        if (abs(r1 - r2) > abs(ii - i)) {
                            r1 = i;
                            res1 = ans1;
                            r2 = ii;
                            res2 = ans2;
                        }
                        if (abs(r1 - r2) ==  abs(ii - i) && i < r1) {
                            r1 = i;
                            res1 = ans1;
                            r2 = ii;
                            res2 = ans2;
                        }
                        if (abs(r1 - r2) == abs(ii - i) && i == r1 && ii < r2) {
                            r1 = i;
                            res1 = ans1;
                            r2 = ii;
                            res2 = ans2;
                        }
                    }
                }
            }
        }
        cout << "Case #" << t + 1 << ": ";

        cout << res1 << " " << res2 << endl;
    }
    return 0;
}