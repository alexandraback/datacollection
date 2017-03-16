#include <cstdio>
#include <queue>
#include<algorithm>
#include <cstring>
#include <vector>
using namespace std;
char str[1010];
int a[1010];
int main()
{
freopen("B-small-attempt2.in", "r", stdin);
 freopen("B-small-attempt2.out", "w", stdout);
	int t, n, ca = 1;
	scanf("%d", &t);
        while(t--) {
                int D;
                scanf("%d", &D);
                int mx = 0;
                for(int i=0;i<D;i++){
                        scanf("%d",&a[i]);
                        if(a[i] > mx) mx = a[i];
                }
                int ret = mx;
                for(int i = 1; i <= mx; i++) {
                        int tmp = 0;
                        for(int j = 0; j < D; j++) {
                                if(a[j] > i) {
                                        tmp += (a[j] + i - 1) / i - 1;

                                }
                        }
                        if(tmp +i < ret) ret=  tmp+i;
                }
                printf("Case #%d: %d\n",ca++, ret);
        }
	return 0;
}
