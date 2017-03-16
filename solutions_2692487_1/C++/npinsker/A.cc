#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n, a, zt, motes[1000];

int main() {
    scanf("%d", &zt);
    
    for (int kt=0; kt<zt; ++kt) {
	scanf("%d%d", &a, &n);
	for (int i=0; i<n; ++i) scanf("%d", &motes[i]);
	
	sort(motes, motes + n);
	
	int best = n, add = 0, size = a;
	
	for (int i=0; i<n; ++i) {
	    if (size == 1) {
		best = n;
		break;
	    }
	    
	    if (size > motes[i]) {
		size += motes[i];
	    }
	    else {
		while (size <= motes[i]) {
		    ++add;
		    size += size-1;
		}
		size += motes[i];
	    }
	    best = min(best, add + (n-1-i));
	}
	printf("Case #%d: %d\n", kt+1, best);
    }
}