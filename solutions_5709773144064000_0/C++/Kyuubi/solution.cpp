#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

#define MOD 1000000007
#define SWAP(a,b) {a=(a)^(b);b = (a)^(b);a= (a)^(b);}

using namespace std;
inline long long minOf(long long x, long long y){return (x<y?x:y);}
inline long long maxOf(long long x, long long y){return (x>y?x:y);}
inline long long mabs(long long x){return (x<0?-x:x);}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	long double c,f,x,n,r=2.0,ans;
	long long farm;
	for(int tt = 1; tt <= t; tt++){
		cin >> c >> f >> x;
		r = 2.0;
		n = ((((x*f)/c) - r)/f);
		farm = n;
		ans = 0.0;
		for(int i = 1;i<=farm;i++){
			ans += c/r;
			r += f;
		}
		ans += x/r;
		printf("Case #%d: %.8Lf\n",tt,ans);
		
	}
	return 0;
}