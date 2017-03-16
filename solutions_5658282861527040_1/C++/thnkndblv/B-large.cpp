using namespace std;

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "iostream"
#include "stdio.h"
#include "algorithm"
#include "math.h"
#include "vector"
#include "string.h"

int A, B, K;

long long dp[ 32 ][ 2 ][ 2 ][ 2 ];
long long solve(int bit, int lima, int limb, int limk)
{
	if (bit < 0) return 1LL; 
	
	long long &ret = dp[ bit ][ lima ][ limb ][ limk ];

	if ( ret != -1LL ) return ret;

	ret = 0LL;

	int AA = (lima) ? ((A >> bit) & 1) : 1;
	int BB = (limb) ? ((B >> bit) & 1) : 1;
	int KK = (limk) ? ((K >> bit) & 1) : 1;

	for (int ba = 0; ba <= AA; ba++)
		for (int bb = 0; bb <= BB; bb++)
		{
			int rr = ba && bb;
			if ( rr <= KK )
				ret += solve( bit - 1, lima && ba == AA, limb && bb == BB, limk && rr == KK);
		}

	return ret;
}

int main()
{
	int ntc;

	cin >> ntc;
	for (int tc = 1; tc <= ntc; tc++)
	{
		cin >> A >> B >> K;

		A--;
		B--;
		K--;

		memset( dp, -1, sizeof dp );
		cout << "Case #" << tc << ": " << solve(30, 1, 1, 1) << endl;
	}
	
    return 0;
}
