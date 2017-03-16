#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <limits>
#include <iomanip>

#define INF 1000000000
#define Inf 1000000000000000000
#define mp make_pair
#define pb push_back
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int main() {
    //freopen("in","r",stdin);
    //freopen("out", "w", stdout);
    int t,w,r,c;
    cin >> t;
    for(int cas = 1; cas <= t; ++cas)
    {
        cin >> r >> c >> w;
        if (c % w) printf("Case #%d: %d\n",cas, r * (c / w + w));
        else printf("Case #%d: %d\n",cas, r * (c / w + w - 1));
    }
    return 0;
}
