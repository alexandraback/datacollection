#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int T;
int n;

int main()
{
	ifstream in("safety.in");
	ofstream out("safety.out");
	in >> T;
	out.precision(6);
	for (int c = 1; c <= T; c++)
	{
		in >> n;
		int total = 0, nums[210];
		double ans[210];
		for (int i = 0; i < n; i++)
		{
			in >> nums[i];
			total += nums[i];
		}
		out << "Case #" << c << ":";
		double subtract = 0;
		int tt = 0;
		for (int i = 0; i < n; i++)
		{
			double x = total - nums[i] + total - (n - 1) * nums[i];
			x /= n;
			ans[i] = x;
			if (x < 0.0)
			{
				subtract += x;
				tt++;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (ans[i] < 0)
				out << ' ' << fixed << 0.0;
			else
				out << ' ' << fixed << (ans[i] + subtract / (n - tt)) / total * 100;
		}
		out << '\n';
	}
	return 0;
}

