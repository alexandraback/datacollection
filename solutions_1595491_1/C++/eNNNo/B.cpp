#include <iostream>
using namespace std;
int T,N,S,P;
int Score,Ans;
int main() {
	freopen ("in.txt","r",stdin);
	freopen ("out.txt","w",stdout);
	scanf("%d",&T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d%d",&N,&S,&P);
		Ans = 0;
//		printf("%d %d %d__ ",N,S,P);
		for (int i = 1; i <= N; i++) {
			scanf("%d",&Score);
//			printf("%d ",Score);
			if (P == 0 || Score >= 3*P - 2 && P > 0)
				Ans++;
			else if (Score >= 3*P - 4 && P > 1 && S)
				S--, Ans++;
		}
		printf("Case #%d: %d\n",t,Ans);
/*		printf(" : %d ",Ans);
		if (S)
			printf("______S: %d",S);
		printf("\n");*/
	}
}