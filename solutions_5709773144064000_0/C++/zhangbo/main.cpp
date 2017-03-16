#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>

using namespace std;

void calc()
{
	static int caseno = 0;
	caseno++;

	double c, f, x;
	cin >> c >> f >> x;

	double th = f*x / c - f;

	double rate = 2.0;
	double time = 0.0;
	while (rate < th)
	{
		time += c / rate;
		rate += f;
	}
	time += x / rate;

	std::cout.precision(7);
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	cout << "Case #" << caseno << ": ";
	cout << time;
	cout << endl;
}

int main()
{
	int k = 1;
	cin >> k;
	while (k-- > 0)
	{
		calc();
	}

	return 0;
}

