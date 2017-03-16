#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int H,N,X,Y,T;
float A[40][40];
float solve(){
	scanf("%d%d%d",&N,&X,&Y);
	if (X<0) X*=-1;
	int t=-2,c=0,a=1;
	for (;c+a<=N;c+=a,a+=4,t+=2);
	if (X+Y>t+2) return 0;
	if (X+Y<=t) return 1;
	else {
		if (2*Y+1>a-1) return 0;
		int C=Y+1;
		N-=c;
		float V=0;
		for (int x=C;x<=N;x++) 	V+=A[x][N-x];
		return V;
	}
}
int main () {
	scanf("%d",&T);
	A[0][0]=1;
	for (int i=0;i<=20;i++) 
		for (int X=0;X<=i;X++) {
			int Y=i-X;
			A[X][Y+1]+=A[X][Y]/2.0;
			A[X+1][Y]+=A[X][Y]/2.0;
		}	
	for (int cs=1;cs<=T;cs++) printf("Case #%d: %.6f\n",cs,solve());
	scanf("\n");
	return 0;
}
