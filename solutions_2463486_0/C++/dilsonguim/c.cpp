#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdint.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

//#define NDEBUG
#if defined(NDEBUG)
#define DBG_CODE(cb...)
#else
#define DBG_CODE(cb...) cb
#endif
#define WRITE(x) DBG_CODE(cout << x << endl)
#define WATCH(x) DBG_CODE(cout << #x << "=" << x << endl)
#define FORN(i, a, b) for(typeof(b) i = (a); i < (b); i++)
#define ALL(x) x.begin(), x.end()
#define FOREACH(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

typedef long long ll;
vector<ll> fs;

bool ispalindrome(ll n)
{
	static vector<ll> digits;
	digits.clear();

	while(n){
		digits.push_back(n % 10ll);
		n /= 10ll;
	}

	FORN(i, 0, digits.size() / 2){
		if(digits[i] != digits[digits.size() - i - 1]) return false;
	}
	return true;
}

void gen()
{
	FORN(i, 0ll, 100000000ll){
		if(ispalindrome(i)){
			ll x = i * i;
			if(ispalindrome(x)){
				fs.push_back(x);
			}
		}
	}
}

int howmany(ll a, ll b)
{
	int count = 0;
	FOREACH(x, fs){
		if(a <= *x and *x <= b) count++;
	}
	return count;
}

int main(){
	gen();
	int ntc;
	scanf("%d", &ntc);
	FORN(tc, 0, ntc){
		ll a, b;
		scanf("%lld%lld", &a, &b);
		int sol = howmany(a, b);
		printf("Case #%d: %d\n", tc + 1, sol);	
	}
}
