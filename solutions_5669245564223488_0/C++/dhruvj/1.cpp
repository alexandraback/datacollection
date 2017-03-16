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
	int myints[12];
	ll t, i, j,a, b, n,ans;
	
	char test[10000];
	cin>>t;
	for(ll lol = 1; lol <= t; ++lol) {
		char str[101][1100];
		cin>>n;
		int sum = 0;
		for(i=1;i<=n;++i) {
			cin>>str[i];
			myints[i-1] = i;
			sum+=strlen(str[i]);
		}
		int yo = 0;
		ans = 0;
		do {
		
			ll check = 1;
			char test[10000];
			test[0] = '\0';
	    	for(i=0;i<=n-1;++i) {
	    		strcat(test,str[myints[i]]);
	    	}
	    	int done[1000];
	    	CLR(done);
	    	for(i=0;i<sum;++i) {
	    		if(done[test[i]]) check = 0;
	    		if(test[i] != test[i+1]) done[test[i]] = 1;
	    		if(check == 0) break;
	    	}
	    	if(check) ++ans;
 	  	} while ( std::next_permutation(myints,myints+n) );
		cout<<"Case #"<<lol<<": "<<ans<<endl;
		
	}
	return 0;
}