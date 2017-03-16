#include <stdio.h>
#include <string.h>

using namespace std;

int t;
int K,L,S,mx;
char keys[200],target[200],w[200];

double go(int rem,double p){
	if (!rem){
		int poc=0;
		for(int i=0;i+L<=S;++i){
			if (!strncmp(target,w+i,L)){
				++poc;
			}
		}
		if (poc>mx) mx=poc;
		return p*(mx-poc);
	}
	double res=0;
	for(int i=0;i<K;++i){
		w[S-rem]=keys[i];
		res+=go(rem-1,p/K);
	}
	return res;
}

int main(){
	scanf("%d",&t);
	for(int tt=1;tt<=t;++tt){
		printf("Case #%d: ",tt);
		scanf("%d%d%d\n%s\n%s",&K,&L,&S,keys,target);
		mx=0;
		go(S,1.);
		double res=go(S,1.);
		printf("%.9lf\n",res);
	}
	return 0;
}
