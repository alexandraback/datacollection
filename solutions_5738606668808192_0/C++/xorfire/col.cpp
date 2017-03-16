#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define int long long


#undef int
int main()
{
#define int long long
	cout << "Case #1:\n";
	int t = 50;
	for (int msk = 1; msk < 1 << 15; msk += 2)
	{
		int le = msk + (1 << 15);
		bool yes = true;
		for (int i = 0; i < 16; i++)
			if (le >> i & 1)
			{
				if (le >> (i + 1) & 1) i++;
				else yes = false;
			}
		if (yes)
		{
			for (int i = 0; i < 16; i++)
				cout << (le >> i & 1);
			cout << " ";
			for (int i = 2; i <= 10; i++)
				cout << i + 1 << " \n"[i == 10];
			t--;
		}
		if (!t) break;
	}
	return 0;
}