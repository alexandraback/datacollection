#include<stdio.h>

int main() {

  freopen("in.in", "r", stdin);
  	freopen("out.out", "w", stdout);

	int t,T;
	int n,m,k;
	int ans;

	scanf("%d", &T);
	for(t=1 ; t<=T ; t++) {
		scanf("%d %d %d", &n, &m, &k);
		if(m>n) {
			int tmp=n; n=m; m=tmp;
		}

		if(m<=2) ans=k;
		else if(m==3) {
			if(k<=4) ans=k;
			else if(k>=n*m-4) ans=2*(m+n)-8+(k-n*m+4);
			else {
				if(k<=7) ans=k-1;
				else if(k<=10) ans=k-2;
				else if(k<=13) ans=k-3;
				else if(k<=16) ans=k-4;
			}

		}
		else if(m==4) { // N can be 4 or 5
			if(n==4) {
				if(k<=4) ans=k;
				else if(k<=7) ans=k-1;
				else if(k<=10) ans=k-2;
				else if(k==11) ans=k-3;
				else if(k==12) ans=k-4;
				else ans=8+(k+4-n*m);
			}
			else { // N==5
				if(k<=4) ans=k;
				else if(k<=7) ans=k-1;
				else if(k<=10) ans=k-2;
				else if(k==11) ans=k-3;
				else if(k<=13) ans=k-4;
				else if(k<=15) ans=k-5;
				else if(k<=16) ans=k-6;
				else ans=10+(k+4-n*m);
			}
		}
		else 
			ans=-1;

		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}