#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

const double eps = 1e-8;
int T;
int n,a[205],sum;
double ans[205];
bool check(double mid,int id){
	double x = (double)a[id] + mid * sum / 100.0;
	double y = (100.0 - mid) * sum / 100.0;
//	printf("%f %f\n",x,y);
	int cnt = 0;
	for(int i = 0;i < n; ++i){
		if(i == id) continue;
		if((double)a[i] < x){
			cnt++;
			y += a[i];
		}
	}
//	printf("%f %f\n",x,y);
	if(cnt == 0) return false;
	if(x < (y / (double)cnt)) return false;
	else return true;
}
void solve(){
	sum = 0;
	scanf("%d",&n);
	for(int i = 0;i < n; ++i) scanf("%d",&a[i]);
	for(int i = 0;i < n; ++i) sum += a[i];
//	printf("%d\n",check(50.0,0));
	for(int i = 0;i < n; ++i){
		double low = 0.0,high = 100.0,mid;
//		printf("%f\n",high - low);
		while(high - low > eps){
//			printf("here\n");
			mid = (low + high) / 2.0;
			if(check(mid,i)) high = mid;
			else low = mid;
		}
		ans[i] = mid;
	}
	for(int i = 0;i < n; ++i) printf("%.6f%c",ans[i],i == n - 1 ? '\n' : ' ');
}
int main(int argc, char** argv) {
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&T);
	for(int v = 1;v <= T; ++v){
		printf("Case #%d: ",v);
		solve();
	}
	return 0;
}

