#include <stdio.h>
#include <algorithm>


void printcasenull(int r, int c){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(i==0 && j==0)printf("c");
			else printf(".");
		}
		printf("\n");
	}
}

void printcaseoneleft(int r, int c){
	for(int i =0;i<r;i++){
		for(int j=0;j<c;j++){
			if(i==0 && j==0)printf("c");
			else printf("*");
		}
		printf("\n");
	}
}

void printcase1(int r, int c, int m){
	int cont=0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(i==0 && j==0){
				printf("c");
			}
			else if(cont>=r*c-m){
				printf("*");
			}
			else{
				printf(".");
			}
			cont++;
		}
		printf("\n");
	}
}

void printcase2(int r, int c, int m){
	int cont=0;
	for(int i =0;i<r;i++){
		for(int j=0;j<c;j++){
			if(i==r-1 && j==c-1){
				printf("c");
			}
			else if(j<c-2 && cont<m){
				cont++;
				printf("*");
			} else{
				printf(".");
			}
		}
		printf("\n");
	}
}

void printgeneric(int r, int c, int deltar, int deltac, int completar, int completac, int restor, int restoc){
	//printf("%d %d %d %d %d %d %d %d\n",r,c,deltar,deltac, completar, completac, restor, restoc );
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(i==r-1 && j==c-1){
				printf("c");
			}
			else if(i<r-deltar && j<c-deltac){
				printf("*");
			}
			else if(i<r-deltar){
				if(i<completar){
					printf("*");
				}
				else if(i==completar && j<c-deltac+restor){
					printf("*");
				}
				else{
					printf(".");
				}
			}
			else if(j<c-deltac){
				if(j<completac){
					printf("*");
				}
				else if(j==completac && i<r-deltar+restoc){
					printf("*");
				}
				else{
					printf(".");
				}
			}
			else{
				printf(".");
			}
		}
		printf("\n");
	}
}

bool test(int r,int c,int m,int deltar,int deltac){
	int m1=m-(r-deltar)*(c-deltac);
	for(int completar=0;completar<r-deltar;completar++){
		int m2=m1-completar*deltac;
		if(m2<0)break;
		for(int completac=0;completac<c-deltac;completac++){	
			int m3=m2-completac*deltar;
			if(m3<0)break;
			if(m3<=deltar && m3!=deltar-1){
				printgeneric(r,c,deltar,deltac,completar,completac,m3,0);
				return true;
			}
			if(m3<=deltac && m3!=deltac-1){
				printgeneric(r,c,deltar,deltac,completar,completac,0,m3);
				return true;
			}
			if(m3<=deltac+deltar && m3!=deltar+deltac-1){
				if(m3>=deltar){	
					printgeneric(r,c,deltar,deltac,completar,completac,m3-deltar,deltar);
					return true;
				}
				if(m3>=deltac){
					printgeneric(r,c,deltar,deltac,completar,completac,deltac,m3-deltac);
					return true;
				}
				if(m3==deltar-1 && deltac!=2){
					printgeneric(r,c,deltar,deltac,completar,completac,1,m3-1);
					return true;
				}
				if(m3==deltac-1 && deltar!=2){
					printgeneric(r,c,deltar,deltac,completar,completac,m3-1,1);
					return true;
				}
			}

		}
	}
	return false;
}

void printcase3(int r,int c, int m){
	int cont=0;
	if(c==2){
		for(int i =0;i<r;i++){
			for(int j=0;j<c;j++){
				if(i==r-1 && j==c-1){
					printf("c");
				}else if(cont<m){
					cont++;
					printf("*");
				}else{
					printf(".");
				}
			}
			printf("\n");
		}
	}else{//r==2
		for(int i =0;i<r;i++){
			cont=0;
			for(int j=0;j<c;j++){
				if(i==r-1 && j==c-1){
					printf("c");
				}else if(cont<m/2){
					cont++;
					printf("*");
				}else{
					printf(".");
				}
			}
			printf("\n");
		}
	}
}

void printemr(int r, int c, int m){
	int cont=0;
	for(int i =0;i<r;i++){
		for(int j=0;j<c;j++){
			if(i==r-1 && j==c-1){
				printf("c");
			}
			else if(cont<m){
				printf("*");
				cont++;
			}
			else{
				printf(".");
			}
		}
		printf("\n");
	}

}
char auxiliar[100][100];
void printemc(int r, int c, int m){
	int cont=0;
	for(int j=0;j<c;j++){
		for(int i =0;i<r;i++){
			if(i==r-1 && j==c-1){
				auxiliar[i][j]='c';
			}
			else if(cont<m){
				auxiliar[i][j]='*';
				cont++;
			}
			else{
				auxiliar[i][j]='.';
			}
		}
	}	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			printf("%c",auxiliar[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int t;
	scanf("%d",&t);
	for(int xxx=0;xxx<t;xxx++){
		printf("Case #%d:\n",xxx+1);
		int r,c,m;
		scanf("%d %d %d",&r,&c,&m);
		//printf("%d %d %d\n", r,c,m);
		if(m==0){
			printcasenull(r,c);
			continue;
		}
		if(m==(r*c)-1){
			printcaseoneleft(r,c);
			continue;
		}
		if(r==1 || c==1){
			printcase1(r,c,m);
			continue;
		}
		if(m<=(r-2)*(c-2)){
			printcase2(r,c,m);
			continue;
		}
		if(m>r*c-4){
			printf("Impossible\n");
			continue;
		}
		if(r==2 || c==2){
			if(m%2==0){
				printcase3(r,c,m);
				continue;
			}
		}
		if(m<=(r-2)*c && m%c!=c-1){
			printemr(r,c,m);
			continue;
		}
		if(m<=(c-2)*r && m%r!=r-1){
			printemc(r,c,m);
			continue;			
		}
		bool impossible = true;
		for(int deltar=2; deltar<=r;deltar++){
			for(int deltac=2;deltac<=c;deltac++){
				//printf("%d %d\n", deltar, deltac);
				if(test(r,c,m,deltar,deltac)){
					impossible=false;
				}
				if(!impossible)break;
			}
			if(!impossible)break;
		}
		if(!impossible)continue;
		printf("Impossible\n");
	}
}