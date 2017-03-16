#include <cstdio>

using namespace std;

unsigned long long binarySearchAns(unsigned long long r, unsigned long long t);
bool func(unsigned long long r, unsigned long long k, unsigned long long t);
/*int main(void)
{
	int T, r, t, caseId = 1, numDraw = 0, areaPi;

	scanf("%d", &T);

	while(caseId <= T)
	{
		scanf("%d %d", &r, &t);

		numDraw = 0;
		
		areaPi = 2 * r  + 1;
		while(t >= areaPi)
		{
			numDraw++;
			t -= areaPi;
			areaPi += 4;
		}

		printf("Case #%d: %d\n", caseId, numDraw);
		caseId++;
	}
	return 0;
} */

int main(void)
{
	int T, caseId;
	unsigned long long r, t;

	scanf("%d", &T);

	caseId = 1;
	while(caseId <= T)
	{
		scanf("%llu %llu", &r, &t);

		/* Find largest k such that
  		 *	2r + 1 + 2r + 5 + ... + 2r + 1 + 4k <= t
 		 * Then the total number of circles drawn is k +  1
 		 */
		printf("Case #%d: %llu\n", caseId, 1 + binarySearchAns(r, t));
		caseId++;
	}

	return 0;
}

unsigned long long binarySearchAns(unsigned long long r, unsigned long long t)
{
	unsigned long long left = 0, right = 1000000000, mid;

	while(left <= right)
	{
		mid = left + ((right - left) >> 1);

		if(func(r, mid, t) && !func(r, mid + 1, t))
			return mid;
		else
		{
			if(!func(r, mid, t))
				right = mid - 1;
			else
				left = mid + 1;
		}
	}

	return -1;	// Dummy
}

bool func(unsigned long long r, unsigned long long k, unsigned long long t)
{
	if(!(2 * r + 2 * k + 1 > (t * 1.0 / (k + 1))))
		return true;
	return false;
}
