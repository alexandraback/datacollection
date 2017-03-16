#include <iostream>
#include <stdio.h>
#include <numeric>
#include <queue>
#include <string>
#include <cmath>
#include <vector>
#include <deque>
#include <iomanip>
#include <set>
#include <queue>
#include <bitset>
#include <iomanip>
#include <map>
#include <string.h>
#include <stack>
#include <algorithm>

#include <unordered_map>
#include <unordered_set>

using namespace std;

long long get_value(int bitmap , int base)
{	
	long long ans = 0;
	for (int i = 15;i >= 0;i --)
	{
		if (bitmap & (1 << i))
			ans = ans * base + 1;
		else
			ans = ans * base;
	}
	return ans;
}

long long check(long long value)
{
	for (long long i = 2;i * i <= value;i ++)
	{
		if (value % i == 0)
			return i;
	}
	return - 1;
}

void to_binary_string(int bitmap)
{
	for (int i = 15;i >= 0;i --)
	{
		if (bitmap & (1 << i))
			cout << "1";
		else
			cout << "0";
	}
}

int main()
{
//	freopen("E:\\C-small-attempt0.in" , "r" , stdin);
//	freopen("E:\\out.txt" , "w" , stdout);

	int t , n , i , j , base , cnt = 0;
	scanf("%d" , &t);
	scanf("%d%d" , &n , &j);
	printf("Case #1:\n");
	for (i = 0;i < (1 << n) && cnt < j;i ++)
	{
		// the first and the last
		if ((i & (1 << 0)) && (i & (1 << (n - 1))))
		{
			vector<long long> temp;
			for (base = 2;base <= 10;base ++)
			{
				long long value = get_value(i , base);
				long long result = check(value);
				if (result < 0)
					break;
				else
					temp.push_back(result);
			}
			if (temp.size() == 9)
			{
				cnt ++;
				// the i to bitmap
				to_binary_string(i);
				for (int a = 0;a < temp.size();a ++)
					cout << " " << temp[a];
				cout << endl;
			}
		}
	}
	return 0;
}


