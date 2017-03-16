#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <iterator>
#include <queue>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> point;
typedef pair<pll, pll> seg;
typedef vector<int> lnum;

const int N = (int)(1e6) + 7;
const int M = (int)(1e6) + 7;
const int K = (int)(1e4) + 7;
const int BLOCK_SIZE = 320;
const ld eps = 1e-9;
const ll INF = (ll)(1e9) + 7;
const ll MOD = (ll)(1e9) + 7;

string s1, s2, a1, a2;

ll rz = -1, ans1, ans2;
ll rz1 = -1, aa1, aa2;

ll qabs(ll q) {
    if (q < 0)
        return -q;
    return q;
}

void rec(int ind, ll ch1, ll ch2) {
    if (ind == s1.size()) {
        if (rz == -1 || qabs(ch1 - ch2) < rz || (qabs(ch1 - ch2) == rz && ch1 < ans1) || (qabs(ch1 - ch2) == rz && ch1 == ans1 && ch2 < ans2)) {
            rz = qabs(ch1 - ch2);
            ans1 = ch1;
            ans2 = ch2;
        }
        return ;
    }
    if (s1[ind] == '?' && s2[ind] == '?') {
        rec(ind + 1, ch1 * 10 + 0, ch2 * 10 + 0);
        rec(ind + 1, ch1 * 10 + 9, ch2 * 10 + 0);
        rec(ind + 1, ch1 * 10 + 0, ch2 * 10 + 9);
        return ;
    }
    if (s1[ind] != '?' && s2[ind] != '?') {
        rec(ind + 1, ch1 * 10 + s1[ind] - '0', ch2 * 10 + s2[ind] - '0');
        return ;
    }
    if (s1[ind] == '?') {
        for (int k = -1; k <= 1; ++k) {
            int q = s2[ind] - '0';
            q = (q + k + 10) % 10;
            rec(ind + 1, ch1 * 10 + q, ch2 * 10 + s2[ind] - '0');
        }
        return ;
    }
    if (s2[ind] == '?') {
        for (int k = -1; k <= 1; ++k) {
            int q = s1[ind] - '0';
            q = (q + k + 10) % 10;
            rec(ind + 1, ch1 * 10 + s1[ind] - '0', ch2 * 10 + q);
        }
    }
}

string preo(ll q) {
    string ans = "";
    while (q) {
        ans += (q % 10) + '0';
        q /= 10;
    }
    reverse(ans.begin(), ans.end());
    while (ans.size() != s1.size())
        ans = "0" + ans;
    return ans;
}

ll toll(string s) {
    ll res = 0;
    for (int i = 0; i < s.size(); ++i)
        res = res * 10 + s[i] - '0';
    return res;
}

void prov(string q1, string q2) {
    bool f = 0;
    for (int i = 0; i < s1.size(); ++i)
        if (s1[i] == '?')
            continue;
        else if (s1[i] != q1[i]) {
            f = 1;
            break;
        }
    for (int i = 0; i < s2.size(); ++i)
        if (s2[i] == '?')
            continue;
        else if (s2[i] != q2[i]) {
            f = 1;
            break;
        }
    if (f)
        return ;
    ll q = toll(q1), w = toll(q2);
    if (rz1 == -1 || qabs(q - w) < rz1 || (qabs(q - w) == rz1 && q < aa1) || (qabs(q - w) == rz1 && q == aa1 && w < aa2)) {
        rz1 = qabs(q - w);
        aa1 = q;
        aa2 = w;
    }
}

void solve() {
    for (char i = '0'; i <= '9'; ++i)
        for (char j = '0'; j <= '9'; ++j)
            if (s1.size() == 1) {
                string ss1 = "", ss2 = "";
                ss1 += i;
                ss2 += j;
                prov(ss1, ss2);
            } else {
                for (char ii = '0'; ii <= '9'; ++ii)
                    for (char jj = '0'; jj <= '9'; ++jj)
                        if (s1.size() == 2) {
                            string ss1 = "", ss2 = "";
                            ss1 += i;
                            ss1 += ii;
                            ss2 += j;
                            ss2 += jj;
                            prov(ss1, ss2);
                        } else {
                            for (char iii = '0'; iii <= '9'; ++iii)
                                for (char jjj = '0'; jjj <= '9'; ++jjj) {
                                    string ss1 = "", ss2 = "";
                                    ss1 += i;
                                    ss1 += ii;
                                    ss1 += iii;
                                    ss2 += j;
                                    ss2 += jj;
                                    ss2 += jjj;
                                    prov(ss1, ss2);
                                }
                        }
            }
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int ttt;
    cin >> ttt;
    for (int iii = 1; iii <= ttt; ++iii) {
        cin >> s1 >> s2;
        /*rz = -1;
        rec(0, 0, 0);*/
        rz1 = -1;
        solve();
        printf("Case #%d: %s %s\n", iii, preo(aa1).c_str(), preo(aa2).c_str());
    }
    return 0;
}
