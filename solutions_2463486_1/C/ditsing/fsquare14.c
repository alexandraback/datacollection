#include <stdio.h>

const int table[] = {
	1,
	2,
	3,
	11,
	22,
	101,
	111,
	121,
	202,
	212,
	1001,
	1111,
	2002,
	10001,
	10101,
	10201,
	11011,
	11111,
	11211,
	20002,
	20102,
	100001,
	101101,
	110011,
	111111,
	200002,
	1000001,
	1001001,
	1002001,
	1010101,
	1011101,
	1012101,
	1100011,
	1101011,
	1102011,
	1110111,
	1111111,
	2000002,
	2001002,
};
const int cnt = 39;

int main()
{
	int Tcases;
	scanf("%d", &Tcases);
	int cases;
	for ( cases = 0; cases < Tcases; cases++)
	{
		long long A, B;
		scanf("%lld %lld\n", &A, &B);
		int i;
		int ans = 0;
		for ( i = 0; i < cnt; i++)
		{
			long long num = table[i];
			num *= num;
			if ( num >= A && num <= B)
			{
				++ans;
			}
		}
		printf("Case #%d: %d\n", cases + 1, ans);
	}

	return 0;
}

