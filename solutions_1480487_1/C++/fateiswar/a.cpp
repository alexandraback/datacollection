#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;

int s[300];
int tot;
double eps=1e-8;
double result[300];
int judge(int i, double yi, int N){
	double lim=s[i]+tot*yi;
	double c=0;
	for(int j=1; j<=N; j++) if(j!=i){
		if(lim>s[j]){
			c+=(lim-s[j])*1.0/tot;
		}
	}
	if(c+yi>=1.0) return 1;
	return 0;
}
int main(){
	freopen("A-large.in", "r", stdin);
	freopen("aoutlarge.txt", "w", stdout);
	int T; cin>>T;
	for(int cas=1; cas<=T;cas++){
		int N; cin>>N;
		int i, j;
		for(i=1; i<=N; i++) cin>>s[i];
		tot=0; for(i=1; i<=N; i++) tot+=s[i];
		for(i=1; i<=N; i++){
			double low=0, high=1;
			while(high-low>eps){
				double mid=(low+high)/2;
				if(judge(i, mid, N))
					high=mid;
				else low=mid;
			}
			result[i]=low*100;
		}
		printf("Case #%d:", cas);
		for(i=1; i<=N; i++) printf(" %.8lf", result[i]);
		printf("\n");
	}
	return 0;
}