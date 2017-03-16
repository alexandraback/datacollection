#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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

using namespace std;

long long gcd(long long a, long long b)
{
	if(!b)
		return a;

	return gcd(b, a % b);
}


long long toLong(string p)
{
	int n = p.size();
	reverse(p.begin(), p.end());
	
	long long ans = 0;
	long long X = 1LL;

	for(int i = 0; i < n; i++)
	{
		ans += (p[i]-'0') * X;
		X *= 10;
	}

	return ans;
}

int convert(string s, long long & a, long long & b)
{
	int n = s.size();
	string p = "";

	for(int i = 0; i < n; i++)
	{
		if(s[i] == '/')
		{
			a = toLong(p);
			p = "";
		}
		else
			p += s[i];
	}

	b = toLong(p);

	return 0;
}


int main()
{

	int TC;
	cin >> TC;

	for(int test = 1; test <= TC; test++)
	{		
		long long a, b;
		string s;

		cin >> s;

		convert(s, a, b);

		long long g = gcd(a,b);
		a /= g;
		b /= g;

		int ans = 0;

		cout <<  "Case #" << test << ": ";

		if((b & (b-1)) != 0)
			cout << "impossible" << "\n";
		else
		{
			while(a < b)
			{
				b >>= 1;
				ans++;
			}

			cout << ans << "\n";
		}

	}

	return 0;
}