#include <stdio.h>
#include <set>
using namespace std;

int A, B, T, M;

void go(int n)
{
	int m = 0, t = 1, p = n;
	for (int k = n; k; ++m) k/=10, t*=10;
	t /= 10;
	set<int> dict;
	while (--m)
	{
		p = p/10 + p%10*t;
		if (p>n && p<=B)
			if (dict.insert(p).second) ++M;
	}
}

int main()
{
	scanf("%d ", &T);
	for (int t = 0; t < T; ++t)
	{
		scanf("%d%d", &A, &B);
		M = 0;
		for (int n = A; n <= B; ++n)
			go(n);
		printf("Case #%d: ", t+1);
		printf("%d\n", M);
	}
	return 0;
}
