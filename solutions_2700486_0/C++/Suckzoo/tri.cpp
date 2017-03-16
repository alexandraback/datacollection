#include <cstdio>
int T,Ti;
int n,x,y;
int abs(int t) {
	return t<0?-t:t;
}
int sequence(int s) {
	return (2*s*s)+(3*s)+1;
}
double exp2(int q) {
	int i;
	double s=1;
	for(i=0;i<q;i++) {
		s/=2;
	}
	return s;
}
double func(int n,int r) {
	double fx=1;
	int i;
	for(i=1;i<=n;i++) fx/=2;
	for(i=1;i<=n-r;i++) {
		fx*=(double)(r+i);
		fx/=(double)i;
	}
	return fx;
}
int main() { //2n^2+3n+1
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	scanf("%d",&T);
	for(Ti=1;Ti<=T;Ti++) {
		scanf("%d%d%d",&n,&x,&y);
		if(x==0 && y==0) {
			printf("Case #%d: 1.0\n",Ti);
			continue;
		}
		if(x==0) {
			if(sequence(y/2)<=n) printf("Case #%d: 1.0\n",Ti);
			else printf("Case #%d: 0.0\n",Ti);
			continue;
		}
		int s,ii;
		if(x<0) {
			s=sequence(-1+abs(x-y)/2);
			//ii=1+abs(x-y)/2;
		} else {
			s=sequence(-1+abs(x+y)/2);
			//ii=1+abs(x+y)/2;
		}
		n-=s;
		/*int rem=n-ii;
		if(n-ii>0){
			n-=(rem*2);
			y-=rem;
		}
		if(y<0) {
			printf("Case #%d: 1.0\n",Ti);
			continue;
		}*/
		double ans=0;
		int i;
		for(i=n;i>y;i--) {
			ans+=func(n,i);
		}
		printf("Case #%d: %.6lf\n",Ti,ans);
	}
	return 0;
}