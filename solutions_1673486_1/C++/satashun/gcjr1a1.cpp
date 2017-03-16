#include <cstdio>
#include <algorithm>
using namespace std;

int T, A, B;
double p[100000], d[100000];

int main(){
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
	scanf("%d %d", &A, &B);
	for(int i = 1; i <= A; i++){
	    scanf("%lf", &p[i]);
	}
	double a, tmp, ans;
	ans = 1000000000;
	a = 1;
	d[0] = 1;
	for(int i = 1; i <= A; i++){
	    a *= p[i];
	    d[i] = a;
	}
	tmp = (B - A + 1) * a + (B * 2 - A + 2) * (1 - a);
	ans = min(ans, tmp);
	if(A == B){
	    tmp = 1 * a + (B + 2) * (1 - a);
	    ans = min(ans, tmp);
	}else{
	    tmp = B + 2;
	    ans = min(ans, tmp);
	}
	for(int i = 1; i <= A; i++){
	    tmp = (B - A + i * 2 + 1) * d[A - i] + (B * 2 - A + i * 2 + 2) * (1 - d[A - i]);
	    ans = min(ans, tmp);
	}
	printf("Case #%d: %lf\n", t, ans);
    }
    return 0;
}
