#include <iostream>
#include <iomanip>

using namespace std;

double s[10000], X;
int n;

void read()
{
	int i;
	cin >> n;
	X = 0.0;
	for (i = 0; i < n; ++i)
	{
		cin >> s[i];
		X += s[i];
	}
}
double solution(int i1)
{
	int i;
	double st = 0.0, end = 1.0, midval, val;
	double sum_of_less;
	int num_of_less;
	while (end - st > 0.000000001)
	{
		midval = (end + st) / 2;
		val = s[i1]  + X * midval;
		sum_of_less = 0.0;
		num_of_less = 0;
		for (i = 0; i < n; ++i)
		{
			if ((s[i] < val) && (i != i1))
			{
				++num_of_less;
				sum_of_less += s[i];
			}
		}
		if (val > (sum_of_less + (1.0 - midval) * X) / num_of_less)
		{
			end = midval;
		}
		else
		{
			st = midval;
		}
	}
	return st;
}
void solve()
{
	int i,j,k;
	for (i = 0; i < n - 1; ++i)
	{
		std::cout << fixed << setprecision(7) << solution(i)*100 << " ";
	}
	std::cout << fixed << setprecision(7) << solution(n - 1)*100 << "\n"; 
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	int i;
	for (i = 1; i <= t; ++i)
	{
		read();
		std::cout << "Case #" << i << ": ";
		solve();
	}
}