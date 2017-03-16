#include <cstdio>
#include <algorithm>
#define N 1005
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int t, n, sum, ans;
char s[N];

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w+", stdout);
	scanf("%d", &t);
	FI(z, 1, t){
		scanf("%d %s", &n, s);
		sum = ans = 0;
		FI(i, 0, n){
			if(s[i] == '0') continue;
			if(sum < i){
				ans += i - sum;
				sum = i;
			}
			sum += s[i] - '0';
		}
		printf("Case #%d: %d\n", z, ans);
	}
	scanf("\n");
}
