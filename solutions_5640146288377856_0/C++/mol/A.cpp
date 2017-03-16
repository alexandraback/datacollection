#include <stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	for(int t=0; t<T; t++){
		int r,c,w;
		scanf("%d%d%d",&r,&c,&w);
		int a[11][11];
		// r=1
		for(int j=1; j<=10; j++)
			a[j][1] = j;
		a[4][2] = 3;
		a[5][2] = 4;
		a[6][2] = 4;
		a[6][3] = 4;
		a[7][2] = 5;
		a[7][3] = 5;
		a[8][2] = 5;
		a[8][3] = 5;
		a[8][4] = 5;
		a[9][2] = 6;
		a[9][3] = 5;
		a[9][4] = 6;
		a[10][2] = 6;
		a[10][3] = 6;
		a[10][4] = 6;
		a[10][5] = 6;
		int ans;
		if(c == w)
			ans = w;
		else if(c < 2*w)
			ans = (2*w-c)+a[c-(2*w-c)][w-(2*w-c)];
		else
			ans = a[c][w];
		printf("Case #%d: %d\n",t+1,ans);
	}
	return 0;
}
