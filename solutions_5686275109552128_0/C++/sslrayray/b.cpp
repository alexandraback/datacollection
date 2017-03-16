#include <bits/stdc++.h>
#define maxn 1000

using namespace std;

int main(){
	int repn;
	cin >> repn;
	int P[maxn];
	for (int rep = 0; rep < repn; rep++) {
		int D, maxcake = 0;
		int maxans;
		cin >> D;
		for (int i = 0; i < D; i++){
			cin >> P[i];
			if (P[i] > maxcake)
				maxcake = P[i];
		}
		maxans = maxcake;
		int anscake = -1;
		for ( int caket = maxcake; caket > 0; caket --) {
			int time = maxcake;
			int fent = 0;
			for ( int i = 0; i < D; i++)
				fent += (int)(ceil((double)P[i] / (double)caket) - 1);
			if (fent + caket <= maxans){
				anscake = caket;
				maxans = fent+caket;
			}
		}
		cout << "Case #" << rep+1 << ": " << maxans << endl;
	}
	return 0;
}