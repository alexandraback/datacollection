#include <stdio.h>

int cnt[10];
long long CC[20][20];

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int T,Case=0;
	int R,N,M,K,i,j,k,l,tn,a,b,c,d,f,A,B,C,D; long long x,X[20];

	for (i=0;i<20;i++){
		CC[i][0] = CC[i][i] = 1;
		for (j=1;j<i;j++) CC[i][j] = CC[i-1][j] + CC[i-1][j-1];
	}

	scanf ("%d",&T); while (T--){
		printf ("Case #%d:\n",++Case);
		scanf ("%d %d %d %d",&R,&N,&M,&K);
		while (R--){

			for (i=0;i<K;i++){
				scanf ("%lld",&X[i]);
			}
			f = 0;
			A = B = C = D = 0;
			for (i=0;i<K;i++){
				a = b = c = d = 0;
				cnt[2]=  cnt[3] = cnt[5] = cnt[7] = 0;
				while (X[i] % 2 == 0){cnt[2]++; X[i] /= 2; a++;}
				while (X[i] % 3 == 0){cnt[3]++; X[i] /= 3; b++;}
				while (X[i] % 5 == 0){cnt[5]++; X[i] /= 5; c++;}
				while (X[i] % 7 == 0){cnt[7]++; X[i] /= 7; d++;}
				if (A < a) A = a;
				if (B < b) B = b;
				if (C < c) C = c;
				if (D < d) D = d;
			}

			double v = 0; long long print;
			for (a=A;a<=N;a++){
				for (i=0;i<=A/2;i++){
					int two = a - i * 2, four = i;
					if (two + four > N) break;
					for (b=B;b<=N;b++){
						for (j=0;j<=B/2;j++){
							int three = b - j * 2, nine = j;
							if (two + four + three + nine > N) break;
							for (c=C;c<=N;c++){
								if (two + four + three + nine + c > N) break;
								for (d=D;d<=N;d++){
									if (two + four + three + nine + c + d != N) break;
									double u = 1e18;
									for (k=0;k<K;k++){
										cnt[2] =  cnt[3] = cnt[5] = cnt[7] = 0;
										x = X[k];
										while (x % 2 == 0){cnt[2]++; x /= 2;}
										while (x % 3 == 0){cnt[3]++; x /= 3;}
										while (x % 5 == 0){cnt[5]++; x /= 5;}
										while (x % 7 == 0){cnt[7]++; x /= 7;}
										double p = 1, s;
										s = 0;
										for (l=0;l<=cnt[2]/2;l++) s += CC[four][l] * CC[two][cnt[2]-l*2];
										p *= s;
										s = 0;
										for (l=0;l<=cnt[3]/2;l++) s += CC[nine][l] * CC[three][cnt[3]-l*2];
										p *= s;
										s = 0;
										for (l=0;l<=cnt[5];l++) s += CC[c][l];
										p *= s;
										s = 0;
										for (l=0;l<=cnt[7];l++) s += CC[d][l];
										p *= s;

										if (u > p) u = p;
									}

									if (v < u){
										v = u;
										print = 0;
										for (l=0;l<two;l++) print *= 10, print += 2;
										for (l=0;l<three;l++) print *= 10, print += 3;
										for (l=0;l<four;l++) print *= 10, print += 4;
										for (l=0;l<nine;l++) print *= 10, print += 9;
										for (l=0;l<c;l++) print *= 10, print += 5;
										for (l=0;l<d;l++) print *= 10, print += 7;
									}
								}
							}
						}
					}
				}
			}

			printf ("%lld\n",print);
		}
	}

	return 0;
}