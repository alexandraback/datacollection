#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char board[51][50];

int solve(int r, int c, int m, int s){
	//printf("%d %d %d %d\n", r, c, m, s);
	int e;
	if(r==2){
		if((e=r*c-m)&1 || (e>>1)<s){
			return -1;
		} else {
			memset(board, '.', e>>1);
			memset(&board[1][0], '.', e>>1);
			return (e>>1);			
		}
	}

	if (c>=m && c-m!=1){
		memset(board, '.', 50*(r-1));
		memset(&board[r-1][0], '.', c-m);
		return (c-m);
	}

	for(int i=s; i<c; ++i){
		if(i!=1 && m+i-c>0 && solve(r-1, c, m+i-c, i)>=0){
			return i;
		}

		board[r-1][i] = '.';
	}

	return -1;
}

int main(){
	int t, i, j, k, r, c, m, e;
	bool s, p;

	cin>>t;
	for (i = 0; i < t; ++i){
		cin>>r>>c>>m;
		e = r*c-m;

		printf("Case #%d:\n", i+1);

		if(r>c){
			k=r;r=c;c=k;
			s = true;
		} else {
			s = false;
		}

		if (r>1 && (e==2||e==3||e==5||e==7)){
			printf("Impossible\n");
			continue;
		} 

		memset(board, '*', sizeof(board));

		if(r==1){
			memset(&board[0][1], '.', e-1);
		} else if(e!=1) {
			if (solve(r, c, m, 0)<0){
				printf("Impossible\n");
				continue;
			}
		}

		board[0][0] = 'c';
		if(s){k=r;r=c;c=k;}
		for(j=0; j<r; ++j){
			for(k=0; k<c; ++k)
				if(!s) printf("%c", board[j][k]);
				else printf("%c", board[k][j]);
			printf("\n");
		}
	}
	
	return 0;
}