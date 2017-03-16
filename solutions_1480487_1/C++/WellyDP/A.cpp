#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <string>
#define INF 2000000000
#define ii pair<int, int>

using namespace std;

int main() {
	int ntc,n,x;
	int arr[205];
	double res[205];
	int flag[205];
	scanf("%d",&ntc);
	for (int tc=1;tc<=ntc;tc++) {
		scanf("%d",&n);
		memset(flag,0,sizeof(flag));
		x=0;
		for (int i=0;i<n;i++) {
			scanf("%d",&arr[i]);
			x=x+arr[i];	
		}
		double exval = x*2/n;
		for (int i=0;i<n;i++) {
			res[i] = (exval - arr[i]) / x * 100.0;	
		}	
		int byk=n;
		double jum=0;
		for (int i=0;i<n;i++) {
			if (res[i]<0.0) {
				jum += arr[i];
				res[i]=0.0;
				flag[i]=1; byk--;
			}
		}
		
		double exval2 = (2 * x- jum)/ byk;
		//printf("%lf\n",exval2);
		//share = share/(n-jum);
		for (int i=0;i<n;i++) {
			if (flag[i]==0) {res[i]=(exval2-arr[i])/x*100.0;}
		}
		printf("Case #%d:",tc);
		for (int i=0;i<n;i++) {
			printf(" %lf",res[i]);
		}	
		puts("");
	}
    return 0;
}
