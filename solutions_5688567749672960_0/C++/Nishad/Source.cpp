#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

long long reverse(long long num)
{
	long long ten = 1;

	for (long long x = num; x;)
	{
		ten *= 10;
		x /= 10;
	}

	ten /= 10;
	long long ans = 0;

	for (long long x = num; x;)
	{
		long long a = x % 10;
		ans += ten * a;
		ten /= 10;
		x /= 10;
	}

	return ans;
}

int main()
{
	//ifstream infile("in.txt");
	//cin.rdbuf(infile.rdbuf());

	//ofstream outfile("out.txt");
	//cout.rdbuf(outfile.rdbuf());

	//for (int i = 0; i < 1000; i++)
	//{
	//	if (i & 1)
	//		cout << 0 << ' ';
	//	else
	//		cout << 10000 << ' ';
	//}

	int t;

	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		long long n;
		cin >> n;

		vector<long long> arr(1000001, 10000000000000000LL);

		for (int i = 0; i <= 11; i++)
		{
			arr[i] = i;
		}

		for (long long i = 12; i <= n; i++)
		{
			long long a = arr[i - 1] + 1;
			arr[i] = a < arr[i] ? a : arr[i];

			long long b = reverse(i);
			long long c = arr[i] + 1;
			arr[b] = c < arr[b] ? c : arr[b];
		}

		cout << "Case #" << tc << ": " << arr[n] << endl;
	}

	return 0;
}
