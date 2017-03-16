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
int n, m, t, r, c, w, x, ans;
int up(int a, int b){
	return a / b + (a % b > 0);
}
int main(){
	scanf("%d", &t);
	FI(k, 1, t){
		scanf("%d%d%d", &r, &c, &w);
		if(c == w){
			ans = c;
		}else{
			ans = (c / w) * r + (c % w > 0) + w - 1;
		}
		printf("Case #%d: %d\n", k, ans);
	}
}
