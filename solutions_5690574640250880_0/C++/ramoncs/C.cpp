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
int mine[51][51];
int di[]={-1,-1,-1,0,1,1, 1, 0};
int dj[]={-1, 0, 1,1,1,0,-1,-1};
bool valid(int i, int j){
	return i>0 && j>0 && j<=c && i<=r;
}
/*

bool vis[51][51];
void pre_fill(){
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
}

void pos_fill(){
	for(int i=1; i<=r-2; i++){
		for(int j=c-1; j<=c; j++){
			if(cont<m){
				cont++;
				out[i][j] = '*';
			}else{
				out[i][j] = '.';
			}
		}
	}

	for(int j=1; j<=c; j++){
		for(int i=r-1; i<=r; i++){
			if(cont<m){
				cont++;
				out[i][j] = '*';
			}else{
				out[i][j] = '.';
			}
		}
	}
}


bool flood_fill(ii s){
	memset(vis,false,sizeof vis);
	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++){
			if(out[i][j]=='*'){
				vis[i][j]=true;
				//printf("from %d %d\n",i,j);
				for(int k=0; k<8; k++){
					int ni=i+di[k];
					int nj=j+dj[k];
					//printf("(%d %d)\n",ni,nj);
					if(valid(ni,nj)){
						//printf("set %d %d\n",ni,nj);
						vis[ni][nj] = true;
					}
				}
			}
		}
	}
	printf("vis:\n");
	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++){
			printf("%d ", vis[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	queue<ii> Q;
	Q.push(s);
	while(!Q.empty()){
		ii p = Q.front();Q.pop();
		if(vis[p.x][p.y]) continue;
		vis[p.x][p.y] = true;
		printf("%d %d foi\n",p.x,p.y);
		for(int k=0; k<8; k++){
			int ni = p.x+di[k];
			int nj = p.y+dj[k];
			if(valid(ni,nj) && !vis[ni][nj])
				Q.push(ii(ni,nj));
		}
	}
	for(int i=1; i<=r; i++)
		for(int j=1; j<=c; j++)
			if(!vis[i][j]) return false;
	return true;
}
*/
void fill_mine(){
	memset(mine,0,sizeof mine);
	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++){
			//printf("from %d %d\n",i,j);
			for(int k=0; k<8 && (out[i][j]=='*'); k++){
				int ni = i + di[k];
				int nj = j + dj[k];
				//printf("to %d %d\n",ni,nj);
				if(valid(ni,nj) && out[ni][nj]=='.'){
					mine[ni][nj]++;
				}
			}
		}
	}
}

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
				//printf("tamos aqui rk: %d ck:%d v:%d middle:%d\n",rk,ck,v,middle);
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
			//print_out(r,c);
			//fill_mine();
			int cont=0;
			for(int i=1; i<=r; i++){
				for(int j=1; j<=c; j++){
					printf("%c",out[i][j]);
					if(out[i][j]=='*'){
						cont++;
					}
					/*else
						printf("%d",mine[i][j]);*/
				}
				printf("\n");
			}
			assert(cont==m);
		}

	}
	return 0;
}