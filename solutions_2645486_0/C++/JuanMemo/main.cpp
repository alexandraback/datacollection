#include <stdio.h>

int casos,energia,recupera,act,valores[20];

void lee(){
	scanf("%d %d %d",&energia,&recupera,&act);
	for(int i = 0;i < act;i++){
		scanf("%d",&valores[i]);
	}
}
int max(int x,int y){
	if(x > y)
		return x;
	return y;
}
int busca(int e,int pos){
	int val = 0;
	if(e < 0)
		return 0;
	e += recupera;
	if(e > energia)
		e = energia;
	if(pos < act-1){
		for(int i = 0;i <= e;i++){
			val =  max(val,(i*valores[pos])+busca(e-i,pos+1));
		}
	}else{
		return valores[pos] * e;
	}
	return val ;
}
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&casos);
	for(int i = 1;i <= casos;i++){
		lee();
		printf("Case #%d: %d\n",i,busca(energia,0));
	}
	return 0;
}
