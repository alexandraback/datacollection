#include <bits/stdc++.h>
using namespace std;
const int MAXN = 340000008;
bitset <MAXN> ps;
vector <int> primes;
struct coin
{
	string mask;
	vector <long long int> div;
};
vector <coin> A,B;
string s_of(int mask, int len)
{
	string ret = "";
	for (int i = len-1; i >= 0; --i)
		if(mask & (1<<i))
			ret+='1';
		else
			ret+='0';
	return ret;
}
coin get_coin(int mask, int len)
{
	coin ret;
	ret.mask = s_of(mask,len);
	ret.div.clear();
	for (int base = 2; base <= 10; ++base)
	{
		long long int val = 0;
		for (int i = len-1; i >= 0; --i)
		{
			val*=base;
			if(mask & (1<<i))
				val++;
		}
		bool is_p = true;
		for (int i = 0; i < primes.size() && is_p; ++i)
		{
			long long int p = primes[i];
			if(p*p > val)
				break;
			if(val%p == 0)
			{
				is_p = false;
				ret.div.push_back(p);
			}
		}
		if(is_p)
		{
			ret.mask = "--";
			return ret;
		}
	}
	return ret;
}
coin compatible(coin &x, coin &y, int len)
{
	coin ret;
	ret.mask = x.mask + y.mask;
	ret.div.clear();
	for (int base = 2; base <= 10; ++base)
	{
		long long int v1 = 0, v2 = 0;
		for (int i = 0; i < len; ++i)
		{
			v1 = v1*base + (x.mask[i] - '0');
			v2 = v2*base + (y.mask[i] - '0');
		}
		long long int g = __gcd(v1,v2);
		if(g == 1)
		{
			ret.mask = "--";
			return ret;
		}
		ret.div.push_back(g);
	}
	return ret;
}
int main()
{
	// sieve
	for (long long int i = 2; i < MAXN; ++i)
	{
		if(!ps[i])
		{
			primes.push_back(i);
			for (long long int j = i*i; j < MAXN; j+=i)
				ps[j] = 1;
		}
	}
	//
	for (int mask = (1<<15)+1; A.size() < 50 || B.size() < 500; mask+=2)
	{
		assert(mask < (1<<16));
		coin temp = get_coin(mask,16);
		if(temp.mask[0] == '-')
			continue;
		A.push_back(temp);
		for (int i = 0; i < A.size(); ++i)
		{
			coin t2 = compatible(A[i],temp,16);
			if(t2.mask[0] != '-')
				B.push_back(t2);
		}
	}
	// copy to small.out
	for (int i = 0; i < min(50,(int)A.size()); ++i)
	{
		cout<<A[i].mask<<" ";
		for (int j = 0; j < 9; ++j)
			cout<<A[i].div[j]<<" ";
		cout<<"\n";
	}
	// copy to large.out
	for (int i = 0; i < min(500,(int)B.size()); ++i)
	{
		cout<<B[i].mask<<" ";
		assert(B[i].div.size() == 9);
		for (int j = 0; j < 9; ++j)
			cout<<B[i].div[j]<<" ";
		cout<<"\n";
	}
	return 0;
}
