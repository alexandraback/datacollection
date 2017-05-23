#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

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
	long long a,b,k;
	cin >> t;
	int ans;
	for(int tt = 1; tt <= t; tt++){
		ans = 0;
		cin >> a >> b >> k;
		for(int i = 0;i< a;i++)
			for(int j = 0;j<b;j++)
				if((i&j) < k)
					ans++;
		cout << "Case #" << tt << ": " << ans << endl;
	}
	return 0;
}