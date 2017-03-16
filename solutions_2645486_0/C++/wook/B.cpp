#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i=0; i<(int)(n); ++ i) 
#define uniquify(v) {sort(all(v));(v).erase(unique(all(v)), (v).end());}

int E, R, N;
int v[100];

int C[6][11];

int f(int energy, int i) {
	if(i >= N) return 0;

	int &ret = C[energy][i];
	if(ret!= -1) return ret;

	ret = 0;
	for(int here = 0; here <= energy; ++ here) {
		int t = v[i] * here + f(min(energy - here + R, E), i + 1);
		ret = max(ret, t);
	}
	return ret;
}

int go() {
	memset(C, -1, sizeof(C));
	return f(E, 0);
}

int main() {
	int T;
	freopen("B-small.in","r",stdin);
	freopen("B-small.out","w",stdout);
	cin >> T;

	for(int tt=1;tt<=T;++tt) {
		cin >> E >> R >> N;
		for(int i=0; i<N; ++i)
			cin >> v[i];
		cout << "Case #" << tt << ": ";
		cout << go () << endl;
	}
	return 0;
}
