#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)

using namespace std;

typedef long double K;

bool ok;
int m, r, c;
char M[53][53];

int main(){
	int zz; scanf("%d", &zz);
	FWD(z,1,zz+1){
		scanf("%d %d %d", &r, &c, &m);
		m = r*c - m;
		FWD(i,0,r){
			FWD(j,0,c)
				M[i][j] = '*';
			M[i][c] = 0;
		}
		ok = true;
		if(m == 1){
			M[0][0] = 'c';
		}else if(r == 1 || c == 1){
			if(r == 1)
				FWD(i,0,m) M[0][i] = '.';
			else
				FWD(i,0,m) M[i][0] = '.';
			M[0][0] = 'c';
		}else if(r == 2 || c == 2){
			if((m&1) || m == 2)
				ok = false;
			if(r == 2)
				FWD(i,0,m/2)
					M[0][i] = M[1][i] = '.';
			else
				FWD(i,0,m/2)
					M[i][0] = M[i][1] = '.';
			M[0][0] = 'c';
		}else{
			if(m == 2 || m == 3 || m == 5 || m == 7)
				ok = false;
			int i = 0, j = 0;
			while(m > 1 && j != c){
				M[i][j] = M[i+1][j] = '.';
				++j;
				m -= 2;
			}
			if(m == 1){
				--j;
				M[i][j] = M[i+1][j] = '*';
				M[i+2][0] = M[i+2][1] = M[i+2][2] = '.';
				--m;
			}
			i = 2, j = 0;
			while(m > 1 && i != r){
				M[i][j] = M[i][j+1] = '.';
				++i;
				m -= 2;
			}
			i = 2, j = 2;
			while(m){
				M[i][j] = '.';
				--m;
				++j;
				if(j == c){
					++i;
					j = 2;
				}
			}
			M[0][0] = 'c';
		}
		printf("Case #%d:\n", z);
		if(ok)
			FWD(i,0,r) printf("%s\n", M[i]);
		else
			printf("Impossible\n");
	}
	return 0;
}
