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
const ll upto = ll(1e3);
const int mx = 10000007;

int cnt;
ll num[mx];

bool ok(ll n) {
    ll rev = 0, tmp = n;
    for(; tmp; tmp /= 10) rev = rev * 10 + (tmp % 10);
    
    return rev == n;
}

void pre() {
    for(ll i = 1; i * i <= upto; ++i) if(ok(i) && ok(i * i)) num[cnt++] = i * i;
    //cerr << upto << " " << cnt << endl;
    //fr(i, cnt) cerr << num[i] << " " << (int)sqrt(num[i]) << endl;
}

int main() {
    //freopen("sample.txt", "r", stdin); freopen("output.txt", "w", stdout);
    freopen("C-small-attempt0.in", "r", stdin); freopen("small0.txt", "w", stdout);
    //freopen("C-large.in", "r", stdin); freopen("large.txt", "w", stdout);
    
    pre();
    
    int _T;
    scanf("%d", &_T);
    for(int _t = 1; _t <= _T; ++_t) {
        ll a, b;
        cin >> a >> b;
        int ans = upper_bound(num, num + cnt, b) - lower_bound(num, num + cnt, a);
        printf("Case #%d: %d\n", _t, ans);
    }

	return 0;
}
