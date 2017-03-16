#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>

template <class T>
inline std::string to_string (const T& t)
{
	std::stringstream ss;
	ss << t;
	return ss.str();
}

#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld epsylon = 1e-9;
typedef unsigned int ui;

inline long double get_time(){   
	return (long double)clock()/CLOCKS_PER_SEC;
};
bool isPalindrome(string &s)
{
	for (int i = 0, j = s.length() - 1; i < s.length()/2; ++i, --j)
		if (s[i] != s[j]) return false;
	return true;
}

int a, b;

int main()
{
	freopen("Fair and Square numbers under 10^14.txt", "w", stdout);
	for (long long i = 1; i < 20000000; ++i)
	{
		long long num = i*i;
		if (isPalindrome(to_string<long long>(i)) && 
			isPalindrome(to_string<long long>(num))) 
		{
			printf("%lld\n", num);
		}
	}
	fclose(stdout);
	return 0;
}






