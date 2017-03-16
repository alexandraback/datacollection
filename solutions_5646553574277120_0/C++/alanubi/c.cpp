#include <cstdio>
#include <cassert>
using namespace std;

bool *a;
int v;

void add(int x)
{
	for (int i = v - x; 0 <= i; --i) {
		a[i + x] = a[i + x] || a[i];
	}
}

void solve()
{
	int c, d;
	scanf("%i%i%i", &c, &d, &v);
	assert(1 == c);
	a = new bool[v +1];
	for (int i = v; 0 <= i; --i) {
		a[i] = 0 == i;
	}
	for (int i = 0; i < d; i++) {
		int x;
		scanf("%i", &x);
		add(x);
	}
	int cnt = 0;
	for (int i = 0; i <= v; i++) {
		if (!a[i]) {
			add(i);
			cnt++;
		}
	}
	printf("%i", cnt);
	delete[] a;
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

