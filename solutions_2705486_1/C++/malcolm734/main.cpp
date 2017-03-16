#include <iostream>
#include <sstream>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <string>

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>

#include <algorithm>
#include <numeric>

#define foreach(i, x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define sqr(x) ((x) * (x))
#define len(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define endl '\n'
#ifdef CUTEBMAING
#include "cutedebug.h"
#else
#define debug(x) ({})
#endif

using namespace std;

typedef long long int64;
typedef unsigned long long lint;
typedef long double ld;

const int inf = ((1 << 30) - 1);
const int64 linf = ((1ll << 62) - 1);

const char* fin = "input.txt";
const char* fout = "output.txt";
const int cmax = 100500;

vector<string> dict;

int dp[cmax][6], p[cmax][6], pp[cmax][6], df[cmax][6];
string s;

pair<int, int> diff(int pos, const string &cs, int k){
    int ans = 0;
    for (int i = 0; i < len(cs); i++)
        if (cs[i] != s[i + pos]){
            if (k < 5)
                return mp(inf, 0);
            k = 1, ++ans;
        }
        else
            ++k;
    return mp(ans, k);
}

void run(){
    cin >> s;
    for (int i = 0; i <= len(s); i++)
        for (int j = 0; j < 6; j++)
            dp[i][j] = inf;
    dp[0][5] = 0;
    for (int i = 0; i < len(s); i++)
        for (int k = 0; k < 6; k++)
            foreach(j, dict)
                if (dp[i][k] < inf && i + len(*j) <= len(s)){
                    pair<int, int> err = diff(i, *j, k);
                    int nk = (err.sc == -1) ? (min(5, k + len(s))) : min(5, err.sc);
                    if (dp[i + len(*j)][nk] > dp[i][k] + err.fs){
                        dp[i + len(*j)][nk] = dp[i][k] + err.fs, p[i + len(*j)][nk] = j - dict.begin(), pp[i + len(*j)][nk] = p[i][k];
                        df[i + len(*j)][nk] = err.fs;
                    }
                }
    int ans = inf;
    for (int i = 0; i < 6; i++)
        ans = min(ans, dp[len(s)][i]);
    cout << ans << endl;
}

FILE *fdict;

int main(){
    #if !defined STRESS && defined CUTEBMAING
    assert(freopen(fin, "r", stdin));
    assert(fdict = fopen("dict.in", "r"));
    assert(freopen(fout, "w", stdout));
    #endif
    char s[100];
    while (fscanf(fdict, "%s", s) >= 1)
        dict.pb(string(s));
    int t; cin >> t;
    for (int i = 0; i < t; i++){
        cout << "Case #" << i + 1 << ": ";
        run();
        cerr << i + 1 << " OK" << endl;
    }
    return 0;
}
