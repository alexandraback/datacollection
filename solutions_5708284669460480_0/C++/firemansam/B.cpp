#include<bits/stdc++.h>
using namespace std;
int tcs, k, l, s, cm[256], nu, mc, bc, ct;
char sample[105], des[105], bf[105], buf[105], bff[105];
double ans;
void gen(int pos){
	if(pos == s) {
		int cc = 0;
		for(int i=0;i<s-(l-1);i++){
			memset(bff, 0, sizeof bff);
			memcpy(bff, bf+i, l);
			bff[l] = 0;
			if(strcmp(bff, des) == 0) {mc++; cc++;}
		}
		bc = max(bc, cc);
		return;
	}
	for(int i=0;i<k;i++){
		bf[pos] = sample[i];
		gen(pos + 1);
	}
}
int main(){
	scanf("%i", &tcs);
	for(int tc=1;tc<=tcs;tc++){
		ans = 0;
		scanf("%i%i%i\n", &k, &l, &s);
		scanf("%s", sample);
		scanf("%s", des);
		sort(sample, sample + k);
		/*memset(cm, 0, sizeof cm);
		for(int i=0;i<k;i++){
			cm[sample[i]]++;
		}
		strcpy(buf, sample);
		sort(buf, buf + k);
		nu = unique(buf, buf + k) - buf;*/
		int nc = pow(k, s);
		//printf("total %i cases\n", nc);
		//f it
		memset(bf, 0, sizeof bf);
		mc = 0;
		bc = 0;
		ct = 0;
		gen(0);
		ans = mc/(double)nc;
		//printf("%i of %i. (best match was %i)\n", mc, nc, bc);
		printf("Case #%i: %f\n", tc, bc - ans);
	}
}