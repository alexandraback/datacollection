#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <numeric>

using namespace std;

#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define SIZEOF(a) (sizeof(a)/sizeof((a)[0]))

const int MAX_N = 1e5+10;
int a[MAX_N];

void Solve()
{
	double C, F, X; cin >> C >> F >> X;
	double R = 2;
	const int n = max(C, max(F, X)) + 10;
	double t = 0;
	for(int i = 0; i < n; ++i){
		const double t1 = X / R;
		const double r = R+F;
		const double ts = C / R;
		const double t2 = X / r;
		if(t1 < ts+t2){
			t += t1;
			break;
		}else{
			R = r;
			t += ts;
		}
	}
	printf("%0.7f\n", t);
}

int main()
{
	int T; cin >> T;
	FOR(t, T){
		cout << "Case #" << t+1 << ": ";
		Solve();
	}
	return 0;
}
