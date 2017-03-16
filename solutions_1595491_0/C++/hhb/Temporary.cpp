#include<stdio.h>

int solve() {
	int N, S, p, res=0;
	scanf("%d%d%d", &N, &S, &p);
	for(int i=0;i<N;i++) {
		int v;
		scanf("%d", &v);
		if((v+2)/3>=p) res++;
		else {
			bool succ=false;
			switch(v%3) {
			case 0:
				if(v/3+1>=p&&v>0) succ=true;
				break;
			case 1:
				break;
			case 2:
				if(v/3+2>=p) succ=true;
			}
			if(succ&&S>0) {
				S--;
				res++;
			}
		}
	}
	return res;
}

int main() {
	int T;
	scanf("%d", &T);
	for(int c=1;c<=T;c++) {
		printf("Case #%d: %d\n", c, solve());
	}
}