#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
const long long MAX_LEN = 111111111;
int is_cons(char ch)
{
	return ch != 'a' &&
		   ch != 'e' &&
		   ch != 'i' &&
		   ch != 'o' &&
		   ch != 'u';
}
ll ANS()
{
	string s;
	cin >> s;
	ll n;
	cin >> n;
	if (s.size() < n)
		return 0;
	ll  start = 0;
	ll cur = 0;
	ll ans = 0;
	for(int i = 0; i < n; i++)
	{
		cur += is_cons(s[i]);
	}
	for (int i = n - 1; i < s.size(); i++)
	{
		if (i == n - 1)
		{
			if (cur == n)
			{
				ans += s.size() - n + 1;
				start = i - n + 2;
			}
		}
		else
		{
			cur -= is_cons(s[i - n]);
			cur += is_cons(s[i]);
			if (cur == n)
			{
				ans += ((i - n + 1) - start + 1) * (s.size() - i);
				start = i - n + 2;
			}
		}
	}
	return ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int TESTS;
	cin >> TESTS;
	for (int TEST = 1; TEST <= TESTS; TEST++)
	{
		cout << "Case #" << TEST << ": " << ANS() << endl;
	}
	return 0;
}