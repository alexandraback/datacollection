#pragma region Saaman


/*

This code is exclusive property of Anant Simran Singh.
Any use without his consent will result in copyright violation.

*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS 
#define getchar_unlocked() getchar()
#endif 
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<set>
#include<map>
#include<utility>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<string>
#include<climits>
#include<bitset>
#include<cfloat>
#include<sstream>
#include<iomanip>
#include<array>
#include<unordered_set>
#include<unordered_map>
#include<limits>
using namespace std;
const int maximum_string_length = (int)1e4 + 5;
inline void in(char &d)
{
	d = getchar_unlocked();
	while ((d<33) || (d>126))
	{
		d = getchar_unlocked();
	}
}
inline void in(string &str)
{
	str.clear();
	str.reserve(maximum_string_length);
	char c = getchar_unlocked();
	while ((c<33) || (c>126))
	{
		c = getchar_unlocked();
	}
	while ((c >= 33) && (c <= 126))
	{
		str.push_back(c);
		c = getchar_unlocked();
	}
	return;
}
template<typename T>
inline void in(T & t){
	char c, m = 0;
	t = 0;
	c = getchar_unlocked();
	while ((c<'0' || c>'9') && c != '-')
		c = getchar_unlocked();
	if (c == '-')
		m = 1,
		c = getchar_unlocked();

	while (c >= '0' && c <= '9'){
		t = (t << 3) + (t << 1) + c - '0';
		c = getchar_unlocked();
	}
	if (m)
		t = 0 - t;	
	}
template <typename T>
int signum(T val) {
	return (T(0) < val) - (val < T(0));

}
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
#pragma endregion

const int maxn = (int)1e6 + 5;

int dp[maxn];

int calculate(int x)
{
	if (dp[x] != -1)
	{
		return dp[x];
	}
	string s = to_string(x);
	reverse(s.begin(), s.end());	
	int rev = stoi(s);
	if ((s[0] == '0') || (rev>=x))
	{
		dp[x] = calculate(x - 1) + 1;
		return dp[x];
	}
	dp[x]= min(calculate(x - 1)+1, calculate(rev)+1);
	return dp[x];
}

int main()
{
	int t, n,ans;
	for (size_t i = 0; i < maxn; i++)
	{
		dp[i] = -1;
	}
	dp[0] = 0;
	dp[1] = 1;
	int cas = 1;
	in(t);
	while (t--)
	{
		in(n);
		ans = calculate(n);
		printf("Case #%d: %d\n", cas,ans);
		cas++;
	}
	return 0;
}
