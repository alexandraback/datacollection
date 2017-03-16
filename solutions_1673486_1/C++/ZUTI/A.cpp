#include <cstdio>

using namespace std;

int main() {

	int t,a,b,tmp;

	scanf("%d",&t);

	for (int tc = 0; tc < t; ++tc) {
		scanf("%d %d",&a,&b);
		double result, current, p;
		current = 1;
		result = 2+b;
		for (int i = 0; i < a; ++i) {
			scanf("%lf",&p);
			current = current * p;
			tmp = 2*(a-i-1) + b-a+1;
			if (result > current*tmp + (1-current)*(tmp +b+1))
				result = current*tmp + (1-current)*(tmp +b+1);
		}

		printf("Case #%d: %.6lf\n",tc+1,result);
	}

	return 0;
}

