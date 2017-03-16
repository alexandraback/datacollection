#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int J,P,S,K;
int res[1010][3];

int main(){
	int T; scanf("%d",&T);
	for(int Case=1; Case<=T; ++Case){
		scanf("%d%d%d%d",&J,&P,&S,&K);
		int ans=0;
		for(int k=1; k<=S && k<=P; k+=K){
			for(int m=1; m<1+K; ++m){
				if(m>J) break;
				for(int i=k; i<k+K; ++i){
					if(i>S) break;
					for(int j=k; j<k+K; ++j){
						if(j>P) break;
						res[ans][0]=m;
						res[ans][1]=j;
						res[ans][2]=i;
						++ans;
					}
				}
			}
		}
		for(int k=1+K; k<=S && k<=J; k+=K){
			for(int m=1; m<1+K; ++m){
				if(m>P) break;
				for(int i=k; i<k+K; ++i){
					if(i>S) break;
					for(int j=k; j<k+K; ++j){
						if(j>J) break;
						res[ans][0]=j;
						res[ans][1]=m;
						res[ans][2]=i;
						++ans;
					}
				}
			}
		}
		for(int k=1+K; k<=P && k<=J; k+=K){
			for(int m=1; m<1+K; ++m){
				if(m>S) break;
				for(int i=k; i<k+K; ++i){
					if(i>P) break;
					for(int j=k; j<k+K; ++j){
						if(j>J) break;
						res[ans][0]=j;
						res[ans][1]=i;
						res[ans][2]=m;
						++ans;
					}
				}
			}
		}
		printf("Case #%d: %d\n",Case,ans);
		for(int i=0; i<ans; ++i)
			printf("%d %d %d\n",res[i][0],res[i][1],res[i][2]);
	}
	return 0;
}
