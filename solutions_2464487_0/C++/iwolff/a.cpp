#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iostream>
#include <ctime>
#include <cassert>
#include <sstream>

using namespace std;

#define INF 0x3f3f3f3f
#define ll long long

int main() {
    int nt,nteste=1;
    ll r,t,A;
    ll lo,hi,mid,ans;

    cin>>nt;
    while (nt--) {
        cin>>r>>t;
        A = 2LL*r + 1LL;
        lo = 0LL; hi = min(t/A,(ll)sqrt(1.0*t)) + 1LL;
        while (lo<=hi) {
            mid = (lo+hi)/2LL;
            if ((A + 2LL*mid)*(mid + 1LL) <= t) {
                ans = mid;
                lo = mid+1LL;
            }
            else hi = mid-1LL;
        }
        printf("Case #%d: %lld\n",nteste++,ans+1LL);
    }
    
	return 0;
}
