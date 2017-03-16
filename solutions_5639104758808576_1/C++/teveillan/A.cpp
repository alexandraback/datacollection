#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

#define FOR(i,l,r)  for(int i=(l); i<=(r); ++i)
#define REP(i,r)    for(int i=0; i<(r); ++i)
#define DWN(i,r,l)  for(int i=(r);i>=(l);--i)

#define pb push_back

typedef long long ll;
typedef pair<int, int>pii;

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int casnum, casid = 0;
    cin >> casnum;
    while(casnum --) {
        int n;
        scanf("%d", &n);
        string str;
        cin >> str;
        int ans = 0, tmp = str[0] - '0';

        FOR(i, 1, n) {
            ans += max(0, i - tmp);
            tmp += max(0, i - tmp) + str[i] - '0';
        }
        printf("Case #%d: %d\n", ++casid, ans);
    }
    return 0;
}

