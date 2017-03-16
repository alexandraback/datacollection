#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

#define	LL	long long int

using namespace std;

LL r, t;

LL Solve() {
	LL ans = 0;
	LL tmp;	

	while(1) {
		tmp = (2*r+1);
		//cout << tmp << endl;
		if(tmp > t) break;
		t -= tmp;
		r += 2;
		ans++;
	}

	return ans;
}

int main (void) {
	int k, d;

	scanf("%d", &d);
	for(k=1; k <= d; k++) {
		cin >> r;
		cin >> t;
		printf("Case #%d: ", k);
		cout << Solve() << endl;
	}

	return 0;
}
