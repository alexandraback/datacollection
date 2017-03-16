#include <cstdio>
#include <algorithm>
#define N 105
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int t, n, a, x[N], c, A;

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &t);
	FI(z, 1, t){
		scanf("%d %d", &a, &n);
		fi(i, 0, n) scanf("%d", &x[i]);
		sort(x, x + n);
		
		if(a == 1){
			A = n;
		}else{
		A = N;
		c = 0;
		fi(i, 0, n){
			A = min(A, c + n - i);
			while(a <= x[i]){
				a += a - 1;
				c++;
			}
			a += x[i];
		}
		A = min(A, c);
		}
		printf("Case #%d: %d\n", z, A);
	}
	scanf("\n");
}
