#include "stdio.h"
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

ll E, R, N;
ll* vi;

ll doit(ll* s, ll* e, ll e1, ll e2) {
	if(e-s==1) {
		if(e1>=e2-R)
			return (*s)*(e1-e2+R);
		else return -1;
	}
	if(e-s<=0) {
		if(e1!=e2) return -1;
		return 0;
	}

	ll* i = max_element(s, e);
	ll ei1=E, ei2=R;
	ll do1, do2;
	if(i==s) {
		do1 = 0;
		ei1 = e1;
	}else {
		while((do1=doit(s,i,e1,ei1))==-1 && ei1>0) 
			--ei1;
		if(do1==-1) return -1;
	}

	if(i+1==e) {
		do2=0;
		ei2=e2;
	} else {
		while((do2=doit(i+1,e,ei2,e2))==-1 && ei2<ei1+R && ei2<E)
			++ei2;
		if(do2==-1) return -1;
	}
	return do1+do2+ (*i)*(ei1-(ei2-R));
}

int main() {
	FILE *fp, *fp2;
	int num;
	ll ans;
	fopen_s(&fp, "B-small-attempt0.in", "r");
	fopen_s(&fp2, "B-small-attempt0.out", "w");
	fscanf_s(fp, "%d", &num);

	for(int i=0; i<num; ++i) {
		fprintf(fp2,"Case #%d: ",i+1);
		fscanf_s(fp, "%lld %lld %lld", &E, &R, &N);
		vi = (ll*)malloc(N*sizeof(ll));
		for(int j=0; j<N;++j){
			fscanf_s(fp, "%lld", vi+j);
		}
		ans = doit(vi, vi+N, E, R);
		fprintf(fp2, "%lld\n", ans);
		free(vi);
	}

	fclose(fp);
	fclose(fp2);
	return 0;
}
