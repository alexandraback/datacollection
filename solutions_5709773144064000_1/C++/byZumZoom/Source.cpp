#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		double c, f, x, cur = 2.0;
		cin >> c >> f >> x;
		
		double wait_time = 0;
		double cur_time = x / cur, next_time = x / (cur + f) + c / cur;
		while(cur_time > next_time)
		{
			wait_time += c / cur;
			cur += f;
			cur_time = x / cur, next_time = x / (cur + f) + c / cur;
		}

		wait_time += cur_time;

		cout.precision(10);
		cout.setf(std::ios::fixed, std:: ios::floatfield);
		cout << "Case #" << t << ": " << wait_time << endl;
	}

	return 0;
}