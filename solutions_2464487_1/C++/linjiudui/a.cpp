#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef __int64 ll;
int main()
{
    int T, cas = 1;
    ll r, t;
    ll MAX64 = 1<<63LL;
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
	    scanf("%I64d %I64d", &r, &t);
        ll lb = 1, ub = t/(2*r)+1;
        ll ans = 0;
        while(lb <= ub){
		    ll mid = (lb+ub)/2;
            if(mid <= 1000000000 && 2*mid*mid+2*mid*r-mid <= t){
			    ans = mid;
                lb = mid+1;
			}else{
                ub = mid-1;
			}
		}
		printf("Case #%d: %I64d\n", cas++, ans);
	}
    return 0;
}