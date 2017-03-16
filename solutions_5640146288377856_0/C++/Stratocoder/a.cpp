#include <iostream>
#include <map>
#include <queue>
#include <utility>

using namespace std;

int solve_case() {
	int r, c, w;
	cin>>r>>c>>w;
	int ct = (r - 1) * (c / w);
	int base = c / w - 1;
	if (c % w == 0) {
		base -= 1;
	}
	ct += base + w + 1;
	return ct;
}

int main() {
	int tt;
	cin>>tt;
	for (int t = 1; t <= tt; ++t) {
		cout<<"Case #"<<t<<": "<<solve_case()<<endl;
	}
	return 0;
}

