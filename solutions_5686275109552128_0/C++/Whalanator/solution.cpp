#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T,D,cas,m,s,c1,c2;
typedef vector<int> vi;
vi pc;

int main() {
	cin >> T;
	pc.assign(1000,0);
	for (cas=1;cas<=T;cas++) {
		cin >> D;
		for (c1=0;c1<D;c1++) {
			cin >> pc[c1];
		}
		m=INT_MAX;
		for (c1=1;c1<=1000;c1++) {
			s=c1;
			for (c2=0;c2<D;c2++) s+=(pc[c2]-1)/c1;
			m=min(s,m);
		}
		cout << "Case #" << cas << ": " << m << endl;
	}
	return 0;
}
