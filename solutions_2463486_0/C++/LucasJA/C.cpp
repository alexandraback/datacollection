#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

/*long long v[10000000];
char s[30];

bool isPal(long long n)
{
	int i = 0;
	while (n > 0)
	{
		s[i++] = n % 10;
		n /= 10;
	}
	
	bool pal = true;
	for (int j = 0; j < i; ++j)
		pal = pal && s[j] == s[i - j - 1];
		
	return pal;
}*/

long long v[] = { 1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004 };

int main()
{
	/*int size = 0;
	for (int i = 1; i <= 10000000; ++i)
	{
		long long ii = (long long) i * i;
		if (isPal(i) && isPal(ii))
		{
			printf("%lld, ", ii);
			v[size++] = ii;
		}
	}
	printf("\n%d\n", size);*/
	
	int size = 39;

	int t;
	scanf("%d", &t);
	for (int x = 0; x < t; ++x)
	{
		long long a, b;
		scanf("%lld %lld", &a, &b);
		
		int low = lower_bound(v, v + size, a) - v;
		int high = upper_bound(v, v + size, b) - v;
		printf("Case #%d: %d\n", x + 1, high - low);
	}
	return 0;
}
