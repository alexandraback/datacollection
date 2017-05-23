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

bool rez[1001];

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
	fill(&rez[0], &rez[1001], false);
	for (int i = 1; i < 1000; ++i)
		if (i*i < 1001 && isPalindrome(to_string<int>(i)) && 
			isPalindrome(to_string<int>(i*i))) rez[i*i] = 1;
	freopen("Fair and Square.in","r",stdin);
	freopen("Fair and Square.out","w",stdout);
	//program
	int tests;
	scanf("%d\n", &tests);
	for (int Case = 1; Case <= tests; Case++)
	{
		scanf("%d %d", &a, &b);
		int res = 0;
		for (int i = a; i <= b; ++i) if (rez[i]) res++;
		printf("Case #%d: %d\n", Case, res);
	}
	//end program
	return 0;
}






