#pragma comment(linker, "/STACK:640000000")
#include<iostream>
#include<cstdio>
#include<cassert>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<bitset>
#include<algorithm>

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define ll long long
#define bit __builtin_popcountll
#define sqr(x) (x) * (x)
#define forit(it,S) for(__typeof((S).begin()) it = (S).begin(); it != (S).end(); it++)

using namespace std;

typedef pair<int, int> pii;

const double eps = 1e-9;
const double pi = acos(-1.0);

const int maxn = (int)1e6 + 10;

int res[maxn];

int rev(int x) {
	int r = 0;
	while(x) {
		r *= 10;
		r += x % 10;
		x /= 10;
	}
	return r;
}

void stupid() {
	int n; cin >> n;
	cout << res[n] << endl;	
}

int main() {
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	for (int i = 1; i < maxn; i++) {
		res[i] = i;
	}

	for (int i = 1; i < maxn - 1; i++) {
		res[i + 1] = min(res[i + 1],res[i] + 1);
		int r = rev(i);		
 		if (r <= i || r >= maxn) continue;
 		res[r] = min(res[r],res[i] + 1); 		
	}

	int Cases; cin >> Cases;

	for (int Case = 1; Case <= Cases; Case++) {
		printf("Case #%d: ",Case);
		stupid();
	}
	
	return 0;
}
