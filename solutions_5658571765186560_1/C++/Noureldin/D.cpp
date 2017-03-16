#include <bits/stdc++.h>
using namespace std;

int main(){
	int T,X,R,C;
	scanf("%d",&T);
	char out [2][10] = {"RICHARD","GABRIEL"};
	for(int t = 1;t <= T;t++){
		scanf("%d %d %d",&X,&R,&C);
		int c,A = R*C;
		if(X < 7) c = (A%X == 0) && (A >= X*(X - 1));
		else c = 0;
		printf("Case #%d: %s\n",t,out[c]); 
	}
	return 0;
}