#include<stdio.h>
int T;
int X, Y, N, lev, lev2;
double pasc[2][50005];
int main()
{
	freopen("B-small-attempt4.in", "r", stdin);
	freopen("output4.txt", "w", stdout);
	scanf("%d", &T);
	for(int t=1; t<=T; t++){

		scanf("%d %d %d", &N, &X, &Y);
		lev = (X+Y) >> 1;
		lev2 = X+Y;
		printf("Case #%d: ", t);
		if(lev == 0) {
			printf("1.0\n");
			continue;
		}
		if((lev+1)*(2*lev+1) <= N){
			printf("1.0\n");
			continue;
		}
		if(N<=lev*(2*lev-1)){
			printf("0.0\n");
			continue;
		}

		int last = N-lev*(2*lev-1);
		if(X == 0){
			printf("0.0\n");
			continue;
		}
		
		int bef=0, aft=1;
		pasc[bef][0] = 1.0;
		bool v1, v2;
		for(int i = 1; i <= last; i++)
		{
			for(int j = 0; j <= i; j++)
				pasc[aft][j] = 0;
			for(int j = 0; j < i; j++){
				v1 = v2 = false;
				if((i-j-1) < lev2) v1=true;
				if(j < lev2) v2=true;

				if(v1 && v2){
					pasc[aft][j] += pasc[bef][j]*0.5;
					pasc[aft][j+1] += pasc[bef][j]*0.5;
				}
				else if(v1){
					pasc[aft][j] += pasc[bef][j];
				}
				else if(v2){
					pasc[aft][j+1] += pasc[bef][j];
				}
			}
			bef^=1; aft^=1;
		}

		double tot = 0.0;
		int left = Y+1, right = last-left;
		for(left=0, right=last; left<=last; left++, right--){
			if(left>=Y+1 && right<=lev2 && left<=lev2)
				tot += pasc[bef][left];
		}
		printf("%.8lf\n", tot);
	}
	return 0;
}