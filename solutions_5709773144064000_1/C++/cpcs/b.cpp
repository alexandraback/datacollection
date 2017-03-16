#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
int z,zz;
	scanf("%d",&zz);
	for (int z = 1; z <= zz; ++z) {
		double c , f, x, r = 2.;
		scanf("%lf%lf%lf",&c,&f,&x);
		double answer = x / 2.,now = 0.;
		while (now + 1e-10 <= answer) {	
			answer = min(answer, now + x / r);
			now += c / r;
			r += f;
		}
		printf("Case #%d: %.7lf\n",z,answer);
	}
	return 0;
}
