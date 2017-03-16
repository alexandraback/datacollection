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

int vec[100];

int main() {
    //freopen("in","r",stdin);
    //freopen("out", "w", stdout);
    int t,c,d,v,x;
    cin >> t;
    for(int cas = 1; cas <= t; ++cas)
    {
        memset(vec,0,sizeof(vec));
        vec[0] = 1;
        cin >> c >> d >> v;
        for(int i = 0; i < d; ++i)
        {
            cin >> x;
            for(int j = v; j >= x; --j)
                vec[j] |= vec[j - x];
        }
        int ans = 0;
        for(int i = 1; i <= v; ++i)
        {
            if (vec[i] == 0)
            {
                ++ans;
                for(int j = v; j >= i; --j)
                    vec[j] |= vec[j - i];
            }
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
