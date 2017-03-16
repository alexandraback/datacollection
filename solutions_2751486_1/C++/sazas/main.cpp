#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define FILE_NAME "A-large"

using namespace std;

char vow[] = "aeiou";
bool isVow(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

long long go(string& s, int k, int& start)
{
	long long n = s.length();
	int cnt = 0;
	for(long long i = start; i < n; ++i)
	{
		if(isVow(s[i]))
			cnt = 0;
		else
			++cnt;
		if(cnt == k)
		{
			start = i - k + 2;
			return (n-i)*(i-k+2);
		}
	}
	start = n;
	return 0;
}

int main()
{
	freopen(FILE_NAME ".in", "r", stdin);
	freopen(FILE_NAME ".out", "w", stdout);
	
	int numTestCaces = 0;
	cin >> numTestCaces;
	for(int Case = 1; Case <= numTestCaces; ++Case)
	{
		string s;
		int k;
		cin >> s >> k;
		int n = s.length();
		long long res = 0;
		int start = 0;
		while(start < n)
		{
			res += go(s, k, start);
		}

		cout << "Case #" << Case << ": " << res << endl;
	}

	return 0;
}
