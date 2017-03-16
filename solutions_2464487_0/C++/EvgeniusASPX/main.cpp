#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <set>
#include <vector>
using namespace std;
const long long MOD = 1000000007;
const int MAX = 10000;
const int MAXX = 100000000;
int b[MAXX];
int mul[5] = {1, 10, 100, 1000, 10000};
long long n,m;
long long w[MAX];
bool good(int i)
{
	long long q = i;
	long long p = q * q; q = p;


	long long rq = 0;
	long long tq = q;

	while (tq)
	{
		rq = rq * 10 + tq %10;
		tq/=10;
	}
	return rq == q;
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tt;
	cin >> tt;
					
	for (int t = 0; t < tt; ++t)
	{
		long long r, p;
		long long count = 0;
		cin >> r  >> p;
		r--;
		
		while (p > 0)
		{
		long long need = 2 * r + 3;

		if (p < need)
			break;
		p-=need;
		count++;
		r+=2;
		}

	
		cout << "Case #" << t + 1 << ": " << count << endl;
	}
	return 0;
}