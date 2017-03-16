#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <string>


using namespace std;


int a[146];
set<long long> s;


bool isPalindrome(long long n)
{
	vector<int> v;
	while(n != 0)
	{
		v.push_back(n % 10);
		n /= 10;
	}
	for(int i = 0; i < v.size(); i++)
		if(v[i] != v[v.size() - i - 1])
			return false;
	return true;
}


long long getOddPalindrome(int l)
{
	for(int i = 0; i < l - 1; i++)
	{
		a[2 * l - i - 2] = a[i];
	}
	long long res = 0;
	for(int i = 0; i < 2 * l - 1; i++)
		res = res * 10 + a[i];
	return res;
}


long long getEvenPalindrome(int l)
{
	for(int i = 0; i < l; i++)
		a[2 * l - i - 1] = a[i];
	long long res = 0;
	for(int i = 0; i < 2 * l; i++)
		res = res * 10 + a[i];
	return res;
}


vector<long long> v;


int main()
{
	freopen("input.txt","r",stdin);
	freopen("outpu1t.txt","w",stdout);
	for(int i = 1; i <= 30000; i++)
	{
		int l = 0;
		int xx = i;
		while(xx != 0)
		{
			a[l++] = xx % 10;
			xx /= 10;
		}
		reverse(a, a + l);
		long long x = getOddPalindrome(l);
		if(isPalindrome(x * x))
			s.insert(x);
		x = getEvenPalindrome(l);
		if(isPalindrome(x * x))
			s.insert(x);
	}
	for(set<long long>::iterator it = s.begin(); it != s.end(); it++)
		v.push_back(*it * *it);
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		long long a, b;
		scanf("%lld %lld", &a, &b);
		int ans = lower_bound(v.begin(), v.end(), b + 1) - lower_bound(v.begin(), v.end(), a);
		printf("Case #%d: %d\n", i + 1, ans);
	}
}