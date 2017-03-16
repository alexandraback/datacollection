#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>

using namespace std;

int t;
string str1, str2;
long long e[20], l[20], g[20];

void solve(string str1, string str2) {
    long long ifless = 1, ifgreater = 1, ifequal = 0;
    long long multiplier = 1;
    for (int i = str1.size() - 1; i > 0; --i) {
        if (str1[i] != '?') {
            ifless += ('9' - str1[i]) * multiplier;
            ifgreater += (str1[i] - '0') * multiplier;
        }
        if (str2[i] != '?') {
            ifless += (str2[i] - '0') * multiplier;
            ifgreater += ('9' - str2[i]) * multiplier;
        }
        if (str1[i] != '?' && str2[i] != '?')
            ifequal += (str1[i] - str2[i]) * multiplier;
        l[i - 1] = ifless;
        e[i - 1] = abs(ifequal);
        g[i - 1] = ifgreater;
        multiplier *= 10;
    }
    bool chosen = false;
    bool chosen_less = false, chosen_greater = false;
    for (int i = 0; i < str1.size(); ++i) {
        if (!chosen && str1[i] != '?' && str2[i] != '?') {
            if (str1[i] < str2[i]) {
                chosen = chosen_less = true;
            }
            if (str1[i] > str2[i]) {
                chosen = chosen_greater = true;
            }
            if (str1[i] == str2[i])
                continue;
        }
        bool can_less = !(str1[i] == '9' || str2[i] == '0');
        bool can_greater = !(str2[i] == '9' || str1[i] == '0');
        if (!chosen && can_less &&
            (l[i] < e[i] || (l[i] == e[i] && str2[i] != '?')) &&
            (l[i] < g[i] || !can_greater || (l[i] == g[i] && str1[i] == '?'))){
            chosen = chosen_less = true;
            if (str1[i] == '?')
                if (str2[i] != '?')
                    str1[i] = str2[i] - 1;
                else {
                    str1[i] = '0';
                    str2[i] = '1';
                }
            else
                str2[i] = str1[i] + 1;
            continue;
        }
        if (!chosen && can_greater &&
            (g[i] < e[i] || (g[i] == e[i] && str1[i] != '?')) &&
            (g[i] < l[i] || !can_less || (g[i] == l[i] && str1[i] != '?'))){
            chosen = chosen_greater = true;
            if (str1[i] == '?')
                if (str2[i] != '?')
                    str1[i] = str2[i] + 1;
                else {
                    str1[i] = '1';
                    str2[i] = '0';
                }
            else
                str2[i] = str1[i] - 1;
            continue;
        }
        if (chosen) {
            if (str1[i] == '?') {
                if (chosen_less)
                    str1[i] = '9';
                else if (chosen_greater)
                    str1[i] = '0';
                else {
                    if (str2[i] != '?')
                        str1[i] = str2[i];
                    else
                        str1[i] = str2[i] = '0';
                }
            }
            if (str2[i] == '?') {
                if (chosen_less)
                    str2[i] = '0';
                else if (chosen_greater)
                    str2[i] = '9';
                else
                    str2[i] = str1[i];

            }
        } else {
            if (str1[i] != '?')
                str2[i] = str1[i];
            if (str2[i] != '?')
                str1[i] = str2[i];
            if (str1[i] == '?')
                str1[i] = str2[i] = '0';
        }
    }
    /*
    cout << endl;
    for (int i = 0; i < str1.size(); ++i) {
        cout << l[i] << ' ' << e[i] << ' ' << g[i] << endl;
    }
    */
    cout << str1 << ' ' << str2;
}

int min_dif;
string s1, s2;

int stoi(const string &s) {
    int result = 0;
    for (int i = 0; i < s.size(); ++i) {
        result *= 10;
        result += s[i] - '0';
    }
    return result;
}

void gen2(int cur) {
    if (cur == str2.size()) {
        if (abs(stoi(str1) - stoi(str2)) < min_dif) {
            min_dif = abs(stoi(str1) - stoi(str2));
            s1 = str1;
            s2 = str2;
        }
        return;
    }
    if (str2[cur] == '?') {
        for (int i = 0; i < 10; ++i) {
            str2[cur] = '0' + i;
            gen2(cur + 1);
        }
        str2[cur] = '?';
    } else
        gen2(cur + 1);
}

void gen1(int cur) {
    if (cur == str1.size()) {
        gen2(0);
        return;
    }
    if (str1[cur] == '?') {
        for (int i = 0; i < 10; ++i) {
            str1[cur] = '0' + i;
            gen1(cur + 1);
        }
        str1[cur] = '?';
    } else
        gen1(cur + 1);
}

void solve2() {
    min_dif = 100000;
    gen1(0);
    cout << s1 << ' ' << s2;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> str1 >> str2;
        cout << "CASE #" << i << ": ";
        solve2();
        cout << endl;
    }
    return 0;
}
