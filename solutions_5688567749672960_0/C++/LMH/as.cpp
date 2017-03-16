#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#define FI(i,a, b) for(int i=a;i<=b;i++)
#define FD(i,a, b) for(int i=a;i>=b;i--)

#define CL(x, y) memset(x, y, sizeof(x))
#define INF 2000000000
#define MAXN ?
#define MAXE ?
#define ll long long
using namespace std;
int n, m, dp[10000000], t;
int digit(int x){
	int y = 0;
	while(x){
		x /= 10;
		y++;
	}
	return y;
}
int rev(int x){
	int ret = 0, o = x;;
	while(x){
		ret = ret * 10 + x % 10;
		x /= 10;
	}
	if(digit(ret) != digit(o)) return 0;
	if(ret < o) return ret;
	else return 0;
}
int main(){
	scanf("%d", &t);
	dp[0] = INF;
	dp[1] = 1;
	FI(i, 2, 2000000){

		dp[i] = min(dp[i - 1], dp[rev(i)]) + 1;
	}
	FI(k, 1, t){
		scanf("%d", &n);
		printf("Case #%d: %d\n", k, dp[n]);
	}
}
