#include <stdio.h>
#include <vector>
#include <map>
#include <hash_map>
#include <algorithm>
#include <utility>
#include <string.h>

using namespace std;

int main()
{
	int ncase;
	scanf("%d", &ncase);

	for (int icase=1; icase<=ncase; icase++) {
		int x, r, c;
		scanf("%d %d %d", &x, &r, &c);
		if (x==1) {
			printf("Case #%d: GABRIEL\n", icase);
			continue;
		}
		if (x==2) {
			if ((r*c)%2 == 0)
				printf("Case #%d: GABRIEL\n", icase);
			else
				printf("Case #%d: RICHARD\n", icase);
			continue;
		}
		if (x==3) {
			if (r > c)
				swap(r, c);
			if (r==1) {
				printf("Case #%d: RICHARD\n", icase);
				continue;
			}
			if (r==2&&c==3 || r==3&&c==4 || r==3&&c==3)
				printf("Case #%d: GABRIEL\n", icase);
			else
				printf("Case #%d: RICHARD\n", icase);
		}
		if (x==4) {
			if (r>c)
				swap(r,c);
			if (r==1 || r==2 || r==3&&c==3)
				printf("Case #%d: RICHARD\n", icase);
			else {
				printf("Case #%d: GABRIEL\n", icase);
			}
		}

	}
	return 0;
}