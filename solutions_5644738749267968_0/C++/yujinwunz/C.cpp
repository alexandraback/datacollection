#include <iostream>
#include <algorithm>
using namespace std;

int cases;
double naomi[1000], ken[1000];

int main() {
	cin>>cases;
	for (int c = 1; c <= cases;c ++) {
		int n;
		cin>>n;
		for (int i = 0; i < n; i++) cin>>naomi[i];
		for (int i = 0; i < n; i++) cin>>ken[i];

		sort(naomi, naomi+n);
		sort(ken, ken+n);

		int lies = 0, honest = 0;
		int lmom = 0, hmom = 0;
		int a = n-1, b = n-1;
		while (a >= 0 || b >= 0) {

			if (b == -1 || (a != -1 && naomi[a] > ken[b])) {
				lmom++;
				if (hmom) {
					honest ++;
					hmom--;
				}
				a--;
			} else {
				hmom++;
				if (lmom) {
					lies++;
					lmom--;
				}
				b--;
			}
		}

		cout<<"Case #"<<c<<": "<<lies<<" "<<n-honest<<"\n";
	}
}