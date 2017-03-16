#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const double eps=1e-9;
double tot, num[300], L, R, M, remain, avg;

int main(){
	int t, time=0, n, i, j;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i=0, tot=0; i<n; i++){
			scanf("%lf", num+i);
			tot+=num[i];
		}
		printf("Case #%d:", ++time);
		for(i=0; i<n; i++){
			L=0; R=1.0;
			while(R-L>=eps){
				M=(L+R)/2;
				avg=num[i]+M*tot;
				remain=1.0-M;
				for(j=0; j<n; j++){
					if(i==j) continue;
					if(num[j]>=avg) continue;
					if(remain<(avg-num[j])/tot) break;
					remain-=(avg-num[j])/tot;
				}
				if(j==n) L=M;
				else R=M;
			}
			printf(" %f", (L+R)*50.0);
		}
		puts("");
	}
	return 0;
}
