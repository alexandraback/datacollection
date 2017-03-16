#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define RESULT(x) printf("Case #%d: %s\n", Q, (x)?"GABRIEL":"RICHARD")

int main() {
	int T, x, r, c;
	scanf("%d", &T);
	for (int Q=1;Q<=T;Q++) {
		scanf("%d%d%d", &x, &r, &c);
		if (r>c)
			swap(r, c);
		if (x==1)
			RESULT(true);
		else if (x==2)
			RESULT(r*c%2==0);
		else if (x==3)
			RESULT(r>1 && r*c%3==0);
		else if (x==4)
			RESULT(r*c>=12);
	}
	return 0;
}

