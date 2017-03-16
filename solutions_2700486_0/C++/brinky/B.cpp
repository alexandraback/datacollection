#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int d[200];
int n, x, y;

double rek(int p, int i) {
	if(i == n){
		return d[100 + x] >= y;
	}
	if(d[p-1] > d[p] && d[p+1] < d[p])
		return rek(p+1, i);
	else if(d[p-1] < d[p] && d[p+1] > d[p])
		return rek(p-1, i);
	else if(d[p-1] > d[p] && d[p+1] > d[p]){
		d[p] += 2;
		double r = rek(100, i+1);
		d[p] -= 2;
		return r;
	}else{
		double r = 0;
		r += .5 * rek(p+1, i);
		r += .5 * rek(p-1, i);
		return r;
	}
}

int main(){
	int tc, tcn;
	scanf("%d", &tcn);
	for(tc=0; tc<tcn; ++tc){
		for(int i=0; i<200; ++i){
			d[i] = (i%2) ? -1 : -2;
		}
		scanf("%d %d %d", &n, &x, &y);
		if(x < -50 || x > 50)
			printf("Case #%d: %.10lf\n", tc+1, 0);
		else
			printf("Case #%d: %.10lf\n", tc+1, rek(100, 0));
	}
}
