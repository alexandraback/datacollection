#define DBG 1

#include <cstring>
#include <map>
#include <unordered_map>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> pii;

int gi() {
    int a;
    scanf("%d", &a);
    return a;
}

ll gli() {
    ll a;
    scanf("%lld", &a);
    return a;
}

char cc[12];
int cv[12];
char a[2004];

string s[12];

#define SINGLELINE 1
void solve() {
    unordered_map<char, int> m;
    scanf("%s", a);

    vector<int> vv;

    for (int i = 0; i < 10; i++)
        m[cc[i]] = 0;

    int l = strlen(a);
    for (int i = 0; i < l; i++)
        m[a[i]]++;

    for (int i = 0; i < 10; i++) {
        while (m[cc[i]]) {
            int v = cv[i];
            vv.push_back(v);
            for (int j = 0; j < s[v].size(); j++)
                m[s[v][j]]--;
        }
    }

    sort(vv.begin(), vv.end());
    for (int i = 0; i < vv.size(); i++)
        printf("%d", vv[i]);
    printf("\n");
}

int main() {
    int t = gi();

    s[0] = "ZERO";
    s[1] = "ONE";
    s[2] = "TWO";
    s[3] = "THREE";
    s[4] = "FOUR";
    s[5] = "FIVE";
    s[6] = "SIX";
    s[7] = "SEVEN";
    s[8] = "EIGHT";
    s[9] = "NINE";

    cc[0] = 'Z'; cv[0] = 0; 
    cc[1] = 'G'; cv[1] = 8; 
    cc[2] = 'X'; cv[2] = 6; 
    cc[3] = 'S'; cv[3] = 7; 
    cc[4] = 'V'; cv[4] = 5; 
    cc[5] = 'F'; cv[5] = 4; 
    cc[6] = 'W'; cv[6] = 2; 
    cc[7] = 'H'; cv[7] = 3; 
    cc[8] = 'O'; cv[8] = 1; 
    cc[9] = 'I'; cv[9] = 9; 

    for (int i = 1; i <= t; i++) {
        printf("Case #%d:%c", i, (SINGLELINE ? ' ' : '\n'));
        solve();
        fprintf (stderr, "Case %d / %d. Elapsed %.2f. Estimated %.2f\n", i, t, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / i * t) / CLOCKS_PER_SEC);
    }

    return 0;
}
