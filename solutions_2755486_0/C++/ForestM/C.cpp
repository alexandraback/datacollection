#include "stdio.h"
#include <math.h>
#include <algorithm>
using namespace std;

#define ll long long

int N;
int d[10], n[10], w[10],e[10], s[10], dd[10], dp[10], ds[10];
int tw[10],te[10], ts[10];
int Sw[202], Se[202];

int maxDay() {
	int ret=0;
	for(int j=0; j<N; ++j)
		if((n[j]-1)*dd[j]+d[j]>ret) ret = (n[j]-1)*dd[j]+d[j];
	return ret;
}
bool checkAtt(int j) {
	bool succ=false;
	int i=-e[j]*2;
	if(i<0) i=0;
	for(; i<=-w[j]*2; ++i)
		if(Sw[i]<s[j]) {succ=true;break;}
	if(!succ) {
		i=w[j]*2;
		if(i<0) i=0;
		for(; i<=e[j]*2; ++i)
			if(Se[i]<s[j]) {succ=true;break;}
	}

	if(succ) {
		tw[j]=w[j]; te[j]=e[j]; ts[j]=s[j];
	}
	return succ;
}

void build() {
	int i=0;
	for(int k=0; k<N; ++k) {
		if(ts[k]!=0) {
			if(-te[k]>0) i=-te[k]*2;
			for(; i<=-tw[k]*2; ++i)
				if(Sw[i]<ts[k])	Sw[i]=ts[k];
			i=0;
			if(tw[k]>0) i=tw[k]*2;
			for(; i<=te[k]*2; ++i)
				if(Se[i]<ts[k]) Se[i]=ts[k];
		}
	}
}
int main() {
	FILE *fp, *fp2;
	int num;

	int maxD;
	int ans;
	fopen_s(&fp, "C-small-attempt0.in", "r");
	fopen_s(&fp2, "C-small-attempt0.out", "w");
	fscanf_s(fp, "%d", &num);

	for(int i=0; i<num; ++i) {
		fprintf(fp2,"Case #%d: ",i+1);
		fscanf_s(fp,"%d", &N);
		for(int j=0; j<N;++j)
			fscanf_s(fp,"%d %d %d %d %d %d %d %d", d+j,n+j,w+j,e+j,s+j,dd+j,dp+j,ds+j);
		maxD = maxDay();
		ans=0;
		for(int j=0; j<202; ++j)
			Sw[j]=Se[j]=0;

		for(int j=0; j<=maxD; ++j) {
			for(int k=0; k<10; ++k)
				tw[k]=te[k]=ts[k]=0;
			for(int k=0; k<N; ++k) {
				if(n[k]<=0) continue;
				if(d[k]!=j) continue;
				if(checkAtt(k)) ++ans;
				w[k]+=dp[k]; e[k]+=dp[k];
				d[k]+=dd[k]; s[k]+=ds[k];
				n[k]--;
			}

			build();
		}

		fprintf(fp2, "%d\n", ans);
	}
	fclose(fp);
	fclose(fp2);
	return 0;
}
