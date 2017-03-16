#include <stdio.h>

int casos;
char mapa[4][4];

void lee(){
	for(int i = 0;i < 4;i++){
		scanf("\n");
		for(int j = 0;j < 4;j++){
			scanf("%c",&mapa[j][i]);
		}
		scanf("\n");
	}
}
bool checa(char x){
	bool res = true;
	for(int i = 0;i < 4;i++){
		for(int j = 0;j < 4;j++){
			if(mapa[j][i] != x && mapa[j][i] != 'T')
				res = false;
		}
		if(res == true)
			return true;
		res = true;
	}
	for(int i = 0;i < 4;i++){
		for(int j = 0;j < 4;j++){
			if(mapa[i][j] != x && mapa[i][j] != 'T')
				res = false;
		}
		if(res == true)
			return true;
		res = true;
	}
	for(int i = 0;i < 4;i++){
		if(mapa[i][i] != x && mapa[i][i] != 'T')
			res = false;		
	}
	if(res == true)
		return true;
	res = true;	
	for(int i = 0;i < 4;i++){
		if(mapa[i][3-i] != x && mapa[i][3-i] != 'T')
			res = false;		
	}
	if(res == true)
		return true;
	return false;		
}
int cuentaPuntos(){
	int r = 0;
	for(int i= 0;i < 4;i++)
		for(int j = 0;j < 4;j++)
			if(mapa[j][i] == '.')
				r++;
	return r;
}
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&casos);
	for(int i = 1;i <= casos;i++){
		lee();
		printf("Case #%d: ",i);
		if(checa('X'))
			printf("X won\n");
		else if(checa('O'))
			printf("O won\n");
		else if(cuentaPuntos() == 0)
			printf("Draw\n");
		else
			printf("Game has not completed\n");
	}
	return 0;
}
