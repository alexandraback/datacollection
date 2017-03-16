#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include<numeric>
using namespace std;

class Solution{
public:
	int solve(unsigned long long val)
	{
		typedef unsigned long long ulong;
		ulong product = 0;
		ulong temp = 0;
		int cnt = 10;
		bool flag[10];
		fill(flag, flag + 10, false);
		while (true)
		{
			product += val;
			temp = product;
			while (temp != 0)
			{
				if (!flag[temp % 10])
				{
					flag[temp % 10] = true;
					--cnt;
				}
				temp /= 10;
				if (0 == cnt)
					return product;
			}
		}
		return 0;
	}
};

int main()
{
	//ifstream in("A-small-attempt0.in");
	//ofstream out("small_output.out");
	istream& in = cin;
	ostream& out = cout;
	Solution A;
	int T;
	in >> T;
	unsigned long long indata;
	for (int i = 1; i <= T; ++i)
	{
		in >> indata;
		out << "Case #" << i << ": ";
		if (indata == 0)
			out << "INSOMNIA" << endl;
		else
			out << A.solve(indata) << endl;
	}
	return 0;
}