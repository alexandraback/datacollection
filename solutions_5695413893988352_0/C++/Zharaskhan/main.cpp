#include <iostream>
#include <stdio.h>
#include <fstream>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <time.h>
#include <cassert>
#include <map>
#include <set>
#include <stack>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <bitset>

#include <complex>

//#include <unordered_map>
//#include <unordered_set>

#define llong long long int
#define pb push_back
#define mp make_pair
#define pr pair <int, int>
#define X first
#define Y second
#define endl "\n"
using namespace std;
const int MAXN = 1e5 + 7;
//const int INF = 1e9 + 7;
//const llong LINF = 1e18;
//const llong MOD = 1e9 + 7;
//const long double EPS = 1e-18;
using namespace std;
int tests;
vector<int> FIRST, SECOND;

void gen2(string &S, int len, int cur) {
    if (len == S.size()) {
        SECOND.pb(cur);
    } else {
        if (S[len] == '?') {
            for (int i = 0; i <= 9; i++) {
                gen2(S, len + 1, cur * 10 + i);
            }
        } else {
            gen2(S, len + 1, cur * 10 + (S[len] - '0'));
        }
    }
}
void gen1(string &S, int len, int cur) {
    if (len == S.size()) {
        FIRST.pb(cur);
    } else {
        if (S[len] == '?') {
            for (int i = 0; i <= 9; i++) {
                gen1(S, len + 1, cur * 10 + i);
            }
        } else {
            gen1(S, len + 1, cur * 10 + (S[len] - '0'));
        }
    }
}
int main() {
#ifdef DEBUG
    
    double beg = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
#else
    //freopen("centroid.in", "r", stdin);
    //freopen("centroid.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);cin.tie();
    cin >> tests;
    
    for (int test = 1; test <= tests; test++) {
        string C, J;
        cin >> C >> J;
        FIRST.clear();
        SECOND.clear();
        gen1(C, 0, 0);
        gen2(J, 0, 0);
        int ANS = 100000000, FF = -1, SS = -1;
        for (auto i: FIRST) {
            for (auto j: SECOND) {
                if (abs(i - j) < ANS) {
                    ANS = abs(i - j);
                    FF = i;
                    SS = j;
                } else if (abs(i - j) == ANS) {
                    if (i < FF) {
                        FF = i;
                        SS = j;
                    } else if (i == FF) {
                        if (j < SS) {
                            SS = j;
                        }
                    }
                }
            }
        }
        string FFF = "",SSS = "";
        for (int i = 1; i <= C.size(); i++) {
            FFF += '0' + FF % 10;
            SSS += '0' + SS % 10;
            FF /= 10;
            SS /= 10;
        }
        reverse(FFF.begin(), FFF.end());
        reverse(SSS.begin(), SSS.end());
        cout << "Case #" << test << ": " << FFF << ' ' << SSS << endl;
    }
#ifdef DEBUG
    double end = clock();
    fprintf(stderr, "\n*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
    return 0;
}