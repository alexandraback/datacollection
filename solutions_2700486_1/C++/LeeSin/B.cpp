#include <cstdio>
#include <algorithm>
#define N 5000
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int n, t, x, y, s;
double A, dp[N], nw[N];

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	scanf("%d", &t);
	FI(z, 1, t){
		scanf("%d %d %d", &n, &x, &y);
		
		x = abs(x);
		for(s = 1, n--; n >= s + s + 3; s += 2) n -= s + s + 3;
		
		dp[0] = 1;
		FI(i, 1, s + 1) dp[i] = 0;
		
		fi(i, 0, n){
			FI(j, 0, s + 1) nw[j] = 0;
			FI(j, 0, s){
				if(i - j > s + 1) continue;
				if(i - j == s + 1) nw[j + 1] += dp[j];
				else{
					nw[j + 1] += dp[j] / 2;
					nw[j] += dp[j] / 2;
				}
			}
			nw[s + 1] += dp[s + 1];
			FI(j, 0, s + 1) dp[j] = nw[j];
		}
		
		if(x + y < s) A = 1;
		else if(x + y == s + 1){
			A = 0;
			FD(i, s + 1, y + 1) A += dp[i];
		}else A = 0;
		
		printf("Case #%d: %.7lf\n", z, A);
	}
	scanf("\n");
}
