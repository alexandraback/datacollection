#include <stdio.h>
#include <string.h>

struct pos{int x,y,padre,m;char p;};
int mapa[10000][10000],casos,x,y,moves[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
char r[502];
pos cola[100000000];

char checa(int a){
	char c;
	if(a == 0)
		return 'N';
	if(a == 1)
		return 'E';
	if(a == 2)
		return 'W';
	return 'S';	
}
int busca(){
	int ini = 0,fin = 0,nx,ny;
	cola[ini].x = 0;
	cola[ini].y = 0;
	cola[ini].m = 1;
	cola[ini].padre = -1;
	while(true){
		for(int i = 0;i < 4;i++){
			nx = cola[ini].x + moves[i][0]*cola[ini].m;
			ny = cola[ini].y + moves[i][1]*cola[ini].m;
			if(mapa[nx+5000][ny+5000] != cola[ini].m){
				mapa[nx+5000][ny+5000] = cola[ini].m;
				cola[++fin].x = nx;
				cola[fin].y = ny;
				cola[fin].m = cola[ini].m+1;
				cola[fin].padre = ini;
				cola[fin].p = checa(i);
				if(nx == x && ny == y)
					return fin;
			}
		}
		ini++;
	}
}
void imprime(int pos,int caso){
	int fin = 0;
	printf("Case #%d: ",caso);
	while(pos != 0){
		r[fin++] = cola[pos].p;
		pos = cola[pos].padre;
	}
	while(--fin >= 0){
		printf("%c",r[fin]);
	}
	printf("\n");
}
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&casos);
	for(int i = 1;i <= casos;i++){
		scanf("%d %d",&x,&y);
		imprime(busca(),i);
		memset(mapa,0,sizeof(mapa));
	}
	return 0;
}
