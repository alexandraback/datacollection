#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int cal1(set<int> a,set<int> b) {
	for (set<int>::iterator ta = a.begin(); ta != a.end();) {
		set<int>::iterator tb = b.upper_bound((*ta) + 1);
		if (tb == b.end()) {
			break;
		}
		a.erase(ta++);
		b.erase(tb);
	}
	return a.size();
}

int cal2(set<int> a,set<int> b) {
	for (set<int>::iterator ta = a.begin(); ta != a.end(); ) {
		if (*ta > *(b.rbegin())) {
			break;
		}
		if (*ta > *(b.begin())) {
			++ta;
			b.erase(b.begin());
		}
		else {
			set<int>::iterator tb = b.end();
			b.erase(--tb);
			a.erase(ta++);
		}
	}
	return a.size();
}
			
		
	

int main() {
int zz;
	scanf("%d",&zz);
	for (int z = 1; z <= zz; ++z) {
		int n;
		set<int> a,b;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			double x;
			scanf("%lf",&x);
			a.insert((int) (x * 10000000 + .5));
		}
		for (int i = 0; i < n; ++i) {
			double x;
			scanf("%lf",&x);
			b.insert((int) (x * 10000000 + .5));
		}
		
		//printf("%d\n",cal2(a,b));
		printf("Case #%d: %d %d\n",z,cal2(a,b),cal1(a,b));
	}
	return 0;
}
		
