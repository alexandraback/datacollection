#include <iostream>
#include <set>
#include <cmath>
#include <ctime>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <functional>
#include <sstream>
#include <utility>
#include <algorithm>

using namespace std;

bool mas[1000000];
int arr[26] = {0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1};

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, m = 0, k = 0, ans = 0, length;
		char c;
		string s;
		cin >> s >> n;
		
		length = s.size();

		for (int j = 0; j < length; j++)
		{
			if (arr[s[j] - 'a']) mas[j] = 1;
			else mas[j] = 0;
		}

		for (int j = 0; j < length; j++)
		{
			if (mas[j]) 
			{
				m++;
				if (m == n)
				{
					int a, b;
					a = length - j - 1;
					b = j - m + 1 - k;
					ans += a + b + a * b + 1;
					k = j - m + 2;
					m--;
				}
			}
			else m = 0;
		}
		cout << "Case #" << i + 1 << ": " << ans << endl; 
	}
	return 0;
}