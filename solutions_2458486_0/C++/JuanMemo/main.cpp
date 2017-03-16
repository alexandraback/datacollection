#include <stdio.h>
#include <string.h>

struct tesoro{int tipo,llaves,llave[40];};
tesoro chest[22];
int casos,llaves,tesoros,llave[201],serie[22],usados[2000000],abiertos,restantes;

void lee(){
	int num;
	scanf("%d %d",&llaves,&tesoros);
	for(int i = 0;i < llaves;i++){
		scanf("%d",&num);
		llave[num]++;
	}
	for(int i = 0;i < tesoros;i++){
		scanf("%d %d",&chest[i].tipo,&chest[i].llaves);
		for(int j = 0;j < chest[i].llaves;j++){
			scanf("%d",&chest[i].llave[j]);
		}
	}
}
void reset(){
	memset(usados,0,sizeof(usados));
	memset(llave,0,sizeof(llave));
	abiertos = 0;
}
bool busqueda(){
	if(restantes != 0){
		if(usados[abiertos] == 0){
			usados[abiertos] = 1;
			for(int k = 0;k < tesoros;k++){
				if(((abiertos >> k) & 1) == 0 && llave[chest[k].tipo] > 0){
					llave[chest[k].tipo]--;
					serie[tesoros-restantes] = k;
					restantes--;
					for(int j = 0;j < chest[k].llaves;j++)
						llave[chest[k].llave[j]]++;
					abiertos |= (1<<k);
					if(busqueda())
						return true;
					llave[chest[k].tipo]++;
					for(int j = 0;j < chest[k].llaves;j++)
						llave[chest[k].llave[j]]--;
					abiertos &= (~(1<<k));
					restantes++;
				}
			}
		}else{
			return false;
		}
	}else{
		for(int i = 0;i < tesoros;i++){
			printf("%d ",serie[i]+1);
		}
		printf("\n");
		return true;
	}
	return false;
}
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&casos);
	for(int i = 1;i <= casos;i++){
		reset();
		lee();
		printf("Case #%d: ",i);
		restantes = tesoros;
		if(!busqueda())
			printf("IMPOSSIBLE\n");
	}
	return 0;
}
