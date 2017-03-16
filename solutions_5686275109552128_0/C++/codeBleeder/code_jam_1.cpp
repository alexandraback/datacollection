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

li t , d;
li arr[1005];

int main()
{
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	li i , j , k , a , b , c , ans , temp , mx;
	scanf("%lld" , &t);
	Fi(k , 1 , t) {
		scanf("%lld" , &d);
		mx = 0;
		Fi(i , 1 , d) {
			scanf("%lld" , &arr[i]);
			mx = max(arr[i] , mx);
		}
		ans = inf;
		Fi(i , 1 , mx) {
			temp = b = 0;
			Fi(j , 1 , d) {
				c = arr[j]/i;
				if(arr[j]%i > 0) {
					c++;
				}
				c--;
				temp += c;
			}
			temp += i;
			ans = min(ans , temp);
		}
		printf("Case #%lld: %lld\n" , k , ans);
	}
	return 0;
}
