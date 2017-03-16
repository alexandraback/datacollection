//Coder: Balajiganapathi

#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;

// Basic macros

#define st          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define fr(i,n)     re(i,0,n)
#define tr(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (int)(x.size())

const int oo = 2000000009;

int dp[50][100], E, R, n;
int v[50];

int solve(int e, int i) {
    if(i == n) return 0;
    int &ret = dp[e][i];
    if(ret != -1) return ret;
    ret = 0;
    
    fr(cur, e + 1) ret = max(ret, cur * v[i] + solve(min(E, e - cur + R), i + 1));
    
    return ret;
}

int main() {
    //freopen("sample.txt", "r", stdin); freopen("output.txt", "w", stdout);
    freopen("B-small-attempt1.in", "r", stdin); freopen("small1.txt", "w", stdout);
    //freopen("B-large.in", "r", stdin); freopen("large.txt", "w", stdout);

    int _T;
    scanf("%d", &_T);
    for(int _t = 1; _t <= _T; ++_t) {
        scanf("%d %d %d", &E, &R, &n);
        fr(i, n) scanf("%d", v+i);
        ini(dp, -1);        
        printf("Case #%d: %d\n", _t, solve(E, 0));
    }

	return 0;
}
