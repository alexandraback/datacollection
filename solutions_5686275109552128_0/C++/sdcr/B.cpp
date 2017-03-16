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
	for (int cas = 1; cas <= T; ++cas) {

		int d;
		cin >> d;

		multiset<int> pl;

		forn(i,d) {
			int x;
			cin >> x;
			pl.insert(x);
		}

		int spec = 0;
		int mmin = *pl.rbegin();

		while(spec<mmin) {
			spec++;
			int x = *pl.rbegin();
			pl.erase(--pl.end());
			if(x%2 == 1)
				pl.insert(x/2 + 1);
			else
				pl.insert(x/2);
			pl.insert(x/2);
			mmin = min(mmin, spec + *pl.rbegin());
		}

		cout << "Case #" << cas << ": " << mmin << endl;
	}

	return 0;
}
