#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;
typedef unsigned long long ll;

bool isPalindroms(const char* buf)
{
	int len = strlen(buf);
	for(int i=0;i<len/2;i++)
	{
		if(buf[i]!=buf[len-1-i])
			return false;
	}
	return true;
}

bool isPalindroms(ll n)
{
	char buf[128];
	sprintf(buf, "%lld", n);
	return isPalindroms(buf);
}

bool isSq(ll n)
{
	int r = (ll)(sqrt(double(n))+0.5f);
	return r*r == n;
}

ll arr[10000];
int n;

template<typename T>
const T* MLB(const T* const b, const T* const e, const T& v)
{
	if(b>=e) return e;

	const T* bb = b;
	const T* ee = e;
	while(ee-bb>2)
	{
		const T* mm = bb+(ee-bb)/2;
		if(*mm<v)
		{
			bb = mm + 1;
		}
		else // v<=*p
		{
			ee = mm + 1;
		}
	}

	for(const T* p = bb; p<ee;p++)
	{
		if(v<=*p)
		{
			return p;
		}
	}
	return e;
}

template<typename T>
const T* LUB(const T* const b, const T* const e, const T& v)
{
	if(b>=e) return b-1;

	const T* bb = b;
	const T* ee = e;
	while(ee-bb>2)
	{
		const T* m = bb+(ee-bb)/2;
		if(*m<=v)
		{
			bb = m;
		}
		else // v<*p
		{
			ee = m;
		}
	}

	for(const T* p = ee-1; p>=bb;p--)
	{
		if(*p<=v)
		{
			return p;
		}
	}
	return b-1;
}

int main()
{
	for(ll i=1;i<=10000000;i++)
	{
		ll a = i;
		ll b = i*i;
		if(isPalindroms(a) && isPalindroms(b))
		{
			arr[n++] = b;
		}
	}

	int T;
	scanf("%d",&T);
	for(int kcase = 1; kcase <=T; kcase++)
	{
		ll A,B;
		scanf("%lld%lld",&A,&B);
		const ll* p1 = MLB(arr, arr+n, A);
		const ll* p2 = LUB(arr, arr+n, B);
		printf("Case #%d: %d\n", kcase, p2 - p1 + 1);
	}
}
