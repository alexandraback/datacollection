#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <climits>
#include <cstring>

#define pb push_back
#define po pop_back

#define mp make_pair

#define NMax 1000005
#define inf 40000000

using namespace std;

ifstream f("input");
ofstream g("output");

int memo[NMax];
int target;

int flip(int x) {
	int flipped = 0;
	
	while (x != 0) {
		flipped = flipped*10 + x%10;
		x /= 10;
	}
	
	return flipped;
}

int go(int n) {
	if (n > NMax-1)
		return inf;
	int &rez = memo[n];
	
	if (rez == -1) {
		if (n > target)
			rez = inf;
		else if (target == n)
			rez = 0;	
		else if (flip(n) > n)
			rez = 1+min(go(flip(n)),go(n+1));
		else
			rez = 1+go(n+1);
	}

	return rez;
}

void solve() {
	f>>target;
	memset(memo, -1, sizeof(memo));
	g<<go(0);
}

int main() {
	
	int t; f>>t;
	for (int i=1;i<=t;i++) {
		g<<"Case #"<<i<<": ";
		solve();
		g<<'\n';
	}
	
	f.close(); g.close();
	return 0;
}