#include<stdio.h>

long long int gcd(long long int a, long long int b) {
	if(b==0) return a;
	else return gcd(b, a%b);
}

int main() {

	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);

	int t, T;
	long long int p,q,g,px,qx;
	bool chk;

	scanf("%d", &T);
	for(t=1 ; t<=T ; t++) {
		scanf("%lld/%lld", &p, &q);
		g=gcd(q,p);
		p=p/g, q=q/g;

		for(chk=true, qx=0 ; q>1 ; q/=2, qx++) {
			if(q%2) { chk=false; break; }
		}
		for(px=0 ; p>1 ; p/=2, px++);

		if(chk)
			printf("Case #%d: %lld\n", t, qx-px);
		else
			printf("Case #%d: impossible\n", t);
	}

	return 0;
}