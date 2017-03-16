#include <bits/stdc++.h>

typedef long long int li;

#define min(a,b) a<=b?a:b
#define max(a,b) a>=b?a:b
#define Fi(i, st, ft) for(i = st;i <= ft; ++i)
#define Fd(i, st, ft) for(i = st;i >= ft; --i)
#define pb(a, b) a.push_back(b)
#define mod 1000000007
#define MAXN 1500000
#define MX 1450000
#define inf 1000000000000000000ll
const int maxBufSize = (10000000);

using namespace std;

li t , smax;
string str;

int main()
{
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	li i , j , k , a , b , c , ans;
	cin >> t;
	Fi(k , 1 , t) {
		cin >> smax >> str;
		ans = b = 0;
		Fi(i , 0 , smax) {
			if(b >= i) {
				b += (str[i]-'0');
			} else {
				a = i-b;
				ans += a;
				b += a;
				b += (str[i]-'0');
			}
		}
		cout << "Case #" << k << ": " << ans << "\n";
	}
	return 0;
}
