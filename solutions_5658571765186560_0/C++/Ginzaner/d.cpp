#include <cstdio>

using namespace std;

int main() {

	int T;
	scanf("%d", &T);
	
	for(int t = 1; t <= T; t++) {
		printf("Case #%d: ", t);
		
		int R,C,X;
		scanf("%d %d %d", &X, &R, &C);
		if(R < C) {
			int tmp = C;
			C = R;
			R = tmp;
		}
		
		bool win = true;
		
		if((R*C)%X) win = false;
		
		if(X >= 7) win = false;
		
		if(X >= 2*C+1) win = false;
		
		if(X > R) win = false;
		
		if(C == 1 && X > 2) win = false;
		
		if(C == 2 && X > 3) win = false;
		
		if(C == 3 && X > 5) win = false; 
		
		if(win) printf("GABRIEL\n");
		else printf("RICHARD\n");
	}

	return 0;
}
