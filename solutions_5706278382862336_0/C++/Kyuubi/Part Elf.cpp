#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <limits.h>
#include <queue>

#define MOD 1000000007
#define SWAP(a,b) {a=(a)^(b);b = (a)^(b);a= (a)^(b);}

using namespace std;
inline long long minOf(long long x, long long y){return (x<y?x:y);}
inline long long maxOf(long long x, long long y){return (x>y?x:y);}
inline long long mabs(long long x){return (x<0?-x:x);}
long long p,q;
bool isValid(long long a, long long b){
	//	cout << "Checking for :" << a << " " << b << endl;
	if(a == 0 && b == 1)
		return false;
	while(b > a){
		if(b%2)
			return true;
		b = b/2LL;
	}
	if(a == b && b == 1)
		return false;
	return isValid(a-b, b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	long long ans = 0;
	long long div;
	cin >> t;
	string ss;
	for(int tt = 1; tt<=t; tt++){
		ans = 0;
		div = 1;
		bool noans = false;
		cin >> ss;
		p = 0;
		q = 0;
		int ii = 0;
		while(ss[ii] != '/'){
			p = (p*10LL) + (long long)(ss[ii]-'0');
			ii++;
		}
		ii++;
		while(ii < ss.length()){
			q = (q*10LL) + (long long)(ss[ii]-'0');
			ii++;
		}
		while(q > p && !noans){
			if(q%2)
				noans = true;
			q = q/2LL;
			ans++;
		}
		
		if(noans)
			cout << "Case #" << tt << ": " << "impossible" << endl;
		else{
			noans = isValid(p-q,q);
			if(!noans)
				cout << "Case #" << tt << ": " << ans << endl;
			else
				cout << "Case #" << tt << ": " << "impossible" << endl;
		}
	}
	return 0;
}