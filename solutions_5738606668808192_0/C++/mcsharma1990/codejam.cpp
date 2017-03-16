
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
#include <memory.h>
#include <cassert>

using namespace std;

#define ford(i, a, b, c)        for(int i=(a); i<(b); i+=(c))
#define fori(i, a, b)           ford(i,a,b,1)
#define rep(i, n)               fori(i,0,n)
#define ifor(i, a, b)           for(int i=(a); i>=(b); i--)
#define iter(i, a)              for(typeof(a.begin()) i=(a).begin(); i!=(a).end(); i++)
#define si(x)                   ((int)x.size())
#define SS                      ({int x;scanf("%d",&x);x;})
#define pb                      push_back
#define mp                      make_pair
#define all(a)                  a.begin(),a.end()
#define fill(a, v)              memset(a, v, sizeof(a))
#define inf                     (int)1e9
#define linf                    (long long)1e18
#define V                       vector
#define S                       string
#define XX                      first
#define YY                      second
#define P(v)                    rep(i, si(v)) cout<<v[i]<<" "; puts("")

typedef V<int> vi;
typedef V<S> vs;
typedef long long ll;
typedef pair<int,int> pii;


ll mulmod(ll a, ll b, ll mod)
{
    ll x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {    
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}

/* 
 * modular exponentiation
 */
ll modulo(ll base, ll exponent, ll mod)
{
    ll x = 1;
    ll y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}
 
/*
 * Miller-Rabin primality test, iteration signifies the accuracy
 */
bool Miller(ll p,int iteration)
{
    if (p < 2)
    {
        return false;
    }
    if (p != 2 && p % 2==0)
    {
        return false;
    }
    ll s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (int i = 0; i < iteration; i++)
    {
        ll a = rand() % (p - 1) + 1, temp = s;
        ll mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
        {
            return false;
        }
    }
    return true;
}

ll interpret(int x, int b) {
	ll ans = 0;
	while (x) {
		ans = ans * b + (x % 2);
		x /= 2;
	}
	return ans;
}

int ff(ll n) {
	if (n%2==0) return 2;
	int x = 3;
	while (n % x != 0) x += 2;
	return x;
}

int main() {
//	cout<<interpret(32789, 8)<<" "<<Miller(interpret(32789, 8), 15)<<endl;
	
	int n = 16, j = 70;
	vi ans;
	ford(i, (1<<(n-1)) + 1, 1<<n, 2) {
		int isJamcoin = 1;
		fori(b, 2, 11) {
			if (Miller(interpret(i, b), 5)) {
				isJamcoin = 0;
				break;
			}
		}
		if (isJamcoin) {
			ans.pb(i);
			if (si(ans) == j) break;
		}
	}
	cout<<"Case #1:\n";
	int arr[] = {3, 7, 9, 22, 27, 32, 33, 35};
	int cc = 0;
	rep(i, si(ans)) {
		if (count(arr, arr+8, i)) continue;
		vi v = vi();
		fori(b, 2, 11) {
			ll numInBase = interpret(ans[i], b);
			int factor = ff(numInBase);
//			cout <<numInBase<<" factor is: "<<factor<<endl;
			v.pb(factor);
		}
		int num = ans[i];
		S binStr = "";
		while (num) {
			binStr += '0' + (num % 2);
			num /= 2;
		}
		cout<<(++cc)<<" "<<binStr<<" ";
		rep(i, si(v)) {
			cout<<v[i]<<" ";
		}
		puts("");
	}
}


