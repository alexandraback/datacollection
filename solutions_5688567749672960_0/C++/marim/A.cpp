#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#define sz size()
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define fu(i,n) for(int i=0; i<(n); i++)
#define ALL(a) (a).begin(),(a).end()
#define cl(a,co) memset(a,co,sizeof a)
#define un(a) sort(ALL(a)),a.erase( unique(ALL(a)), a.end() )
typedef long long ll;
//istringstream is(s); is >> a;

using namespace std;

int ileTestow;

ll reverse(ll val){
	ll result = 0;
	for(int i=0; val > 0; i++){
		result = result * 10 + (val % 10);
		val /= 10;
	}
	return result;
}

int digits(ll val){
	ll tmp = 10L;
	fu(i,60){
		if( val < tmp ){
			return i+1;
		}
		tmp *= 10L;
	}
}

bool has_enough_digits(ll n, ll val){
	cerr << n << " : " << val << " # " << digits(n) << " : " << digits(val) << endl;
	return digits(n) <= digits(val);
}

ll pot(int ile){
	ll tmp = 1L;
	fu(a,ile){
		tmp*=10L;
	}
	return tmp;
}

ll brute(ll n, ll cur){
	ll result = n - cur;
	for(ll i=1; i<=pot( digits(n)/2 ); i++){
		ll tmp = cur + i;
		tmp = reverse( tmp );
		if( n >= tmp ){
			result = min(result, i + n - tmp + 1);
		}
	}
	return result;
}

int main(){

	scanf("%d",&ileTestow);

	for(int q=1; q<=ileTestow; q++){
		printf("Case #%d: ",q);
		
		ll n;
		cin >> n;

		ll cur = 1L;
		ll result = has_enough_digits(n,cur);

		while( !has_enough_digits(n, cur) ){
			int ile = digits(cur);
			int tmp = (ile + 1) / 2;
			ll val = pot(tmp);

			result += val - (cur % val) - 1;

			cur = reverse(cur);
			ll val2 = pot( ile/2 );
			result += val2 - (cur % val2) + 1;

			cur = pot(ile);
		}

		result += brute(n, cur);
				
		cout << result << endl;
	}

	return 0;
}
