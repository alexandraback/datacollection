#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <cmath>
#include <functional>
#include <stack>
#include <set>
#include <iostream>

using namespace std;

char buf[20];
int was[3000000];

int main()
{
	int ten[10] = {1};
	for (int i = 1; i < 10; ++i)
	{
		ten[i] = ten[i-1] * 10;	
	}
	ifstream ifs("c.in");
	ofstream ofs("c.out");
	int t;
	ifs >> t;
	int base = 0;
	for (int test = 0; test < t; ++test)
	{
		int a, b, cnt = 0;
		ifs >> a >> b;
		for (int i = a; i < b; ++i)
		{
			++base;
			int num = i;
			int len = 0;
			while (num > 0)
			{
				buf[len++] = num % 10;
				num /= 10;
			}
			num = i;
			for (int k = len-1; k >= 1; --k)
			{
				num -= buf[k]*ten[len-1];
				num = num*10+buf[k];
				if (num >= a && num <= b && num > i && num >= ten[len-1] && was[num] != base)
				{
					++cnt;
					was[num] = base;
				}
				
			}
		}
		ofs << "Case #" << test+1 << ": " << cnt << endl;
	}
	return 0;
}
