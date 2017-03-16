#include <cstdio>
#include <algorithm>
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int t;
double c, f, x;

void solve(){
	scanf("%lf %lf %lf", &c, &f, &x);
	if(x - 1e-5 < c){
		printf("%f\n", x / 2);
		return;
	}
	
	double use = 0, pow = 2, ans = use + x / pow;
	while((pow + f) * (x - c) > pow * x){

		use += c / pow;
		pow += f;
		ans = use + x / pow;
	}
	
	printf("%.7lf\n", ans);
}

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	
	scanf("%d", &t);
	FI(z, 1, t){
		printf("Case #%d: ", z);
		solve();
	}
	scanf("\n");
}
