#define _CRT_SECURE_NO_WARNINGS

#include <cctype>
#include <climits>
#include <cmath>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <numeric>
#include <ratio>
#include <regex>
#include <string>
#include <tuple>
#include <utility>
#include <valarray>

using namespace std;

#define INF ULLONG_MAX
#define MIN LLONG_MIN
#define pi 3.1415926535897932384626433832795

#define sz(v) v.size()
#define pb(x) push_back(x)
#define fill(v,n,x) for(int i=0;i<(int)n;i++) v.push_back(x)
#define FOR(i,n) for(i=0;i<n;i++)
#define re return
#define sum(v) accumulate(v.begin(),v.end(),0)
#define asrt(v) sort(v.begin(),v.end())
#define dsrt(v) sort(v.rbegin(),v.rend())
#define rev(v) reverse(v.begin(),v.end())
#define print(v) for (auto& i:v) cout<<i<<endl
#define print "Case #"+to_string(t1)+": "

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;



int main() {
    freopen("a.in", "r", stdin);
    freopen("a.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t1 = 1; t1 <= T; t1++) {
        int R, C, W;
        cin >> R >> C >> W;
        int s = 0;
        s += (C / W)*R;
        s += W;
        if (C%W == 0) s--;
        cout << print << s << endl;
    }
    getchar();
    return 0;
}

