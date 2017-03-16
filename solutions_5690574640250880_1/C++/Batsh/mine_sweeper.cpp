#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iterator>
#include <iostream>
#include <functional>
#include <sstream>
#include <numeric>

#define CLR( x , y ) ( memset( (x) , (y) , sizeof( (x) ) ) )
#define EPS 1e-9

using namespace std;

FILE *in=fopen("C.in","r");
FILE *out=fopen("C.out","w");

int n;

int ar[60][60];

bool seen[60][60];

bool check(int x,int y){
	if(x>=0 && y>=0  && ar[x][y]==1)return false;
	return true;
}

void make_seen(int x,int y){
	if(x>=0 && y>=0)seen[x][y]=1;
}

int main()
{
	int i,j,k,test,tests;
	fscanf(in,"%d",&tests);
	int n,m,x;
	for(test=1;test<=tests;test++){
		CLR(ar,-1);
		fscanf(in,"%d %d %d", &n,&m,&x);
		int on=n,om=m,ox=x;
		if (test==225){
			test++;
			test--;
		}
		while((x>=n || x>=m)) {
			if(n>=m) {
				x-=m;
				n--;
			}
			else {
				x-=n;
				m--;
			}
		}
		for(i=0;i<m-2 && x>0;i++){
			ar[n-1][m-i-1]=1;
			x--;
		}
		if (x==1) {
			if (ar[n-1][m-1]==-1)ar[n-1][m-1]=1;
			else ar[n-2][m-1]=1;
			x--;
		}
		for(i=0;i<on;i++){
			for(j=0;j<om;j++){
				if(i<n && j<m){
					if(ar[i][j]==-1)
						ar[i][j]=0;
				}
				else
					ar[i][j]=1;
			}
		}
		bool flag = false;
		CLR(seen,0);
		ar[0][0]=2;
		seen[0][0]=true;
		for(i=0;i<on;i++){
			for(j=0;j<om;j++){
				if(ar[i][j]!=1){
					if(seen[i][j] && check(i-1,j) && check(i+1,j) && check(i+1,j+1) && check(i+1,j-1) && check(i-1,j+1) && check(i-1,j-1) && check(i,j+1) && check(i,j-1)){
						make_seen(i-1,j);
						make_seen(i+1,j);
						make_seen(i-1,j+1);
						make_seen(i+1,j+1);
						make_seen(i-1,j-1);
						make_seen(i+1,j-1);
						make_seen(i,j+1);
						make_seen(i,j-1);
						flag = true;
					}
				}
			}
		}
		for(i=0;i<on;i++){
			for(j=0;j<om;j++){
				if(!seen[i][j] && !ar[i][j])flag=false;
			}
		}
		if((x || !flag) && n*m-x !=1) {
			fprintf(out,"Case #%d:\nImpossible\n",test);
		} else {
			fprintf(out,"Case #%d:\n",test);
			for(i=0;i<on;i++){
				for(j=0;j<om;j++){
					if(ar[i][j]==0)fprintf(out,".");
					if(ar[i][j]==1)fprintf(out,"*");
					if(ar[i][j]==2)fprintf(out,"c");
				}
				fprintf(out,"\n");
			}
		}
	}
	return 0;
}
