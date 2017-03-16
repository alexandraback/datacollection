#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <bitset>
#include <climits>
#include <stack>
#include <cctype>
#include <sstream>
#define MAX 1000000000ULL
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

ll r, t;

bool comp(ll x) {
    ll p = (2*r + 2*x + 1);
    if(p > t) return true;
    if(x > 10 && p*10 > t) return true;
    if(x > 100 && p*100 > t) return true;
    if(x > 1000 && p*1000 > t) return true;
    if(x > 10000 && p*10000 > t) return true;
    if(x > 100000 && p*100000 > t) return true;
    if(x > 1000000 && p*1000000 > t) return true;
    ll q = (x+1)*p;
    return q > t;
}

ll binary_search(ll lo, ll hi)  {
    ll mid;
   while (lo < hi)  {
      mid = lo + (hi-lo)/2;
      if (comp(mid))
         hi = mid;
      else
         lo = mid+1;
   }
   if (!comp(lo))
      return -1;

   return lo;
}

int main()	{
    int T, i;
    ll ans;

	freopen("A-large.in", "r", stdin);
	freopen("A-large.txt", "w", stdout);

	scanf("%d", &T);
	for(i=1; i<=T; i++)  {
        scanf("%lld %lld", &r, &t);
        ans = binary_search(0, MAX);
        printf("Case #%d: %lld\n", i, ans);
	}

	return 0;
}
