#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#define FI(i,a, b) for(i=a;i<=b;i++)
#define FD(i,a, b) for(i=a;i>=b;i--)
#define ll long long
#define CL(x, y) memset(x, y, sizeof(x))
#define INF 100000000
#define MAXN ?
#define MAXE ?
using namespace std;
ll i,j, k, N, M, K;
ll P, Q, T, two[100];
ll gcd(ll a, ll b){
	if(a < b) swap(a, b);
	while(b != 0){
		a %= b;
		swap(a, b);
	}
	return a;
}
int main(){
	two[0] = 1;
	FI(i, 1, 50) two[i] = two[i - 1] * 2;
	scanf("%lld", &T);
	FI(k, 1, T){
		
		scanf("%lld%*c%lld", &P, &Q);
		ll g = gcd(P, Q);
		ll ans = 45, fg= 0;;
		P /= g; Q /= g;
		ll left = 40;
			P *= 2;
		FI(i, 1, 40){
			FI(j, 1, left){
				if(two[j] % Q == 0){
					//printf("two[j] = %lld Q = %lld i = %lld\n", two[j], Q, i);
					fg = 1;
					break;
				}
			}
			if(fg && P >= Q){ ans = min(ans, i); break;}
			P *= 2;
			left --;
		}
		if(ans == 45) printf("Case #%lld: impossible\n", k);
		else
		printf("Case #%lld: %lld\n", k, ans);
	}

}
