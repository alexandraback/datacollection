#include <algorithm>
#include <cstdint>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <set>

using namespace std;

//ifstream input("./test.txt");
ifstream input("./A-small-attempt2.in");

ofstream output("./out.txt");

long long flip(long long v) {
	long long res = 0;
	while (v)
	{
		res *= 10;
		res += v % 10;
		v /= 10;
	}
	return res;
}

long long solve(long long val) {

	if (val <= 20)
		return val;

	if (val % 10 == 0)
		return solve(val - 1) + 1;

	long long pow = 1;
	while (pow * pow < val)
		pow *= 10;

	long long a, b;
	a = val % pow;
	b = val / pow;
	b = flip(b);

	long long ans = a + b;

	if (b != 1)
		ans++;

	long long rest = 9;
	while (rest * 10 + 9 < val)
	{
		rest = rest * 10 + 9;
	}

	return ans + solve(rest);
}

int main(int argc, char** argv)
{
	int t;
	input >> t;

	for (int i = 1; i <= t; i++) {
		long long v;
		input >> v;
		output << "Case #" << i << ": " << solve(v) << endl;
	}

	return 0;
}