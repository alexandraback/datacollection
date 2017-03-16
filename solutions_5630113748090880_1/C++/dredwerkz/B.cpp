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

#define SINGLELINE 1
void solve() {
    map<int, int> m;
    map<int, int>::iterator it;
    int n = gi();
    for (int i = 0; i < 2*n-1; i++)
        for (int j = 0; j < n; j++) {
            int x = gi();
            if ((it = m.find(x)) == m.end())
                m[x] = 1;
            else
                it->second++;
        }
    vector<int> v;
    for (it = m.begin(); it != m.end(); it++)
        if (it->second % 2)
            v.push_back(it->first);
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
        printf(" %d", v[i]);
    printf("\n");
}

int main() {
    int t = gi();

    for (int i = 1; i <= t; i++) {
        printf("Case #%d:", i);
        solve();
        fprintf (stderr, "Case %d / %d. Elapsed %.2f. Estimated %.2f\n", i, t, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / i * t) / CLOCKS_PER_SEC);
    }

    return 0;
}
