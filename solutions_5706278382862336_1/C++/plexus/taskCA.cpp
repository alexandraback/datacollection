#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define INF (1<<30)

using namespace std;

const int N = 10;
char buff[300];

int64_t gcd(int64_t a, int64_t b)
{
	if (a == 0 || b == 0)
	{
		return a + b;
	}
	return gcd(max(a, b) % min(a, b), min(a, b));
}

bool check(int64_t a, int64_t b)
{
	int cnt = 0;

	while (b != 0)
	{
		b = b & (b-1);
		cnt++;
	}

	return cnt == 1;
}

int mxP(int64_t a, int64_t b)
{
	int d = 1;

	while (b / (1LL<<d) > a)
		d++;

	return d;
}

int main()
{
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t;
	scanf("%d", &t);
	gets(buff);

	for(int test = 1; test <= t; test++)
	{
		printf("Case #%d: ", test);
		string s;
		getline(cin, s);
		string sa = s.substr(0, s.find('/'));
		string sb = s.substr(s.find('/') + 1);

		int64_t a, b;
		sscanf(sa.c_str(), "%lld", &a);
		sscanf(sb.c_str(), "%lld", &b);
		int64_t g = gcd(a, b);
		a /= g;
		b /= g;

		if (!check(a, b))
		{
			printf("impossible");		
		}
		else
		{
			printf("%d", mxP(a, b));
		}


		printf("\n");
	}

	return 0;
}