//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

typedef long long ll;    
ll tav[20];
ll rev( ll num ) { 
    ll res= 0; 
    while( num ) { 
	res = res * 10 + num % 10; 
	num /= 10; 
    }
    return res;
}
int sz(ll n) { 
    int ret = 0;
    while( n ) 
	ret += 1 , n/= 10;
    return ret;
}

ll solve() { 
    ll n;
    cin >> n; 
    ll ans = 1; 
    if( n % 10 == 0 ) { 
	n --; 
	ans++;
    }
    while( n > 10 ) { 
	if( n < 20 ) { 
	    ans += 10;
	    n -= 10; 
	    continue;
	}
	ll x = tav[ sz(n) / 2 ] ; 
	ans += n % x - 1; 
	n -= n % x - 1; 
	if( n != rev(n) ) 
	    n = rev( n ) , ans++;
	x = tav[ (sz(n)+1) / 2 ] ; 
	ans += n % x + 1; 
	n -= n % x + 1; 
    }
    ans += n % 10 - 1;
    return ans;
}

int main() { 
    tav[0] = 1;
    for( int i = 1 ;i < 15 ; i++ ) 
	tav[i] = tav[i-1] * 10;
    int t;
    cin >> t;
    for( int i = 1 ; i<= t ; i++ ) 
	cout << "Case #" << i << ": " << solve() << endl;
}
