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

int s[1010];

int main(){
    cout.precision(9);

	int T;
	cin >> T;
	for (int cas = 1; cas <= T; ++cas) {

		int n;
		cin >> n;

		string sh;
		cin >> sh;

		int ans = 0;
		int st = sh[0] - '0';

		for1(i, n) {
			int x = sh[i] - '0';
			ans += max(i-st, 0);
			st += x + max(i-st, 0);
		}

		cout << "Case #" << cas << ": " << ans << endl;
	}

	return 0;
}
