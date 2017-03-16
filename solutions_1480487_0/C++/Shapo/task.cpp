#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>

#define maxn 100500

using namespace std;

int t, sum_s, n;
int pp[maxn];
double res[maxn];

bool sum(const double &x){
	double need = double(100), cur = 0;
	double s = double(sum_s);
	for(int i = 1; i <= n; ++i){
		res[i] = max((x - pp[i]) * 100 / s, double(0));
		cur = cur + res[i];
	}
	return(cur < need + 1e-9);
}

int obr(const int &xx){
	int mx = 0;
	sum_s = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &pp[i]);
		mx = max(mx, pp[i]);
		sum_s += pp[i];
	}
	double dl = 0, dr = double(mx + sum_s), dm;
	for(int i = 1; i <= 1000; ++i){
		dm = (dl + dr) / 2;
		if(sum(dm))dl = dm;else dr = dm;
	}
	sum(dl);
	printf("Case #%d:", xx);
	//printf("dl = %.10lf, sum = %d\n", dl, sum_s);
	double ss = 0;
	for(int i = 1; i <= n; ++i){
		printf(" %.8lf", res[i]);
		ss = ss + res[i];
	}
	printf("\n");
	return 0;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &t);
	for(int i = 1; i <= t; ++i)obr(i);

	return 0;
}
