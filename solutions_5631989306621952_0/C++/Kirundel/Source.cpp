#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#include <list>
#include <stack>
#include <bitset>
#include <cmath>
#include <ctime>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <sstream>
using namespace std;

int main()
{
	freopen("A-small-attempt0 (2).in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		string result ="";
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= result[0])
			{
				result = s[i] + result;
			}
			else
			{
				result += s[i];
			}
		}
		cout << "Case #"<<i+1<<": " << result << endl;
	}
	return 0;
}