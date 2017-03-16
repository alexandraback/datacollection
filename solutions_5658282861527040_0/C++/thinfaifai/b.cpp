#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long

int a,b,k;

int main() {
    int tc;
    scanf("%d",&tc);
    for (int t=1; t<=tc; t++) {
        scanf("%d%d%d",&a,&b,&k);
        int ans = 0;
        for (int i=0; i<a; i++)
            for (int j=0; j<b; j++)
                if ((i&j) < k) ans++;
        printf("Case #%d: %d\n",t,ans);
    }
	return 0;
}
