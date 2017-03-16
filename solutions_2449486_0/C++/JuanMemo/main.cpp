#include <stdio.h>

int casos,ancho,alto,mapa[102][102];

void lee(){
	scanf("%d %d",&alto,&ancho);
	int j;
	for(int i = 0;i < alto;i++)
		for(j = 0;j < ancho;j++)
			scanf("%d",&mapa[j][i]);
}
bool sePuede(int x,int y){
	bool res = true;
	for(int i = 0;i < ancho;i++){
		if(mapa[i][y] > mapa[x][y]){
			res = false;
			break;
		}
	}
	if(res)
		return true;
	res = true;
	for(int i = 0;i < alto;i++){
		if(mapa[x][i] > mapa[x][y]){
			res = false;
			break;
		}
	}
	return res;
}
bool prueba(){
	int j;
	for(int i = 0;i < alto;i++)
		for(j = 0;j < ancho;j++)
			if(!sePuede(j,i))
				return false;
	return true;
}
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&casos);
	for(int i = 1;i <= casos;i++){
		lee();
		printf("Case #%d: ",i);
		if(prueba())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
