#pragma comment(linker, "/STACK:64000000")
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair < int, int >
#define pll pair < long long, long long>
#define ull unsigned long long
#define y1 stupid_cmath
#define left stupid_left
#define right stupid_right
#define vi vector <int>
#define sz(a) (int)a.size()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))

const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);

int T;
string s;
int prev[27][2020];
char ans[2020];
int l, r;

void rec(int ind) {
    if (ind < 0) return;
    for (int i = 25; i >= 0; i--) {        
        if (prev[i][ind] != -1) {
            ans[l++] = (char)(i + 'A');
            for (int j = ind; j > prev[i][ind]; j--)
                ans[r--] = s[j];
            rec(prev[i][ind] - 1);
            break;;
        }
    }
}

void solve(int case_num) {
    getline(cin, s);
    int n = sz(s);
    for (int i = 0; i < 26; i++) prev[i][0] = -1;
    prev[s[0] - 'A'][0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 26; j++) prev[j][i] = prev[j][i - 1];
        prev[s[i] - 'A'][i] = i;
    }
    l = 0;
    r = n - 1;
    rec(n - 1);
    printf("Case #%d: ", case_num);
    for (int i = 0; i < n; i++)
        printf("%c", ans[i]);
    printf("\n");
}

int main(){

    scanf("%d\n", &T);

    for (int i = 1; i <= T; i++) {
        solve(i);
    }

    return 0;
}
