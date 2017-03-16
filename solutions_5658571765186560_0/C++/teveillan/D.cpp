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

bool solve(int x, int w, int h) {
    if(w>h) swap(w, h);
    if(w * h % x != 0)  return 0;
    if(x > max(w, h))   return 0;
    if(x == 4 && w == 2 && h == 3)  return 0;
    if(x ==3 && (h < 2))   return 0;
    if(x == 4 && (h < 3 || 2 < 2))  return 0;
    return 1;
}


int main() {
    freopen("D-small-attempt1.in", "r", stdin);
    freopen("small-out", "w", stdout);
    int casnum, casid = 0;
    cin >> casnum;
    while(casnum--) {
        int x, w, h;
        scanf("%d%d%d", &x, &w, &h);
        string yes = "GABRIEL", no = "RICHARD";
        bool ans = 0;
        if(x == 1)  ans = 1;
        else if(x == 2) ans = (w * h % 2 == 0);
        else if(x >= 4) ans = 0;
        else {
            if(w % 3 == 0 && h % 2 == 0)    ans = 1;
            else if(w % 2 == 0 && h % 3 == 0)   ans = 1;
            else ans = 0;
        }
        printf("Case #%d: ", ++casid);
        if(ans) cout << yes << endl;
        else cout << no << endl;
    }
    return 0;
}

