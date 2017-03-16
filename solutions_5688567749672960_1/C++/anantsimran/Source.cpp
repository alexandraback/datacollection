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

string construct(int n)
{
	string ret;
	for (size_t i = 0; i < n-1; i++)
	{
		ret.push_back('9');
	}
	return ret;
}

string construct2(int n)
{
	string ret;
	ret.push_back('1');
	for (size_t i = 0; i < n - 1; i++)
	{
		ret.push_back('0');
	}
	return ret;
}


ll calculate(string str)
{
	if (str.size()==1)
	{
		return str[0] - '0';
	}
	if (str.back()=='0')
	{
		ll x = stoull(str);
		x--;
		return 1+calculate(to_string(x));
	}
	ll ans = 1+calculate(construct(str.size()));
	string comp = construct2(str.size());
	ll bas = 1;
	ll ans2 = 1;
	reverse(comp.begin(), comp.end());
	for (size_t i = 0; i < str.size()/2; i++)
	{
		ans2 += (str[i] - comp[i]) * bas;
		comp[i] = str[i];
		bas *= 10;
	}
	ans2 += stoull(str) - stoull(comp);
	comp = construct2(str.size());
	ans += min(ans2, stoll(str) - stoll(comp));
	return ans;


}




int main()
{
	int t, ans;
	int cas = 1;
	in(t);
	string n;
	while (t--)
	{
		in(n);
		ans = calculate(n);
		printf("Case #%d: %d\n", cas,ans);
		cas++;
	}
	return 0;
}
