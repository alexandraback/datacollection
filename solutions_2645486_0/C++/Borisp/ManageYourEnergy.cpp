#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#include<set>
#include<map>
#include<fstream>
#define epsilon 0.000000001
#define cosinusa(a, b, c) ((a * a + b * b - c * c) / (2.0 * a * b));
#define infi 1000000000
using namespace std;

long long mat[1 << 14];
int closestBigger[1 << 14];
void calcClosestBigger(int n)
{
	for (int i = 0; i < n; i++)
	{
		bool met = false;
		for (int j = i + 1; j < n; j++)
		{
			if (mat[j] > mat[i])
			{
				closestBigger[i] = j;
				met = true;
				break;
			}
		}
		if (!met)
		{
			closestBigger[i] = -1;
		}
	}
}

int main()
{
	freopen("google.in", "r", stdin);
	freopen("google.out", "w", stdout);
	int numTests;
	cin >> numTests;
	for(int testCounter = 0; testCounter < numTests; ++testCounter)
	{
		printf("Case #%d: ", testCounter + 1);
		long long e, r;
		int n;
		cin >> e >> r >> n;
		long long sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> mat[i];
		}
		calcClosestBigger(n);
		long long cur = e;
		long long res = 0;
		long long carry;
		for (int i = 0; i < n; i++)
		{
			if (closestBigger[i] == -1)
			{
				res += cur * mat[i];
				cur = r;
				continue;
			}
			if ((long long)(closestBigger[i] - i) * r > e)
			{
				res += cur * mat[i];
				cur = r;
			} else {
				carry = min(cur, e - (long long)(closestBigger[i] - i) * r);
				res += (cur - carry) * mat[i];
				cur = carry + (long long)(closestBigger[i] - i) * r;
				i = closestBigger[i] - 1;
			}

		}
		cout << res << endl;
	}
	return 0;
}
