#include <cstdio>
#include <cstring>

char temp[64];
int t;

long long gcd(long long a, long long b)
{
	if (a == 0ll) return b;
	if (b == 0ll) return a;
	return gcd(b%a, a);
}

long long atoi(const char* x)
{
	long long res = 0ll;
	int n = strlen(x);
	for (int i = 0;i < n;i++)
		res = res * 10ll + x[i] - '0';
	return res;
}

bool pow2(const long long x)
{
	return (__builtin_popcountll(x) == 1);
}

int main()
{
	scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		printf("Case #%d: ", _);
		scanf("%s", temp);
		char* ptr = strtok(temp, "/");
		long long a = atoi(ptr);
		ptr = strtok(NULL, "/");
		long long b = atoi(ptr);
		long long g = gcd(a, b);
		a /= g;
		b /= g;
		if (!pow2(b))
		{
			printf("impossible\n");
			continue;
		}
		if (b > (1ll << 40))
			continue;
		int i = 0;
		g = (1ll << 40) / b;
		a *= g;
		for (;i <= 40;i++) if (a < (1ll << i))
			break;
		i--;
		printf("%d\n", 40-i);
	}
	return 0;
}
