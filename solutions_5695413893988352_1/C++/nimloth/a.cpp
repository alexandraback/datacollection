#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
#include<deque>
#include<cmath>
#include<ctime>
#include<stack>

using namespace std;

long long strToInt(string s) {
    long long ans = 0;
    for (int i = 0; i < s.length(); ++i) {
        ans = ans * 10 + s[i];
    }
    return ans;
}

pair<string, string> getBest(string c, string j, int cur, int flag) {
    if (cur == c.length()) {
        return make_pair(c, j);
    }
    for (int i = cur; i < c.length(); ++i) {
        if (c[i] == '?' && j[i] == '?') {
            if (flag == 0) {
                c[i] = j[i] = '0';
                pair <string, string> a = getBest(c, j, i, 0);
                c[i] = '0'; j[i] = '1';
                pair <string, string> b = getBest(c, j, i, 2);
                c[i] = '1'; j[i] = '0';
                pair <string, string> d = getBest(c, j, i, 1);
                long long a1 = abs(strToInt(a.first) - strToInt(a.second));
                long long b1 = abs(strToInt(b.first) - strToInt(b.second));
                long long d1 = abs(strToInt(d.first) - strToInt(d.second));
                long long m = min(min(a1, b1), d1);
                if (a1 == m) {
                    c = a.first;
                    j = a.second;
                    return make_pair(c, j);
                } else {
                    if (b1 == m) {
                        c = b.first;
                        j = b.second;
                        return make_pair(c, j);
                    } else {
                        c = d.first;
                        j = d.second;
                        return make_pair(c, j);
                    }
                }
            } else {
                if (flag == 1) {
                    c[i] = '0';
                    j[i] = '9';
                } else {
                    c[i] = '9';
                    j[i] = '0';
                }
            }
        } else {
            if (c[i] == '?' && j[i] != '?') {
                if (flag == 0) {
                    c[i] = j[i];
                    pair <string, string> a = getBest(c, j, i, 0);
                    if (j[i] - 1 >= '0')
                        c[i] = j[i] - 1;
                    else c[i] = j[i];
                    pair <string, string> b = getBest(c, j, i, 2);
                    if (j[i] + 1 <= '9')
                        c[i] = j[i] + 1;
                    else c[i] = j[i];
                    pair <string, string> d = getBest(c, j, i, 1);
                    long long a1 = abs(strToInt(a.first) - strToInt(a.second));
                    long long b1 = abs(strToInt(b.first) - strToInt(b.second));
                    long long d1 = abs(strToInt(d.first) - strToInt(d.second));
                    long long m = min(min(a1, b1), d1);
                    if (b1 == m) {
                        c = b.first;
                        j = b.second;
                        return make_pair(c, j);
                    } else {
                        if (a1 == m) {
                            c = a.first;
                            j = a.second;
                            return make_pair(c, j);
                        } else {
                            c = d.first;
                            j = d.second;
                            return make_pair(c, j);
                        }
                    }
                } else {
                    if (flag == 1) {
                        c[i] = '0';
                    } else {
                        c[i] = '9';
                    }
                }
            } else {
                if (c[i] != '?' && j[i] == '?') {
                    if (flag == 0) {
                        j[i] = c[i];
                        pair <string, string> a = getBest(c, j, i, 0);
                        if (c[i] - 1 >= '0')
                            j[i] = c[i] - 1;
                        else j[i] = c[i];
                        pair <string, string> b = getBest(c, j, i, 1);
                        if (c[i] + 1 <= '9')
                            j[i] = c[i] + 1;
                        else j[i] = c[i];
                        pair <string, string> d = getBest(c, j, i, 2);
                        long long a1 = abs(strToInt(a.first) - strToInt(a.second));
                        long long b1 = abs(strToInt(b.first) - strToInt(b.second));
                        long long d1 = abs(strToInt(d.first) - strToInt(d.second));
                        long long m = min(min(a1, b1), d1);
                        if (b1 == m) {
                            c = b.first;
                            j = b.second;
                            return make_pair(c, j);
                        } else {
                            if (a1 == m) {
                                c = a.first;
                                j = a.second;
                                return make_pair(c, j);
                            } else {
                                c = d.first;
                                j = d.second;
                                return make_pair(c, j);
                            }
                        }
                    } else {
                        if (flag == 1) {
                            j[i] = '9';
                        } else {
                            j[i] = '0';
                        }
                    }
                } else {
                    if (flag == 0) {
                        if (c[i] > j[i]) flag = 1;
                        if (c[i] < j[i]) flag = 2;
                    }
                }
            }
        }
    }
    return make_pair(c, j);
}

int main() {
    freopen("B-large (2).in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cout << "Case #" << t + 1 << ": ";
        string c, j;
        cin >> c >> j;
        pair <string, string> ans = getBest(c, j, 0, 0);
        cout << ans.first << " " << ans.second;
        cout << "\n";
    }
    return 0;
}