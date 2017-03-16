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

int c[250];

void calc(string s, int kol) {
    for (int i = 0; i < (int)(s.size()); ++i)
        c[s[i]] -= kol;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int ttt;
    cin >> ttt;
    for (int iii = 1; iii <= ttt; ++iii) {
        string s;
        cin >> s;
        for (int i = 0; i < (int)(s.size()); ++i)
            c[s[i]] += 1;
        string ans = "";
        for (int i = 0; i < c['Z']; ++i) {
            ans += "0";
        }
        calc("ZERO", c['Z']);
        for (int i = 0; i < c['G']; ++i) {
            ans += "8";
        }
        calc("EIGHT", c['G']);
        for (int i = 0; i < c['H']; ++i) {
            ans += "3";
        }
        calc("THREE", c['H']);
        for (int i = 0; i < c['T']; ++i) {
            ans += "2";
        }
        calc("TWO", c['T']);
        for (int i = 0; i < c['X']; ++i) {
            ans += "6";
        }
        calc("SIX", c['X']);
        for (int i = 0; i < c['S']; ++i) {
            ans += "7";
        }
        calc("SEVEN", c['S']);
        for (int i = 0; i < c['V']; ++i) {
            ans += "5";
        }
        calc("FIVE", c['V']);
        for (int i = 0; i < c['R']; ++i) {
            ans += "4";
        }
        calc("FOUR", c['R']);
        for (int i = 0; i < c['O']; ++i) {
            ans += "1";
        }
        calc("ONE", c['O']);
        for (int i = 0; i < c['I']; ++i) {
            ans += "9";
        }
        calc("NINE", c['I']);
        sort(ans.begin(), ans.end());
        printf("Case #%d: %s\n", iii, ans.c_str());
    }
    return 0;
}
