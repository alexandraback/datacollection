#include <stdio.h>


long long a[] = {1,2,3,11,22,101,111,121,202,212,1001,1111,2002,10001,10101,10201,11011,11111,11211,20002,20102,100001,101101,110011,111111,200002,1000001,1001001,1002001,1010101,1011101,1012101,1100011,1101011,1102011,1110111,1111111,2000002,2001002,10000001,10011001};

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	for (int i = 0; i < 41; ++i)
		a[i] = a[i]*a[i];

	int T;
	scanf("%d", &T);
	int nt = 0;
	while(T--)
	{
		long long A, B;
		scanf("%lld%lld", &A, &B);

		int ans = 0;
		for (int i = 0; i < 41; ++i)
			if (A <= a[i] && a[i] <= B)
				ans++;
		printf("Case #%d: %d\n", ++nt, ans);
	}
}