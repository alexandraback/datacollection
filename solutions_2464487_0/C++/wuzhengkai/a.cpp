#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define uLL unsigned long long
#define LD long double

using namespace std;

int tt;
uLL r,t;

int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	scanf("%d",&tt);
	for (int ii=1;ii<=tt;++ii) {
		cin >> r >> t;
		LD a=2,b=(2*(LD)r-1),c=-(LD)t;
		LD delta=b*b-4*a*c;
		delta=sqrt(delta);
		LD x1=(-b+delta)/(2*a);
		uLL ans=(uLL)x1;
		if (t<ans*ans*2+(2*r-1)*ans) ans--;
		printf("Case #%d: ",ii);
		cout << ans << endl;
	}
}
