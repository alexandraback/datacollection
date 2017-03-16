#include <stdio.h>

int cnt[10];

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int T,Case=0;
	int R,N,M,K,i,tn,a,b,c,d,f,A,B,C,D; long long X[20];

	scanf ("%d",&T); while (T--){
		printf ("Case #%d:\n",++Case);
		scanf ("%d %d %d %d",&R,&N,&M,&K);
		while (R--){
			cnt[2]=  cnt[3] = cnt[5] = cnt[7] = 0;
			for (i=0;i<K;i++){
				scanf ("%lld",&X[i]);
			}
			f = 0;
			A = B = C = D = 0;
			for (i=0;i<K;i++){
				a = b = c = d = 0;
				while (X[i] % 2 == 0){cnt[2]++; X[i] /= 2; a++;}
				while (X[i] % 3 == 0){cnt[3]++; X[i] /= 3; b++;}
				while (X[i] % 5 == 0){cnt[5]++; X[i] /= 5; c++;}
				while (X[i] % 7 == 0){cnt[7]++; X[i] /= 7; d++;}
				if (a == 5 || a / 2 + b + c == 3){f = 1; break;}
				if (A < a) A = a;
				if (B < b) B = b;
				if (C < c) C = c;
				if (D < d) D = d;
			}
			if (f){
				if (a == 5){
					printf ("244");
				}
				else{
					a /= 2;
					while (a--) printf ("4");
					while (b--) printf ("3");
					while (c--) printf ("5");
				}
			}
			else if (cnt[5] == 0){
				if (cnt[2] == 0) printf ("333");
				else if (cnt[3] == 0){
					if (cnt[2] * 2 <= K * 3) printf ("222");
					else if (cnt[2] * 2 <= K * 4) printf ("224");
					else printf ("244");
				}
				else if (cnt[2] <= cnt[3] * 2) printf ("223");
				else if (cnt[2] <= cnt[3] * 3) printf ("324");
				else if (cnt[2] <= cnt[3] * 4) printf ("344");
				else printf ("233");
			}
			else{
				if (cnt[2] && cnt[3]){
					if (cnt[2] >= cnt[3] * 2) printf ("435");
					else printf ("235");
				}
				else{
					if (cnt[5] <= 3) cnt[5] = 1;
					else cnt[5] = (cnt[5] * 2) / 7;
					if (cnt[5] < c) cnt[5] = c;
					tn = N;
					if (cnt[5] > N) cnt[5] = N;
					while (cnt[5]--){
						tn--; printf ("5");
					}
					if (tn == 1){
						if (cnt[2]) printf ("2");
						else printf ("3");
					}
					else if (tn == 2){
						if (cnt[2]) printf ("22");
						else printf ("33");
					}
				}
			}

			printf ("\n");
		}
	}

	return 0;
}