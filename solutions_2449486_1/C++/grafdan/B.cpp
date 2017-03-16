#include <cstdio>
#define MAXNM 110
using namespace std;

int T;
int A[MAXNM][MAXNM];
int X,Y,x,y;

bool check() {
	// row
	// printf("check with %d %d\n",x,y);
	bool is_valid_line = true;
	for(int i=0;i<Y;i++) {
		// printf("A[%d][%d] = %d ->  %d\n",x,i,A[x][i],is_valid_line);
		if(A[x][i] > A[x][y]) is_valid_line = false;
	}
	if(is_valid_line) return true;
	// column
	is_valid_line = true;
	for(int i=0;i<X;i++) {
		if(A[i][y] > A[x][y]) is_valid_line = false;
	}
	return is_valid_line;
}

bool testc() {
	scanf("%d %d",&X,&Y);
	for(x=0;x<X;x++) {
		for(y=0;y<Y;y++) {
			scanf("%d",&(A[x][y]));
		}
	}
	for(x=0;x<X;x++) {
		for(y=0;y<Y;y++) {
			if(!check()) return false;
		}
	}
	return true;
}

int main() {
	scanf("%d\n",&T);
	for(int t=0;t<T;t++) {
		bool b = testc();
		printf("Case #%d: ",t+1);
		if(b) printf("YES\n");
		else printf("NO\n");
	}

}