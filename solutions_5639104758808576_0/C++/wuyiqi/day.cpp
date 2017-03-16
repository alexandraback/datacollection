#include <cstdio>
#include<algorithm>
#include <cstring>
#include <vector>
using namespace std;
char str[1010];
int main()
{
        freopen("A-small-attempt0.in", "r", stdin);
        freopen("A-small-attempt0.out", "w", stdout);
	int t, n, ca = 1;
	scanf("%d", &t);
        while(t--) {
                scanf("%d%s", &n,str);
                int now = 0;
                int ret = 0;
                for(int i = 0; i <= n; i++) {
                        if(str[i]-'0' > 0) {
                                if(now < i) {
                                        ret += i -  now;
                                        now = i;
                                }
                                now += str[i] - '0';
                        }
                }
                printf("Case #%d: %d\n",ca++, ret);
        }
	return 0;
}
