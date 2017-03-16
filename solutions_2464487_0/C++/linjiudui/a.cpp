#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef int ll;
int main()
{
    int T, cas = 1;
    ll r, t;
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
	    scanf("%d %d", &r, &t);
        int ans = 0;
        int ptr = r;
        while(t > 0){
		    if(t >= (2*ptr+1)){
		        t -= (2*ptr+1);	
                ans ++;
                ptr += 2;
			}else{
			    break;
			}
		}
		printf("Case #%d: %d\n", cas++, ans);
	}
    return 0;
}