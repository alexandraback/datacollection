#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <cmath>

using namespace std;

const int MAXN = 1e4+5;

int T, r, t, wyn;
double paint, radius;

int main() {
	scanf("%d",&T);
	for(int ct=1;ct<=T;ct++) {
		scanf("%d%d",&r,&t);
		wyn = 0;
		paint = t; radius = r+1.f;
		while(paint >= (radius*radius-(radius-1.f)*(radius-1.f))) {
			wyn++;
			paint -= (radius*radius-(radius-1.f)*(radius-1.f));
			radius += 2.f;
		}
		printf("Case #%d: %d\n", ct, wyn);
	}
	return 0;
}
