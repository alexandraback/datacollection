#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstring>
#include <map>
#include <fstream>
using namespace std;

vector<string> words;
map<int, vector<int> > dict;

int dp[4000][6];
string input;
int N;

typedef pair<int, int> pii;

int getHash(const string& s, int star) {
    int n = int(s.size());
    int hash = 0;
    for (int i = 0; i < n && i < 5; ++i) {
        int num = 26;
        if (star != i) {
            num = int(s[i] - 'a');
        }
        hash = hash * 27 + num;
    }
    return hash;
}

int getInputHash(int ind, int len, int star) {
    int hash = 0;
    for (int i = 0; i < len; ++i) {
        int num = 26;
        if (star != i) {
            num = int(input[ind + i] - 'a');
        }
        hash = hash * 27 + num;
    }
    return hash;
}

void addToDict(string s, int ind) {
    int n = int(s.size());
    int hash = getHash(s, -1);
    dict[hash].push_back(ind);
    for (int star = 0; star < 5 && star < n; ++star) {
        int hash = getHash(s, star);
        dict[hash].push_back(ind);
    }
}

void readDict() {
    ifstream fin("dict.txt");
    string s;
    while (fin >> s) {
        words.push_back(s);
        int ind = int(words.size() - 1);
        addToDict(s, ind);
    }
}

pii tryout(int ind, int w, int last) {
    if (ind + int(words[w].size()) > N) return pii(-1, -1);
    int prev = -last;
    int done = 0;
    for (int i = 0; i < int(words[w].size()); ++i) {
        if (input[ind + i] != words[w][i]) {
            if (i - prev < 5) {
                return pii(-1, -1);
            }
            prev = i;
            ++done;
        }
    }
    int newlast = int(words[w].size()) - prev;
    if (newlast > 5) newlast = 5;
    return pii(done, newlast);
}

int f(int ind, int last) {
    if (dp[ind][last] != -1) {
        return dp[ind][last];
    }
    if (ind >= N) {
        dp[ind][last] = 0;
        return 0;
    }
    int ret = -2;
    for (int len = 1; len <= 5; ++len) {
        if (ind + len > N) break;
        for (int star = -1; star < len; ++ star) {
            int hash = getInputHash(ind, len, star);
            for (int i = 0; i < int(dict[hash].size()); ++i) {
                int w = dict[hash][i];
                pii res = tryout(ind, w, last);
                if (res.first != -1) {
                    int temp = f(ind + int(words[w].size()), res.second);
                    if (temp != -2) {
                        temp += res.first;
                        if (ret == -2 || temp < ret) {
                            ret = temp;
                        }
                    }
                }
            }
        }
    }
    dp[ind][last] = ret;
    return ret;
}

void solve(int test) {
    cin >> input;
    N = int(input.size());
    memset(dp, -1, sizeof dp);
    int ret = f(0, 5);
    cout << "Case #" << test << ": " << ret << "\n";
}

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    readDict();
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        solve(test);
    }
    return 0;
}
