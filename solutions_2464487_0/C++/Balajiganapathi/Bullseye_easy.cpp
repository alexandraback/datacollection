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

int main() {
    //freopen("sample.txt", "r", stdin); freopen("output.txt", "w", stdout);
    freopen("A-small-attempt0.in", "r", stdin); freopen("small0.txt", "w", stdout);
    //freopen("A-large.in", "r", stdin); freopen("large.txt", "w", stdout);

    int _T;
    scanf("%d", &_T);
    for(int _t = 1; _t <= _T; ++_t) {
        ll r, t, ans = 0;
        cin >> r >> t;
        while(t > 0) {
            t -= (r + 1) * (r + 1) - r * r;
            if(t >= 0) ++ans;
            r += 2;
        }
        
        printf("Case #%d: ", _t);
        cout << ans << endl;
    }

	return 0;
}
