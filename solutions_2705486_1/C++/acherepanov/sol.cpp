#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_set>
#include <set>

using namespace std;

unordered_set<long long> dict;

long long toNum (string const & s) {
    long long res = 0, d = 1;
    for (int i = 0; i < (int)s.size(); ++i, d *= 27) {
        res += (s[i] - 'a' + 1) * d;
    }
    return res;
}

void loadDict () {
    ifstream in;
    in.open("dict.txt", ios::in);
    
    dict.clear();
    string s;
    int maxLen = 0;
    while (in >> s) {
        dict.insert(toNum(s));
        maxLen = max<int>(maxLen, s.size());
    }
    // cout << "maxLen: " << maxLen << "\n";
}

const int N = 4e3 + 10;
const int K = 5;
const int L = 10;

int dp[N][K];
const int INF = 1e9;

char calculated[N][L + 1][L][L];

bool exists (string const & s) {
    return dict.find(toNum(s)) != dict.end();
}


void init () {
    memset(calculated, -1, sizeof(calculated));
}

int sol (string s) {
    init();
    int n = s.size();
    
    for (int i = 0; i < K; ++i) {
        dp[n][i] = 0;
    }
    
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < K; ++j) {
            int & r = dp[i][j];
            r = INF;
            
            for (int len = 1; len <= L && i + len <= n; ++len) {
                string t = s.substr(i, len);
                if (exists(t)) {
                    r = min(r, dp[i + len][max(j - len, 0)]);
                }
                
                for (int e1 = j; e1 < len; ++e1) {
                    for (char c1 = 'a'; c1 <= 'z'; ++c1) {
                        if (c1 == s[i + e1]) {
                            continue;
                        }
                        
                        t[e1] = c1;
                        if (exists(t)) {
                            r = min(r, dp[i + len][max(e1 + K - len, 0)] + 1);
                        }
                        t[e1] = s[i + e1];
                    }
                }
            }
            
            
            
            for (int len = 1; len <= L && i + len <= n; ++len) {
                string t = s.substr(i, len);
                
                for (int e1 = j; e1 < len; ++e1) {
                    for (int e2 = e1 + K; e2 < len; ++e2) {
                        bool found = false;
                        if (calculated[i][len][e1][e2] != -1) {
                            found = ((calculated[i][len][e1][e2] == 0) ? 0 : 1);
                        }
                        else {
                            for (char c1 = 'a'; !found && c1 <= 'z'; ++c1) {
                                if (c1 == s[i + e1]) {
                                    continue;
                                }
                                t[e1] = c1;
                                for (char c2 = 'a'; !found && c2 <= 'z'; ++c2) {
                                    if (c2 == s[i + e2]) {
                                        continue;
                                    }
                                    
                                    t[e2] = c2;
                                    if (exists(t)) {
                                        found = true;
                                    }
                                    t[e2] = s[i + e2];
                                }
                                t[e1] = s[i + e1];
                            }
                        }
                        calculated[i][len][e1][e2] = (found ? 1 : 0);
                        if (found) {
                            r = min(r, dp[i + len][max(e2 + K - len, 0)] + 2);
                        }
                        
                    }
                }
            }
        }
    }
    
    return dp[0][0];
}

void sol (int testNum) {
    string s;
    cin >> s;
    cout << "Case #" << testNum + 1 << ": " << sol(s) << "\n";
}

int main () {
    loadDict();
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        sol(i);
        cerr << (double)clock() / CLOCKS_PER_SEC << "\n";
    }
    return 0;
}
