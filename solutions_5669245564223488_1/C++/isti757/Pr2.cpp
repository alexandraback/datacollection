#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

long long mod = 1e9+7;

bool can(vector<string> t) {
    for(int i = 0; i < t.size(); i++) {
        t[i].resize(unique(t[i].begin(), t[i].end())-t[i].begin());

        string res = t[i];
        vector<char> was(256, 0);
        for(int i = 0; i < res.size(); i++) {
            if(was[res[i]])
                return false;
            was[res[i]] = true;
        }
    }
    for(int i = 0; i < t.size(); i++) {
        for(int j = 0; j < t.size(); j++) {
            if(i != j) {
                for(int l = 1; l+1 < t[i].size(); l++) {
                    for(int m = 0; m < t[j].size(); m++) {
                        if(t[i][l] == t[j][m])
                            return false;
                    }
                }
            }
        }
    }
    return true;
}

string simple(string s) {
    return string(1, s[0])+""+string(1, s[s.size()-1]);
}

int main() {
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);

    vector<long long> fact(101, 1);
    for(int i = 2; i <= 100; i++) {
        fact[i] = fact[i-1]*i;
        fact[i] %= mod;
    }

    int T;
    cin >> T;
    for(int tt = 1; tt <= T; tt++) {
        printf("Case #%d: ", tt);

        int N;
        cin >> N;

        vector<string> t(N);
        for(int i = 0; i < N; i++) {
            cin >> t[i];
        }

        if(!can(t)) {
            puts("0");
        } else {
            long long res = 1;
            for(int i = 0; i < t.size(); i++)
                t[i] = simple(t[i]);

            for(char c = 'a'; c <= 'z'; c++) {
                vector<string> good, left, right;
                for(int i = 0; i < t.size(); i++) {
                    if(t[i].find(c) != string::npos)
                        if(t[i][0] != t[i][1]) {
                            if(t[i][0] == c)
                                right.push_back(t[i]);
                            else
                                left.push_back(t[i]);
                        }
                        else
                            good.push_back(t[i]);

                }

                if(good.size()+left.size()+right.size() > 0) {
                    if(left.size()+right.size() > 2 || left.size() > 1 || right.size() > 1)
                        res = 0;
                    else {
                        res *= fact[good.size()];
                    }

                    vector<string> nt;
                    for(int i = 0; i < t.size(); i++) {
                        if(t[i].find(c) == string::npos)
                            nt.push_back(t[i]);
                    }

                    if(res != 0) {
                        if(left.size()+right.size() == 1)
                            nt.push_back(left.size() == 1 ? left[0] : right[0]);
                        else if(left.size()+right.size() == 2) {
                            string nbad;
                            nbad.append(1, left[0][0]);
                            nbad.append(1, right[0][1]);
                            if(nbad[0] == nbad[1])
                                res = 0;
                            nt.push_back(nbad);
                        } else {
                            if(left.size()+right.size() == 0)
                                nt.push_back(string(2, c));
                        }
                    }

                    res %= mod;
                    t = nt;
                }
            }

            res *= fact[t.size()];
            res %= mod;

            printf("%d\n", res);
        }
    }

    return 0;
}
