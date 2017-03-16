#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;
int e, r, n;
int a[10010];
int gain;
int Max;
int now;
void fun(int k)
{
	if (k == n)
	{
		if (gain > Max)
			Max = gain;
		return;
	}
	int i;
	int tmp;
	for (i = 0;i <= now;i++)
	{
		gain += i * a[k];
		tmp = now;
		now = now - i + r;
		if (now > e)
			now = e;
		fun(k+1);
		gain -= i * a[k];
		now = tmp;
	}
}

int main()
{
	//ifstream infile("test.in");
	ifstream infile("B-small-attempt0.in");
	//ifstream infile("B-small-attempt1.in");
	//ifstream infile("B-large.in");
	ofstream outfile("B.out", ios::out);
	int T;
	infile >> T;
	int testcase;
	for (testcase = 1;testcase <= T;testcase++)
	{

		infile >> e >> r >> n;

		int i;
		for (i = 0;i < n;i++)
		{
			infile >> a[i];
		}

		gain = 0;
		Max = -1;
		now = e;
		fun(0);

		outfile << "Case #" << testcase << ": ";
		outfile << Max;
		outfile << endl;
	}
	return 0;
}