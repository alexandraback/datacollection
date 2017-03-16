#include <stdio.h>
#define INF (1<<29)
int r,c,w;
int pd[5000000];
#include <algorithm>

void print(int x){
	for(int i=0;i<c;i++){
		if((x&(1<<i))>0)printf("1");
		else printf("0");
	}
}

int jogar(int mascara, int acertos){
	if(pd[mascara]!=-1)return pd[mascara];
	if(__builtin_popcount(acertos)==w)return pd[mascara]=0;
	//print(mascara);
	//printf("\n");
	//print(acertos);
	//printf("\n----\n");
	int ans=INF;
	for(int i=0;i<c;i++){
		if((mascara&(1<<i))>0)continue;
		
		int novaMascara = mascara|(1<<i);
		bool da=true;
		int acertoDoLugar=0;
		for(int j=0;j<w;j++){
			if((novaMascara&(1<<j))>0){
				acertoDoLugar|=(1<<j);
			}
		}
		if(acertoDoLugar==acertos){
			da=false;
		}
		for(int j=w;j<c;j++){
			acertoDoLugar&=(~(1<<(j-w)));
			if((novaMascara&(1<<j))>0){
				acertoDoLugar|=(1<<j);
			}
			if(acertoDoLugar==acertos)da=false;
		}
		int novosAcertos = acertos;
		if(da)novosAcertos|=(1<<i);

		ans=std::min(ans,jogar(novaMascara,novosAcertos)+1);
	}
	return pd[mascara]=ans;

}
#include <string.h>

int main(){
	int testes;
	scanf("%d",&testes);
	for(int xxx=0;xxx<testes;xxx++){
		
		scanf("%d %d %d",&r,&c,&w);
		int ans=(c/w)*(r-1);
		memset(pd,-1,sizeof(pd));
		printf("Case #%d: %d\n", xxx+1,ans+jogar(0,0));

	}
}