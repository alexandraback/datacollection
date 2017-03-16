#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <limits>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = numeric_limits<int>::max();

const int maxdigits = 20;

ll sqr(ll x) { return x*x; }

bool palindrome(ll x)
{
	int digits[maxdigits];
	int d;
	for(d=0; x>0; d++)
	{
		digits[d] = x % 10;
		x /= 10;
	}
	for(int i=0,j=d-1; i<j; i++,j--)
		if(digits[i] != digits[j])
			return false;
	return true;
}

int main(int argc,char* argv[])
{
	vector<ll> fsnums;
	for(ll i=0; i<=1e7; i++)
	{
		ll x = sqr(i);
		if(palindrome(i) && palindrome(x))
		{
			fsnums.push_back(x);
			//printf("%lld %lld\n", i, x);
		}
	}
	
	int num_test_cases;
	scanf("%d",&num_test_cases);
	for(int test_case=1; test_case<=num_test_cases; test_case++)
	{
		ll a, b;
		scanf("%lld%lld", &a, &b);
		ll count = 0;
		for(int i=0;i<fsnums.size();i++)
			if(fsnums[i] >= a && fsnums[i] <= b)
				count++;
		printf("Case #%d: %lld\n",test_case,count);
	}
	return 0;
}
