#include <cstdio>
#include <cmath>
#include <cassert>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
typedef pair<int,int> ii;
#define x first
#define y second
int r,c,m;
char out[51][51];

bool solve_0(){
	int cont=0;
	memset(out,'.',sizeof out);
	for(int i=1; i<=r-2; i++){
		for(int j=1; j<=c-2; j++){
			if(cont<m){
				cont++;
				out[i][j] = '*';
			}else{
				out[i][j] = '.';
			}
		}
	}
	if( ((m-cont)%2)==0 ){
		for(int i=1; i<=r-2 && cont<m; i++){
			out[i][c-1] = out[i][c] = '*';
			cont+=2;
		}

		for(int j=1; j<=c-2 && cont<m; j++){
			out[r-1][j] = out[r][j] = '*';
			cont+=2;
		}
		out[r][c] = 'c';
		return true;	
	}else{
		return false;
	}
}

bool solve_1(){
	int rk,ck,v,middle;
	bool ok = false;
	
	for(rk=0; rk<=r-2 && !ok; rk++){
		for(ck=0; ck<=c-2 && !ok; ck++){
			v = rk*c + ck*r;
			v -= rk*ck;
			middle = (r-2)*(c-2) - ( rk*(c-2) + ck*(r-2) ) + rk*ck;
			if(v==m){
				ok = true;
				goto L1;
			}else if(v<m && (m-v) <= middle){
				ok = true;
				goto L1;
			}
		}
	}
	L1:
	if(ok){
		memset(out,'.',sizeof out);
		int cont = 0;
		for(int i=1; i<=rk; i++){
			for(int j=1; j<=c; j++){
				out[i][j]='*';
				cont++;
			}
		}
		for(int j=1; j<=ck; j++){
			for(int i=1; i<=r; i++){
				if(out[i][j]!='*'){
					out[i][j]='*';
					cont++;
				}
			}
		}
		for(int i=1; i<=r-2 && cont<m; i++){
			for(int j=1; j<=c-2 && cont<m; j++){
				if(out[i][j]=='.'){
					cont++;
					out[i][j]='*';
				}
			}
		}

		out[r][c] ='c';
		return true;
	}else{
		return false;
	}
}

void print_out(){
	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++){
			printf("%c",out[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int t;
	scanf("%d",&t);
	for(int test=1; test<=t; test++){
		scanf("%d %d %d",&r,&c,&m);
		assert(r*c>m);
		printf("Case #%d:\n",test);
		if(r==1 || c==1 || (r*c-1)==m){
			int cont=0;
			for(int i=1; i<=r; i++){
				for(int j=1; j<=c; j++){
					if(cont<m){
						cont++;
						printf("*");
					}else if(i==r && j==c){
						printf("c");
					}else{
						printf(".");
					}
				}
				printf("\n");
			}
		}else if( m>(r*c-4) ){
			printf("Impossible\n");
		}else{
			if(!solve_0()){
				if(!solve_1()){
					printf("Impossible\n");
					continue;	
				}
			}
			int cont=0;
			for(int i=1; i<=r; i++){
				for(int j=1; j<=c; j++){
					printf("%c",out[i][j]);
					if(out[i][j]=='*'){
						cont++;
					}
				}
				printf("\n");
			}
			assert(cont==m);
		}

	}
	return 0;
}