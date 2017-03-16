#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <climits>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <complex>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define repa(i,s,e) for(int i=s; i<=e; i++)
#define repd(i,s,e) for(int i=s; i>=e; i--)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;

int T;
string L, U;
vector<vector<string> > V(52);

bool LT(string s1, string s2) {
    int l = s1.size();
    if(l != s2.size()) return l < s2.size();
    rep(i,l) {
        if(s1[i] != s2[i]) return (s1[i] - '0') < (s2[i] - '0');
    }
    return false;
}

bool LEQ(string s1, string s2) {
    int l = s1.size();
    if(l != s2.size()) return l < s2.size();
    rep(i,l) {
        if(s1[i] != s2[i]) return (s1[i] - '0') < (s2[i] - '0');
    }
    return true;
}


string SQ(string s) {
    int l1 = s.size();
    int l2 = l1 << 1;
    string res(l2, '0');
    rep(dig,l2) {
        int sum = 0;
        for(int i=0; i<l1; i++) {
            int j = dig - i;
            if(j < 0 || j >= l1) continue;
            res[l2-dig-1] += (s[i]- '0') * (s[j]- '0');
        }
    }

    if(res[0] == '0') res = res.substr(1);
    return res;
}

bool check(string s) {
    int sum = 0;
    int length = s.size();
    rep(i,length) {
        int n = s[i] - '0';
        sum += n * n;
    }
    return sum < 10;
}

void solve() {
    V[1].push_back("1");
    V[1].push_back("2");
    V[1].push_back("3");
    V[2].push_back("11");
    V[2].push_back("22");
    repa(i,3,51) { // even number
        if(i % 2 == 0) {
            int prev = V[i-1].size();
            rep(k,prev) {
                string s = V[i-1][k].substr(0, i/2) + V[i-1][k][i/2-1] + V[i-1][k].substr(i/2);
                if(check(s)) {
                    // cout << s << " -> " << SQ(s) << endl;
                    V[i].push_back(s);
                }
            }
        } else { // odd number
            int prev = V[i-1].size();
            rep(k,prev) {
                for(char c='0'; c<='2'; c++) {
                    string s = V[i-1][k].substr(0, i/2) + c + V[i-1][k].substr(i/2);
                    if(check(s)) {
                        // cout << s << " -> " << SQ(s) << endl;
                        V[i].push_back(s);
                    }
                }
            }
        }
    }
}

int main() {
    solve();

    cin >> T;
    repa(t,1,T) {
        cin >> L >> U;
        int dL = (L.size() + 1) / 2;
        int dU = (U.size() + 1) / 2;
        ll total = 0LL;
        repa(i,dL,dU-1) {
            total += V[i].size();
        }

        rep(i,V[dU].size()) {
            if(LEQ(SQ(V[dU][i]), U)) total++;
        }

        rep(i, V[dL].size()) {
            if(LT(SQ(V[dL][i]), L)) total--;
        }
        printf("Case #%d: %lld\n", t, total);
    }
}
