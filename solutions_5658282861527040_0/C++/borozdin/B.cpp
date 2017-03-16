#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long int64;

int a, b, c;
int A[32], B[32], C[32];

bool bit(int a, int b)
{
	return (a & (1 << b)) != 0;
}	

void convert(int x, int X[])
{
	for (int i = 0; i <= 30; i++)
		X[i] = bit(x, i);
	reverse(X, X + 31);	
}

int64 get_ans(int x, int y, int z)
{
	A[x] = 0;
	B[y] = 0;
	C[z] = 0;

	int64 ways = 1;

	for (int i = 0; i <= 30; i++)
	{
		bool has_a = (i <= x);
		bool has_b = (i <= y);
		bool has_c = (i <= z);

		if (has_a && has_b && has_c)
		{
			if ((A[i] & B[i]) != C[i])
				ways = 0;
		}
		if (!has_a && has_b && has_c)
		{
			if (B[i] == 0 && C[i] == 1)
				ways = 0;
			if (B[i] == 0 && C[i] == 0)
				ways *= 2;
		}
		if (has_a && !has_b && has_c)
		{
			if (A[i] == 0 && C[i] == 1)
				ways = 0;
			if (A[i] == 0 && C[i] == 0)
				ways *= 2;
		}
		if (has_a && has_b && !has_c)
		{
			//empty
		}
		if (has_a && !has_b && !has_c)
		{
			ways *= 2;
		}
		if (!has_a && has_b && !has_c)
		{
			ways *= 2;
		}
		if (!has_a && !has_b && has_c)
		{
			if (C[i] == 0)
				ways *= 3;
		}
		if (!has_a && !has_b && !has_c)
		{
			ways *= 4;
		}
	}

	A[x] = 1;
	B[y] = 1;
	C[z] = 1;

	return ways;
}

void solve()
{
	cin >> a >> b >> c;
	convert(a, A);
	convert(b, B);
	convert(c, C);

	/*for (int i = 0; i <= 30; i++)
		printf("%d", A[i]);
	printf("\n");
	for (int i = 0; i <= 30; i++)
		printf("%d", B[i]);
	printf("\n");
	for (int i = 0; i <= 30; i++)
		printf("%d", C[i]);
	printf("\n");*/

	int64 answer = 0;

	for (int i = 0; i <= 30; i++)
		for (int j = 0; j <= 30; j++)
			for (int k = 0; k <= 30; k++)
				if (A[i] == 1 && B[j] == 1 && C[k] == 1)
					answer += get_ans(i, j, k);

	printf("%lld\n", answer);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		printf("Case #%d: ", i + 1);
		solve();
		cerr << "done " << i + 1 << endl;
	}

	return 0;
}	