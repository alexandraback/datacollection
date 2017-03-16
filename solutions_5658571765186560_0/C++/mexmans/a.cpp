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

bool solve() {
	int x,r,c; cin >> x >> r >> c;
	if ((x + 1) / 2 > min(r,c) || x > max(r,c) || r * c % x != 0 || x >= 7) return false;
	return true;
}

int main() {
	#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int Cases; cin >> Cases; 

	for (int Case = 1; Case <= Cases; Case++) {
		printf("Case #%d: ",Case);
		puts(solve() ? "GABRIEL" : "RICHARD");
	}
	
	return 0;
}
