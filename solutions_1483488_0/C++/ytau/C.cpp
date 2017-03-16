


#include <iostream>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <sstream>
#include <string>

#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>

#include <algorithm>

#include <utility>
// ytau (HK)
using namespace std;



const int inf = 2000000000;
const long long linf = 9000000000000000000LL;
const double finf = 1.0e18;
const double eps = 1.0e-8;


int T, A, B, l, m;
set<int> se;
long long ans;

int len(int z) {
	int ret=0;
	while (z) {
		ret++;
		z /= 10;
	}
	return ret;
}

int main() {
	scanf("%d", &T);
	for (int tt=1; tt<=T; tt++) {
		scanf("%d%d", &A, &B);
		l = len(A);
		m = 1;
		for (int i=1; i<l; i++) 
			m *= 10;
		ans = 0;
		for (int i=A; i<=B; i++) {
			for (int j=1, k=i; j<l; j++) {
				k = (k%10)*m + (k/10);
				if ((i<k) && (k<=B)) 
					se.insert(k);
			}
			ans += (int) se.size();
			se.clear();
		}
		printf("Case #%d: %lld\n", tt, ans);
	}
	return 0;
}


