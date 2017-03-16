#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)

using namespace std;

typedef long double K;

K c, f, x, t, p, v;

int main(){
	int zz; scanf("%d", &zz);
	FWD(z,1,zz+1){
		scanf("%Lf %Lf %Lf\n", &c, &f, &x);
		p = 0;
		v = 2;
		t = 1000000;
		do{
			t = min(t, p + x / v);
			p += c / v;
			v += f;
		}while(p < t);
		printf("Case #%d: %.7Lf\n", z, t);
	}
	return 0;
}
