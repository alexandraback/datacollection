#include <fstream>
#include <iostream>
using namespace std;

ifstream f("B-large.in"); ofstream g("B-large.out");

const long long INF = 100000;

long long i, j, n, m, k, x, y, t, r, ii, e;
long long v[10005];
long long rez;

long long findMax(long long st, long long dr){
	long long pos = 0, mx = 0;
	for (i=st; i<=dr; i++){
		if (v[i]>mx){
			mx=v[i];
			pos = i;
		}
	}
	return pos;
}

void solve(long long st, long long dr, long long init, long long final){
	long long mij = findMax(st, dr);
	
	long long maxAvailable = (long long) init + (long long) r * (mij-st);
	if (maxAvailable > e) maxAvailable = e;
	
	long long needToHave = (long long) final - (long long) r*(dr-mij);
	if (needToHave <0) needToHave = 0;
	
	long long taken = (maxAvailable - needToHave);

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
