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

#define FILE_NAME "A-small"

using namespace std;

char vow[] = "aeiou";
bool isVow(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

long long go(string& s, int k)
{
	long long n = s.length();
	int cnt = 0;
	for(long long i = 0; i < n; ++i)
	{
		if(isVow(s[i]))
			cnt = 0;
		else
			++cnt;
		if(cnt == k)
		{
			s = string(s.begin() + (i - k + 2), s.end());
			return (n-i)*(i-k+2);
		}
	}
	s = "";
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
		while(s.length() > 0)
		{
			res += go(s, k);
		}

		cout << "Case #" << Case << ": " << res << endl;
	}

	return 0;
}
