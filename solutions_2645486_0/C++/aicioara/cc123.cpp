#include <fstream>
#include <iostream>
using namespace std;

ifstream f("B-small-attempt0.in"); ofstream g("B-small-attempt0.out");

const int INF = 100000;

int i, j, n, m, k, x, y, t, r, ii, e;
int v[10005];
long long rez;

int findMax(int st, int dr){
	int pos = 0, mx = 0;
	for (i=st; i<=dr; i++){
		if (v[i]>mx){
			mx=v[i];
			pos = i;
		}
	}
	return pos;
}

void solve(int st, int dr, int init, int final){
	int mij = findMax(st, dr);
	
	int maxAvailable = (long long) init + r * (mij-st);
	if (maxAvailable > e) maxAvailable = e;
	
	int needToHave = (long long) final - r*(dr-mij);
	if (needToHave <0) needToHave = 0;
	
	int taken = (maxAvailable - needToHave);

	rez += v[mij] * taken;
	if (st<mij) solve (st, mij-1, init, taken+needToHave-r);
	if (mij<dr) solve (mij+1, dr, maxAvailable-taken+r, final);
}
	

int main(){
	f>>t;
	for (ii=1; ii<=t; ii++){
		f>>e>>r>>n;
		rez = 0;
		for (i=1; i<=n; i++) f>>v[i];
		
		rez = 0;
		solve(1, n, e, 0);
		
		g<<"Case #"<<ii<<": "<<rez<<"\n";
	}
}
