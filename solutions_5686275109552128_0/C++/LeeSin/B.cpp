#include <cstdio>
#include <algorithm>
#define N 1005
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int t, n, x[N], ans;

int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w+", stdout);
	scanf("%d", &t);
	FI(z, 1, t){
		scanf("%d", &n);
		fi(i, 0, n) scanf("%d", &x[i]);
		
		ans = N;
		fi(i, 1, N){
			int tmp = i;
			fi(j, 0, n) tmp += (x[j] - 1) / i;
			ans = min(ans, tmp);
		}
		
		printf("Case #%d: %d\n", z, ans);
	}
	scanf("\n");
}
