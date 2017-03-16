#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

int TTT,x,y,n,a[2000000];

double C(int n, int m){
	if (m>n) return 0;
	double ans=1;
	for (int k=1; k<=m; k++){
		ans = ans*(n-m+k)/k;
	}
	return ans;
}

double work(int n,int x, int y){
		int dk=abs(x)+abs(y);
		dk=dk/2;
		int k=1;
		while (2*k*k+3*k+1<=n) k++;
		k--;
		if (dk<=k) return 1.0;
		if (dk>k+1) return 0;
		int r=n-(2*k*k+3*k+1);
		if (y+1<=r-2*dk) return 1.0;
		
		
		double p=0;
		for (int i=y+1; i<=min(2*dk,r); i++) 
			p+=C(r,i);
		//printf("dk:%d k:%d r:%d %lf\n", dk, k,r,p);
		double mu=0;
		for (int i=max(0,r-2*dk); i<=min(2*dk,r); i++)
			mu+=C(r,i);
		p/=mu;
		return p;
}

int main(){
	freopen("B-small-attempt3.in","r",stdin);
	//freopen("B.in","r",stdin);
	//freopen("B-large.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&TTT);
	for (int TT=1; TT<=TTT; TT++){
		printf("Case #%d: ",TT);
		scanf("%d%d%d\n",&n,&x,&y);
		double ans = work(n,x,y);
		if (ans>1.0+1e-6) while (true) ;
		//printf("%d %d %d %.8lf\n",n,x,y,ans);
		printf("%.6lf\n",ans);
		
	}
	
	fclose(stdout);
	fclose(stdin);
}
