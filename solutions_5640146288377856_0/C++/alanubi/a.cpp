#include <cstdio>
using namespace std;

void solve()
{
	int r, c, w;
	scanf("%i%i%i", &r, &c, &w);
	printf("%i", r * (c / w) + w - (c % w? 0: 1));
}

int main()
{
	int t;
	scanf("%i", &t);
	for (int i = 0; i < t; i++) {
		printf("Case #%i: ", i +1);
		solve();
		printf("\n");
	}
	return 0;
}

