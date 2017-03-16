#include<stdio.h>

int a[10];

int main() {

	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	int n2,n3,n5,n2_,n3_,n5_,card;
	int T,R,N,M,K,i,j;

	scanf("%d", &T);
	scanf("%d %d %d %d", &R, &N, &M, &K);

	printf("Case #1:\n");

	for(i=1 ; i<=100 ; i++) {
		n2=0, n3=0, n5=0;
		for(j=1 ; j<=7 ; j++) 
			scanf("%d", &a[j]);

		for(j=1 ; j<=7 ; j++) {
			n2_=0, n3_=0, n5_=0;
			while(a[j]>1) {
				if(a[j]%2==0) n2_++,a[j]/=2;
				else if(a[j]%3==0) n3_++,a[j]/=3;
				else if(a[j]%5==0) n5_++,a[j]/=5;
			}

			if(n2<n2_) n2=n2_;
			if(n3<n3_) n3=n3_;
			if(n5<n5_) n5=n5_;
		}

		if(n2==0) {
			if(n3+n5==0) card=222;
			else if(n3+n5==1) {
				if(n3==1) card=333;
				else card=555;
			}
			else if(n3+n5==2) {
				if(n3==2) card=333;
				else if(n3==1) card=335;
				else card=555;
			}
			else {
				if(n3==3) card=333;
				else if(n3==2) card=335;
				else if(n3==1) card=355;
				else card=555;
			}
		}
		else if(n2==1) {
			if(n3+n5==0) card=222;
			else if(n3+n5==1) {
				if(n3==1) card=223;
				else card=225;
			}
			else if(n3+n5==2) {
				if(n3==2) card=233;
				else if(n3==1) card=235;
				else card=255;
			}
		}
		else if(n2==2) {
			if(n3+n5==0) card=222;
			else if(n3+n5==1) {
				if(n3==1) card=223;
				else card=225;
			}
			else if(n3+n5==2) {
				if(n3==2) card=334;
				else if(n3==1) card=345;
				else card=455;
			}
		}
		else if(n2==3) {
			if(n3+n5==0) card=222;
			else {
				if(n3==1) card=234;
				else card=245;
			}
		}
		else if(n2==4) {
			if(n3+n5==0) card=244;
			else if(n3==1) card=344;
			else card=445;
		}
		else if(n2==5) {
			card=244;
		}
		else if(n2==6) {
			card=444;
		}

		printf("%d\n", card);
	}	

	return 0;
}