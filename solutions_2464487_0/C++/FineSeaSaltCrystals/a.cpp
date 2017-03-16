#include <cstdio>
#include <iostream>
using namespace std;
int main() {
	int ncases;
	cin >> ncases;
	for(int casen = 1; casen <= ncases; casen++) {
		unsigned long long r, t;
		cin >> r >> t;
		unsigned long long lo = 1, hi = 1;
		while(2*hi*(hi + 1) + 2*hi*r - 3*hi < t) hi *= 2;
		while(hi > lo) {
			unsigned long long x = lo/2 + hi/2 + 1;
			unsigned long long need = 2*x*(x + 1) + 2*x*r - 3*x;
			if(need > t) {
				hi = x - 1;
			}
			else {
				lo = x;
			}
		}
		cout << "Case #" << casen << ": " << lo << endl;
	}	
}
