#include "stdafx.h"
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

const int sz = 1000000;
int nums[sz+1];

void pre_compute()
{
	int r, j;
	for (int i = 1; i <= sz; ++i) nums[i] = i;
	for (int i = 1; i < sz; ++i)
	{
		cout << i << endl;
		nums[i+1] = min(nums[i+1], nums[i]+1);
		r = 0;
		j = i;
		while (j != 0)
		{
			r *= 10;
			r += j%10;
			j /= 10;
		}
		nums[r] = min(nums[r], nums[i]+1);
	}
	ofstream out("nums.txt");
	for (int i = 1; i <= sz; ++i)
	{
		out << nums[i] << endl;
	}
	out.close();
}

int counter(int N)
{
	int ans;
	ifstream in("nums.txt");
	for (int i = 1; i <= N; ++i) in >> ans;
	in.close();
	return ans;
}

int main(int argc, char* argv[])
{
	//pre_compute();

	ifstream in("A-small-attempt0.in");
	ofstream out("result.txt");
	int T;
	int N;
	in >> T;
	for (int i = 0; i < T; ++i)
	{
		in >> N;
		out << "Case #" << i+1 << ": " << counter(N) << endl;
		cout << i+1 << endl;
	}

	in.close();
	out.close();
	return 0;
}