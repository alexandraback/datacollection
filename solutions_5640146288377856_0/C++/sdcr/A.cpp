#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstdlib>

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)


int mod1 = int(1e9) + 7;

int main(){
    cout.precision(9);

	int T;
	cin >> T;

    for1(cas,T) {
        cout << "Case #" << cas << ": ";

        ll r,c,w;
        cin >> r >> c >> w;

        ll ans = r*(c/w) + w - 1;

        if((c)%w != 0)
            ans++;

        cout << ans << endl;
	}

	return 0;
}
