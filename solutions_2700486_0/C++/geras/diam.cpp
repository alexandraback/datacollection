// Author: Kamil Niziński
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define debug(fmt,...) //fprintf(stderr,fmt, ## __VA_ARGS__)
#define mp make_pair
#define ft first
#define sd second
using namespace std;
typedef long long int ll;
typedef long long unsigned llu;
typedef double dd;
//const int inf=1000000009;
const int shiftx=50;
int N,X,Y,good,all;
bool T[101][101];
void backtrack(int left,int LX, int LY, int PX, int PY) {
	if(left==0) {
		if(T[X+shiftx][Y]) good++;
		all++;
		return;
	}
	if(LX==0&&PX==0) {
		T[LX+shiftx][LY]=1;
		backtrack(left-1,-LY-2,0,LY+2,0);
		T[LX+shiftx][LY]=0;
	}
	else {
		if(LX<0) {
			T[LX+shiftx][LY]=1;
			backtrack(left-1,LX+1,LY+1,PX,PY);
			T[LX+shiftx][LY]=0;
		}
		if(PX>0) {
			T[PX+shiftx][PY]=1;
			backtrack(left-1,LX,LY,PX-1,PY+1);
			T[PX+shiftx][PY]=0;
		}
	}
}
void solve() {
	scanf("%d%d%d",&N,&X,&Y);
	if(X>45||X<-45||Y>45) {
		printf("0.0\n");
		return;
	}
	good=all=0;
	backtrack(N,0,0,0,0);
	debug("%d %d\n",good,all);
	dd odp=1.0*(dd)good/((dd)all);
	printf("%.6lf\n",odp);
}
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++) {
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
