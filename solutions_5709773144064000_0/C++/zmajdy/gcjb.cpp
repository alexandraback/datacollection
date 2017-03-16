#include <bits/stdc++.h>

#define R(i,a,b) for (int i=a; i<=b; i++)

using namespace std;

typedef pair<double,double> ii;

int T;
double C,F,X;
map<ii,double> mem;


double dp() {
	double tme = 0;
	double ans = 1000111222;
	double spd = 2;
	while (tme < ans) {
		ans = min(ans,tme + X/spd);
		tme += C/spd;
		spd  += F;
	}
	return ans;
}

inline void doprog(int tc) {
	cin >> C >> F >> X;
	mem.clear();
	printf ("Case #%d: ",tc);
	printf ("%.7lf\n",dp());
}

int main () {
	cin >> T;
	R(i,1,T)
		doprog(i);
}
