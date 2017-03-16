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
string dig[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
map <string, string> ans;
void gen(string st, int last, string S) {
    if (st.length() > 20) {
        return;
    }
   // cerr << st <<  ' ' << S<< '\n';
    string tmp = st;
    sort(tmp.begin(), tmp.end());
    ans[tmp] = S;
    for (int i = last; i <= 9; i++) {
        gen(st + dig[i], i, S + char(i + '0'));
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
    gen("", 0, "");
    for (int test = 1; test <= tests; test++) {
        string st;
        cin >> st;
        sort(st.begin(), st.end());
        cout << "Case #" << test << ": " << ans[st] << endl;
    }
#ifdef DEBUG
    double end = clock();
    fprintf(stderr, "\n*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
    return 0;
}