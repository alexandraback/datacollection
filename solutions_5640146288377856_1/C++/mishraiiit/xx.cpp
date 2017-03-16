//mishraiiit
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define fastScan ios_base::sync_with_stdio(0); cin.tie(NULL);
#define foreach(v, c) for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
typedef pair <ll, ll> pll;

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

int main() {

    fastScan;

    ll t;
    cin >> t;

    ll id = 0;

    while(t--) {
      id++;
      ll r, c, w;
      cin >> r >> c >> w;
      cout << "Case #" << id << ": " << ((r * (c/w) + ((c%w) != 0)) + w - 1) << endl;
    }

    return 0;
}
