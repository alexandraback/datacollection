//============================================================================
// Name        : Round1B_B.cpp
// Author      : Peiqian Li
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int nc;
	cin >> nc;
	for(int cid=1; cid<=nc; ++cid) {
		int a, b, k;
		cin >> a >> b >> k;
		int ans = 0;
		for(int i=0; i<a; ++i)
			for(int j=0; j<b; ++j)
				if((i&j)<k)
					++ans;
		printf("Case #%d: %d\n", cid, ans);
	}
	return 0;
}
