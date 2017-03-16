#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <cmath>

#define forn(i, n) for(int i=0;i<n;++i)
#define for1(i, n) for(int i=1;i<=n;++i)
#define forv(i, v) for(int i=0;i<v.size();++i)
#define sz(v) int(v.size())
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define ft first
#define sc second
#define pt pair<int, int>

typedef long long li;
typedef long double ld;


using namespace std;

const int N = 1000 + 13, INF = 1000*1000*1000;
const ld  eps = 1e-9;

string a[N];
string b[N];
bool us[N];
char buf[N];
int n;

int calc() {
	memset(us, false, sizeof us);
	int ans = 0;
	for(int i = n - 1; i >= 0; i--) {
		int idx = -1;
		forn(j, n)
			if (!us[j]) {
				idx = j;
				break;
			}
		forn(j, n) {
        	if (!us[j] && a[i] < b[j]) {
        		idx = j;
        		break;
        	}	
        }
        if (a[i] > b[idx]) {
			ans++;
        }
        us[idx] = true;
	}
	return ans;
}

bool solve(int test) {

	scanf("%d ", &n);
	forn(i, n) {
		scanf("%s ", buf);
		a[i] = string(buf);
	}
	forn(i, n) {
		scanf("%s ", buf);
		b[i] = string(buf);
	}

	sort(a, a + n);
	sort(b, b + n);

	int warAns = calc();
	swap(a, b);
	int dWarAns = n - calc();
	printf("Case #%d: ", test + 1);
	printf("%d %d\n", dWarAns, warAns);

	return false;
}

int main () {	
#ifdef IKAR
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	forn(i, n)
		solve(i);

	return 0;
}