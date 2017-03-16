#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <bitset>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
 
using namespace std;

#define MAX 1000008
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
#define pi(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
#define all(c) c.begin(), c.end()
#define MOD 1000000007
#define M_PI 3.14159265358979323846
#define mp make_pair
#define F first
#define S second
#define INF 0x3f3f3f3f
#define INT_MAX 2147483647
#define pb push_back
#define read freopen("in.txt","r",stdin)
#define write freopen("out.txt","w",stdout)
#define itr(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> lli;
typedef pair<int,pii> i3;
 
void solve(int t) {
    int n;
    cin >> n;
    int arr[3005];
    for (int i = 0; i < 2800; i++) {
        arr[i] = 0;
    }
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            arr[x]++;
        }
    }
    cout << "Case #" << t << ": ";
    for (int i = 0; i < 2800; i++) {
        if (arr[i] % 2 != 0) {
            cout << i << " ";
        }
    }
    cout << "\n";
}
 
int main() {
    read; write;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}
