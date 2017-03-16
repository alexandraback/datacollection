#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
	int i,j,k,m,n,r,c;
	double t[20],x[20],a[20],ans[20];
	double D,N,A,v,s1,tt;
	
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	cin>>r;
	for(c=1; c<=r; ++c){
		cin>>D>>N>>A;
		for(i=0; i<N; ++i) cin>>t[i]>>x[i];
		for(i=0; i<A; ++i) cin>>a[i];
		for(k=0; k<A; ++k) {
			if(x[0] >= D) {
				ans[k] = sqrt(2*D/a[k]);
			} else{
				tt = t[0] + (t[1]-t[0]) * (D-x[0]) / (x[1]-x[0]);
				ans[k] = sqrt(2*D/a[k]);
				if(ans[k] < tt)	ans[k] = tt;
			}
		}
		printf("Case #%d:\n",c);
		for(k=0; k<A; ++k)	printf("%.7lf\n",ans[k]);
	}
	return 0;
}
