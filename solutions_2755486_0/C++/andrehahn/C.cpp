#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <cassert>
#define MAX 550

using namespace std;

struct attack{
	int d, w, e, s;
	attack(){}
	attack(int dd, int ww, int ee, int ss){
		d = dd; w = ww; e = ee; s = ss;
	}
};

bool operator < (const attack &a, const attack &b){
	if(a.d != b.d)
		return a.d < b.d;
	if(a.w != b.w)
		return a.w < b.w;
	if(a.e != b.e)
		return a.e < b.e;
	return a.s < b.s;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		int N;
		scanf("%d", &N);
		attack a[MAX];
		int k = 0;
		int v[MAX*MAX];
		for(int i = 0; i < MAX*MAX; i++)
			v[i] = 0;

		for(int i = 0; i < N; i++){
			int d, n, w, e, s, dd, dp, ds;
			scanf("%d%d%d%d%d%d%d%d", &d, &n, &w, &e, &s, &dd, &dp, &ds);
			for(int j = 0; j < n; j++)
				a[k++] = attack(d+j*dd, 1000+w+j*dp, 1000+e+j*dp, s+j*ds);
		}
		sort(a, a+k);
		for(int i = 0; i < k; i++)
			assert(a[i].w >= 0);

		int r = 0;
		for(int i = 0; i < k; i++){
			int j;
			//printf("Day: %d\n", a[i].d);
			for(j = i; j < k && a[j].d == a[i].d; j++){
				bool suc = false;
				for(int l = a[j].w; l < a[j].e; l++)
					if(a[j].s > v[l])
						suc = true;
				if(suc) r++;
				//printf("%d %d %d %d\n", a[j].w, a[j].e, a[j].s, r);
			}
			for(j = i; j < k && a[j].d == a[i].d; j++)
				for(int l = a[j].w; l < a[j].e; l++)
					if(a[j].s > v[l])
						v[l] = a[j].s;
			i = j-1;
		}
		printf("Case #%d: %d\n", t, r);
	}
	return 0;
}
