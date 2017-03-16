#include <algorithm>
#include <string.h>

using namespace std;

int R,C,M;
char X[55][55];

void uncover(int x,int y){
	X[x][y+1]='.';
	X[x+1][y]='.';
	X[x+1][y+1]='.';
}

void solve_case(){
	scanf("%d%d%d",&R,&C,&M);
	int F=R*C-M;
	memset(X,'*',sizeof(X));
	X[0][0]='c';
	if (R==1){
		for(int i=1;i<F;++i)
			X[0][i]='.';
	}
	if (C==1){
		for(int i=1;i<F;++i)
			X[i][0]='.';
	}
	int ok=0;
	if (F==1||R==1||C==1) ok=1;
	if (!ok){
		int r=0,c=0;
		if (F>=4){
			r=c=1;
			F-=4;
			uncover(0,0);
		if (F>=2&&r+1<R){
			F-=2;
			uncover(r,0);
			++r;
		}
		if (F>=2&&c+1<C){
			F-=2;
			uncover(0,c);
			++c;
		}
		if ((r==2&&c==2)||C==2||R==2){
			while(F>=2&&r+1<R){
				F-=2;
				uncover(r,0);
				++r;
			}
			while(F>=2&&c+1<C){
				F-=2;
				uncover(0,c);
				++c;
			}
			if (C>2&&R>2)
			for(r=1,c=1;F;
					r=c==C-2?r+1:r,
					c=c==C-2?1:c+1){
				F--;
				uncover(r,c);
			}
		}
		if (!F) ok=1;
		}
	}
	if (!ok){
		puts("Impossible");
		return;
	}
	for(int i=0;i<R;++i){
		for(int j=0;j<C;++j){
			printf("%c",X[i][j]);
		}
		puts("");
	}
}

int main(){
	int cases;
	scanf("%d",&cases);
	for(int t=1;t<=cases;++t){
		printf("Case #%d:\n",t);
		solve_case();
	}
	return 0;
}

