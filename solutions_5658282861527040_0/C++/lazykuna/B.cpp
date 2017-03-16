#include <iostream>
#include <fstream>
using namespace std;

ifstream inf("2.in");
ofstream outf("2.out");

int cnt;
int a,b ,k;
long long res;

int getbitsize(int n, int lvl) {
	if (!n) return lvl;
	else getbitsize(n>>1, lvl+1);
}

void process() {
	for (int i=0; i<a; i++) {
		for (int j=0; j<b; j++) {
			if ((i&j) < k) {
				res++;
				//cout << i << "," << j << "," <<  (int)(i&j) << endl;
			}
			//ww
		}
	}
}

int main() {
	inf >> cnt;
	cout << cnt << endl;
	for (int i=0; i<cnt; i++) {
		inf >> a;
		inf >> b;
		inf >> k;
		res = 0;
		
		// sort for convenience
		if (a<b) {
			int t = a;
			a = b;
			b = t;
		}
		process();
		outf << "Case #" << i+1 << ": " << res << endl;
	}

	inf.close();
	outf.close();
	return 0;
}
