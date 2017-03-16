#include <iostream>
#include <vector>
using namespace std;


long long mod = 1e9;
long long inf = 1e9;
struct BigInteger// Note, value[i] may be negative
{
	vector <long long> value;
	void normalize() {
		long long x = 0;
		for (int i = 0; i < value.size(); i++)
		{
			value[i] += x;
			x = value[i] / mod;
			value[i] %= mod;
		}
		if (x != 0)
			value.push_back(x);
		while (value.size() && value.back() == 0)
			value.pop_back();
		return;
	}
	BigInteger() : value() {}
	BigInteger(long long x) { value.push_back(x); normalize(); }
	BigInteger operator + (BigInteger Oth)
	{
		BigInteger ans = BigInteger();
		int len = max(value.size(), Oth.value.size() );
		ans.value.resize(len, 0);
		for (int i = 0; i < len; i++)
		{
			if (value.size() > i)
				ans.value[i] += value[i];
			if (Oth.value.size() > i)
				ans.value[i] += Oth.value[i];
		}
		ans.normalize();
		return ans;
	}
	BigInteger operator * (BigInteger Oth)
	{
		BigInteger ans = BigInteger();
		int len = value.size() + Oth.value.size();
		ans.value.resize(len, 0);
		for (int i = 0; i < value.size(); i++)
		{
			for (int j = max( (int) Oth.value.size() + (int) value.size() - i - 100 , 0); j < Oth.value.size(); j++)
			{
				ans.value[i + j] += value[i] * Oth.value[j];
			}
		}
		ans.normalize();
		return ans;
	}
	BigInteger negate()
	{
		BigInteger ans = BigInteger();
		ans.value.resize(value.size() );
		for (int i = 0; i < value.size(); i++)
			ans.value[i] = -value[i];
		return ans;
	}
	BigInteger operator - (BigInteger Oth)
	{
		return *this + Oth.negate();
	}
	bool operator < (const BigInteger &Oth) const
	{
		int len = value.size();
		int othLen = Oth.value.size();
		if (len > othLen)
		{
			return value.back() < 0;
		}
		if (len < othLen)
		{
			return Oth.value.back() > 0;
		}
		for (int i = len - 1; i >= 0; i--)
		{
			if (value[i] != Oth.value[i] )
				return value[i] < Oth.value[i];
		}
		return false;
	}
	bool operator > (const BigInteger &Oth) const
	{
		return Oth < *this;
	}
	bool operator == (const BigInteger &Oth) const
	{
		return !(*this < Oth || *this > Oth);
	}
	bool operator != (const BigInteger &Oth) const
	{
		return !(*this == Oth);
	}
	void shift(int k)
	{
		for (int i = k; i < value.size(); i++)
			value[i - k] = value[i];
		for (int i = 0; i < k; i++)
			value.pop_back();
	}
};



bool test1(long long R, long long V, long long cnt)
{
	if (cnt <= 1)
		return true;
	BigInteger S1 = BigInteger(2LL) * BigInteger(R) * BigInteger(cnt);
	if (S1 > V)
		return false;
	BigInteger S2 = (BigInteger(1) + BigInteger(2) * BigInteger(cnt - 1) ) * BigInteger(cnt);
	if (S2 > BigInteger(V) )
		return false;
	return !(S1 + S2 > BigInteger(V) );
}
bool test(long long R, long long V, long long cnt)
{
	long long x = R + 1, val = 0;
	for (int i = 0; i < cnt; i++)
	{
		val += x * x - (x - 1) * (x - 1);
		x += 2;
	}
	return val <= V;

}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		long long R, V;
		scanf("%lld %lld", &R, &V);

		unsigned long long l = 1, r = 1e18;

		while (r - l > 1)
		{
			unsigned long long m = (r + l) / 2;
			/*if (m == 2)
			{
				int dskf = 0;
			}*/
			//bool good = test(R, V, m);
			bool good1 = test1(R, V, m);
			/*if (good != good1)
			{
				printf("%lld %lld %llu\n\n", R, V, m);
			}*/
			if (good1)
				l = m;
			else
				r = m;
		}

		printf("Case #%d: %lld\n", t + 1, l);
	}


	return 0;
}