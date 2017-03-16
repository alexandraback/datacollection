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

		int x, r, c;
		cin >> x >> r >> c;

		bool ok = false;
		int p = r*c;

		if(2<=x && x<=6) {
			if(p % x) ok = true;
			else {
				if(r<x && c<x) ok = true;
				else {
					if(c<r) swap(c,r);
					if(x<5 && r<x-1) ok = true;
					if(x==5 && r<3 || (r==3 && c==5)) ok = true;
					if(x==6 && r<=3) ok = true;
				}
			}
		}

		if(7<=x) ok = true;

		cout << "Case #" << cas << ": " << (ok? "RICHARD" : "GABRIEL") << endl;
	}

	return 0;
}
