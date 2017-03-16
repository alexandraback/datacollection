#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
using namespace std;
int main() {
	int T;
	scanf("%d",&T);
	for(int cn=1;cn<=T;++cn) {
		int A,B,ans = 0;
		scanf("%d%d",&A,&B);
		for(int n=A;n<B;++n) {
			// keep shifting till we get back n
			int k = n, p = 1;
			while(p <= n) p *= 10;
			p /= 10;
			do {
				int d = k%10;
				k = k/10 + d*p;
				if(k <= B && k > n) ++ans;
			} while(k != n);
		}
		printf("Case #%d: %d\n",cn,ans);
	}
}
