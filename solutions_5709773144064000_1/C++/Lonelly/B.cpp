#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

void solve(int index)
{
	double C, F, X;
	cin >> C >> F >> X;
	double cur = 0;
	double curSpeed = 2;
	double result = 0;
	if (C >= X)
	{
		result = X / curSpeed;
	}
	else
	{
		result += C / curSpeed;
		while ((X - C) / curSpeed > X / (curSpeed + F))
		{
			curSpeed += F;
			result += C / curSpeed;
		}
		result += (X - C) / curSpeed;
	}
	cout << "Case #" << index + 1 << ": ";
	printf("%.7f", result);
	cout << endl;
}

int main(int argc, char **argv)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		solve(i);
	}
	return 0;
}