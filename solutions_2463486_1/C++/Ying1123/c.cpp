#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int T;
long long A, B;
long long de[20];
int p1[20], p2[20];

inline long long sqr(long long x)
{
	return x * x;
}

inline int length(long long x)
{
	int s = 0;
	for (; x; ++s, x /= 10LL);
	return s;
}

inline bool palindrome(long long x)
{
	long long tmp = x;
	int l;
	for (l = 1; tmp; ++l, tmp /= 10LL)
		p1[l] = tmp % 10;
	--l;
	tmp = x;
	for (int i = l; tmp; --i, tmp /= 10LL)
		p2[i] = tmp % 10;
	for (int i = 1; i <= l; ++i)
		if (p1[i] != p2[i]) return false;
	return true;
}

inline long long extend_odd(long long x)
{
	long long tmp = x;
	int l;
	for (l = 1; tmp; ++l, tmp /= 10LL)
		p1[l] = tmp % 10;
	--l;
	
	for (int i = 2; i <= l; ++i) x = x * 10 + p1[i];
	return x;
}

inline long long extend_even(long long x)
{
	long long tmp = x;
	int l;
	for (l = 1; tmp; ++l, tmp /= 10LL)
		p1[l] = tmp % 10;
	--l;
	
	for (int i = 1; i <= l; ++i) x = x * 10 + p1[i];
	return x;
}

int main()
{
	de[0] = 1LL;
	for (int i = 1; i <= 15; ++i) de[i] = de[i - 1] * 10LL;
	
	scanf("%d",&T);
	for (int i = 1; i <= T; ++i)
	{
		printf("Case #%d: ", i);
		
		cin >> A >> B;
		int l1 = length(A);
		int l2 = length(B);
		l1 = (length((long long)(sqrt(A))) - 1) / 2;
		l2 = (length((long long)(sqrt(B)) + 1) - 1) / 2 + 1;
		// l1 = (l1 - 1) >> 2;
		// l2 = (l2 + 1) >> 2;
		
		long long ans = 0;
		for (long long i = de[l1]; i < de[l2]; ++i)
		{
			long long tmp = sqr(extend_odd(i));
			if (tmp > B) continue;
			if (tmp >= A && palindrome(tmp)) ++ans;
			
			tmp = sqr(extend_even(i));
			if (tmp < A || tmp > B) continue;
			if (palindrome(tmp)) ++ans;
		}
		cout << ans << endl;
	}
	return 0;
}
