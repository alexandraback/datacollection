#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <cmath>

#define S(x) scanf("%d",&x)
#define P(x) printf("%d\n",x)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
using namespace std;

typedef long long int ll;
typedef vector<int > VI;
int A[10000005];

bool isPalindrome(ll n) {
	ll x=0;
	ll a=n;
	while(n) {
		x=x*10+(n%10);
		n/=10;
	}
	if(x == a) return true;
	return false;
} 

int main() {
	int T;
	rep(i,1,10000001) {
		if(isPalindrome((ll)i) && isPalindrome((ll)i*(ll)i))
			A[i]=1;
		A[i]+=A[i-1];
	}
	S(T);
	int c=0;
	while(T--) {
		c++;
		ll a,b;
		ll x,y;	
		scanf("%lld%lld",&a,&b);
		x=(ll)sqrt(a);
		if(x*x < a) x++;
		y=(ll)sqrt(b);
		printf("Case #%d: %d\n",c,A[y]-A[x-1]);
	}
	return 0;
}
