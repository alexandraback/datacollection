#include <cstdio>
#include <algorithm>
using namespace std;

bool solve()
{
	int x, w, l;
	scanf("%i%i%i", &x, &w, &l);
	if (w > l) swap(w, l);
	if (w * l % x) return true;
	if (l < x) return true;
	switch (x) {
		break;case 1:
		break;case 2:
		break;case 3: if (w < 2) return true;
		break;case 4: if (w < 3) return true;
		break;case 5: if (w < 3
			|| w == 3 && l == 5) return true;
		break;case 6: if (w < 4) return true;
		break;default: return true;
	}
	return false;
}

int main()
{
	int t;
	scanf("%i", &t);
	for (int i = 0; i < t; i++) {
		printf("Case #%i: ", i +1);
		printf("%s", solve()? "RICHARD": "GABRIEL");
		printf("\n");
	}
	return 0;
}

