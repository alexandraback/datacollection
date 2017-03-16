#include <stdio.h>
#define INF (1<<29)
#define INDEF -1
int k,l,s;
char keyboard[200];
int keyboardLen;
int targetLen;
char target[200];
#include <algorithm>
#include <string.h>
int automatch;

double pd[200][200][200];
bool matcha[200][200];

double solve(int indice, int matches, int resposta){
	if(matches==targetLen){
		matches=automatch;
		resposta++;
	}
	if(indice==s)return resposta;
	if(pd[indice][matches][resposta]!=INDEF)return pd[indice][matches][resposta];
	double chance=1.0/keyboardLen;
	double ans = 0;
	for(int i=0;keyboard[i];i++){
		if(keyboard[i]==target[matches]){
			ans+=chance*solve(indice+1,matches+1,resposta);
		} else{
			int melhormatch=0;
			for(int j=0;j<matches;j++){
				if(target[j]==keyboard[i]){
					if(j==0 || matcha[matches-1][j-1]){
						melhormatch=j+1;	
					}
				}
			}
			ans+=chance*solve(indice+1,melhormatch,resposta);
		}
	}

	return pd[indice][matches][resposta]=ans;
}


int main(){
	int testes;
	scanf("%d",&testes);
	for(int xxx=0;xxx<testes;xxx++){
		
		scanf("%d %d %d",&k,&l,&s);
		scanf("%s",keyboard);
		scanf("%s",target);
		printf("Case #%d: ",xxx+1);

		bool temtodas=true;
		for(int i=0;target[i];i++){
			bool da=false;
			for(int j=0;keyboard[j];j++){
				if(target[i]==keyboard[j])da=true;
			}
			if(da==false)temtodas=false;
		}
		if(!temtodas){
			printf("%lf\n", 0);
			continue;
		}

		int maximo=0;

		for(int i=1;target[i];i++){
			bool igual=true;
			int count=0;
			for(int j=0;target[i+j];j++){
				if(target[i+j]!=target[j]){
					igual=false;
					break;
				}
				count++;
			}
			if(igual){
				maximo=std::max(maximo,count);
			}
		}
		
		keyboardLen=strlen(keyboard);
		targetLen=strlen(target);

		automatch=maximo;
		int iniciozinho=(targetLen-automatch);
		//printf("%d %d\n", automatch,iniciozinho);
		maximo= (s-automatch)/iniciozinho;
		//printf("%d\n", maximo);


		for(int i=0;target[i];i++){
			for(int j=0;target[j];j++){
				if(j>i)continue;
				bool da=true;
				for(int k=0;k<=j;k++){
					if(target[k]!=target[i-j+k]){da=false;break;}
				}
				matcha[i][j]=da;
				//printf("%d %d %d\n", i,j,da);
			}
		}

		
		for(int i=0;i<200;i++)for(int j=0;j<200;j++)for(int k=0;k<200;k++)pd[i][j][k]=INDEF;
		double ans = solve(0,0,0);
		printf("%lf\n",maximo-ans );



	}
}