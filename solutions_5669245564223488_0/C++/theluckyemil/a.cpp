#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>

#define ll long long
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int maxn = 205;
const int md = 1e9+7;

string a[maxn];
pair<char, char> b[maxn];
vector<int> used(26, 0);

int check(string & s) {
    vector<char> v;
    v.push_back(s[0]);
    for (int i=0; i<s.size()-1; i++) {
        if (s[i] != s[i+1]) {
            v.push_back(s[i + 1]);
        }
    }
    vector<int> ws(26, 0);
    for (int i=0; i<v.size(); i++) {
        int x = v[i] - 'a';
    //    cerr << x << "\n";
        if (ws[x] || used[x]) return 0;
        ws[x] = 1;
        if (i > 0 && i < v.size() - 1) {
            used[x] = 1;
        }
    }
    return 1;
}

int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int test; cin >> test;
    for (int it=0; it<test; it++) {
        int n; cin >> n;
        int ok = 1;

            used.assign(26, 0);
        for (int i=0; i<n; i++) {
            string s;
            cin >> s;
            b[i].first = s[0];
            int sz = s.size();
            b[i].second = s[sz - 1];
            if (used[b[i].first - 'a'] || used[b[i].second - 'a']) {
                ok = 0;
                break;
            }
            int v = check(s);
            if (!v) {
                ok = 0;
                break;
            }
        }
      //  cout << used[1] << "\n";
        if (!ok) {
            printf("Case #%d: 0\n", it+1);
        } else {
            int ans = 0;
            vector<int> p(n);
            for (int i=0; i<n; i++) p[i]=i;
            do {
                ok = 1;
                vector<int> ws(26, 0);
                string res;
                for (int i=0; i<n; i++) {
                    int id = p[i];
                    res.push_back(b[id].first);
                    res.push_back(b[id].second);
                    //res += a[id];
                }

                ws[res[0] - 'a'] = 1;
                for (int i=0; i<(int)res.size()-1; i++) {
                    if (res[i] != res[i+1]) {
                        if (ws[res[i + 1] - 'a']) {
                            ok = 0;
                            break;
                        } else {
                            ws[res[i + 1] - 'a'] = 1;
                        }
                    }
                }
                if (ok) {
                    ans++;
                }
            } while (next_permutation(p.begin(), p.end()));
            printf("Case #%d: %d\n", it+1, ans);
        }
    }
    return 0;
}
