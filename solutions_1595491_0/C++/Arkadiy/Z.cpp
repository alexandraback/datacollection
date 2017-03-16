#include <iostream>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t,q,i,n,s,p,x,y,smx,umx,res;
	cin >> t;
	for (q=1;q<=t;++q) {
		cin >> n >> s >> p;
		res = 0;
		for (i=0;i<n;++i) {
			cin >> x;
			y = x / 3;
			if (x % 3 ==0) {
				smx = y+1;
				umx = y;
			} else if (x % 3 == 1) {
				smx = y + 1;
				umx = y + 1;
			} else {
				smx = y + 2;
				umx = y + 1;
			}
			if (x==29) {
				smx = -1;
			}
			else if (x==30) {
				smx = -1;
			} else if (x==0) {
				smx = -1;
			} else if (x==1) {
				smx = -1;
			}

			if (umx >= p) {
				++res;
			} else if (smx >= p && s > 0) {
				++res;
				--s;
			}
		}
		cout << "Case #" << q << ": " << res << "\n";
	}

	return 0;
}