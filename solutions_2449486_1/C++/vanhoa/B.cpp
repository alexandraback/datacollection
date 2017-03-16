#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int target[101][101];
int board[1][101][101];
int currBoard;
int maxTargetR[101];
int maxTargetC[101];
struct TypeRC{
	int r,c;
	bool operator<(const TypeRC& o) const{
		return target[r][c]>target[o.r][o.c];
	}
} rc[101*101];
int nrc=0;
#define a board[currBoard]
int R,C;
void pushBoard(){
	memcpy(board[currBoard+1],board[currBoard],101*101*sizeof(int));
	currBoard++;
}
void popBoard(){
	currBoard--;
}

bool solve(){
	for(int i=0;i<R;i++) maxTargetR[i]=0;
	for(int i=0;i<C;i++) maxTargetC[i]=0;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			maxTargetR[i]=max(maxTargetR[i],target[i][j]);
			maxTargetC[j]=max(maxTargetC[j],target[i][j]);
		}
	}
	for(int i=0;i<nrc;i++){
		int r=rc[i].r, c=rc[i].c;
		int h=target[r][c];
		if(maxTargetR[r]<=h){
			for(int j=0;j<C;j++) a[r][j]=min(a[r][j],h);
		}
		else if(maxTargetC[c]<=h){
			for(int j=0;j<R;j++) a[j][c]=min(a[j][c],h);
		}
		else{
			//printf("cannot cut at %d %d h=%d | r=%d | c=%d\n",r,c,h,maxTargetR[r],maxTargetC[c]);
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]) {
	freopen("/Users/vanhoa/Documents/dev/codejam/B-large.in","r",stdin);
	freopen("/Users/vanhoa/Documents/dev/codejam/B-large.out","w",stdout);
	int T;scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d%d",&R,&C);
		currBoard=0;nrc=0;
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				scanf("%d",&target[i][j]);
				a[i][j]=100;
				rc[nrc].r=i;
				rc[nrc].c=j;
				nrc++;
			}
		}
		sort(rc,rc+nrc);
		printf("Case #%d: %s\n",t,solve()?"YES":"NO");
	}
}