#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-9

int sum ,a[205],n;
void calc(int x){
	int cnt = 200,i;
	double hi = 1,lo = 0,mid;
	while(cnt--){
		mid = (hi+lo)/2.0;
		double cur = a[x] + mid*sum;
		double pp = 1 - mid;
		for(i = 0;i<n;i++){
			if(i == x || cur+eps<a[i]) continue;
			double p = (cur - a[i])/(double)sum;
			if(pp - p <-eps) break;
			pp-=p;
		}
		if(i == n){
			lo = mid;
		}
		else hi = mid;

	}
	
	printf(" %.6lf",mid*100+eps);
}
int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.ans","w",stdout);
	int t,i,cs = 1;
	cin>>t;
	while(t--){
		cin>>n;
		sum = 0;
		for(i = 0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		printf("Case #%d:",cs++);
		for(i = 0;i<n;i++){
			calc(i);
		}
		printf("\n");
	}
	return 0;
}