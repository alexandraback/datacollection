#include <iostream>
#include <stdio.h>
#include <math.h>
#include <list>
#include <queue>
#include <vector>
#include <functional>
#include <stack>
#include <utility> 
#include <stdlib.h>
#include <map>
#include <string.h>
#include <algorithm>
typedef long long int ll;
#define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))
#define CLR(a) memset(a, 0, sizeof(a))
using namespace std;
ll gcdr ( ll a, ll b )
{
  if ( a==0 ) return b;
  return gcdr ( b%a, a );
}
bool IsPowerOfTwo(ll x)
{
    return (x & (x - 1)) == 0;
}
int main() {
	freopen ("output.txt","w",stdout);
	freopen ("input.in","r",stdin);
	ll t, i, j,a, b, ans;
	double x;
	char str[10000];
	cin>>t;
	for(ll lol = 1; lol <= t; ++lol) {
		
		cin>>str;
		ans = 1;
		a=b=0;
		for(i=0; str[i] != '/'; ++i) {
			a=a*10;
			a+=((int)(str[i]-'0'));
		}
		for(++i; str[i] != '\0'; ++i) {
			b=b*10;
			b+=((int)(str[i]-'0'));
		}
		
		x = a/(double)b;
		
		while(!((x <= 1.00) && (x >= 0.5000))) {
			x = x*2.0;
			++ans;
		}
		b = b/gcdr(a,b);
		if(!IsPowerOfTwo(b)) ans = -1;
		if(ans!=-1)
		cout<<"Case #"<<lol<<": "<<ans<<endl;
		else
		cout<<"Case #"<<lol<<": impossible"<<endl;
	}
	return 0;
}