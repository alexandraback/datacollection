#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 1000;
double pts[size];
const int iter = 100;

bool check(int n, int num, double p)
{
	double have = 1 - p;
	for (int i = 0; i < n; i++)
		if (i != num)
			have -= max(0.0, pts[num] + p - pts[i]);
	return have < 0;
}

int main() {
	int tc, n;
	double lb, rb, mid;

	freopen("problem_a.in", "r", stdin);
	freopen("problem_a.out", "w", stdout);
	
	cin >> tc;
	cout.precision(20);
	for (int t = 0; t < tc; t++)
	{
		cin >> n;
		double sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> pts[i];
			sum += pts[i];
		}
		for (int i = 0; i < n; i++)
			pts[i] /= sum;
		cout << "Case #" << t + 1 << ": ";
		for (int i = 0; i < n; i++)
		{
			lb = 0;
			rb = 1;
			for (int j = 0; j < iter; j++)
			{
				mid = (lb + rb) / 2;
				if (check(n, i, mid))
					rb = mid;
				else
					lb = mid;
			}
			cout << (lb + rb) * 100 / 2 << ' ';
		}
		cout << endl;
	}

	return 0;
}