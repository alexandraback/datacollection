#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <set>

using namespace std;

ofstream fout("output.txt");

int digit_count(int num)
{
	int count = 0;
	while (num > 0)
	{
		++count;
		num /= 10;
	}
	return count;
}

int power(int a, int b)
{
	int res = 1;
	for (int i = 1;i <= b;++i)
	{
		res *= a;
	}
	return res;
}

int rotate(int num, int k)
{
	int j = digit_count(num) - k;
	int l = power(10, j);
	int m = power(10, k);
	return (num % m) * l + (num / m);
}

int pair_count(int A, int B)
{
	int result = 0;
	for (int i = A; i <= B;++i)
	{
		set<int> results;
		int count = digit_count(i);
		for (int j = 1; j < count; ++j)
		{
			int num = rotate(i, j);
			if (num > i && num >= A && num <= B)
			{
				results.insert(num);
			}
		}

		result += results.size();
	}
	return result;
}

int main()
{
	ifstream fin("input.txt");

	int T;
	fin>>T;
	int A,B;
	for (int i = 1;i <= T;++i)
	{
		fin>>A>>B;
		fout<<"Case #"<<i<<": "<<pair_count(A,B)<<endl;
	}
}