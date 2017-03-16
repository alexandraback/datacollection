#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int T, caso, r, t, acum, p;
	scanf("%d", &T);
	for (caso=1 ; caso<=T ; caso++) {
		scanf("%d%d", &r, &t);
		acum = 0;
		r++;
		while (true) {
			p = (r*r)-((r-1)*(r-1));
			//printf("--- p=%d t=%d\n", p, t);
			if (t < p)
				break;
			t -= p;
			acum++;
			r += 2;
		}
		printf("Case #%d: %d\n", caso, acum);
	}
	return 0;
}
