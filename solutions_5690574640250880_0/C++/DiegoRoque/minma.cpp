#include<cstdio>
#include<iostream>
#include<cassert>
using namespace std;

char car[]={'*','.'},mapa[55][55];
int U,R,C;
void checar(int a,int b){
	if(a<0 or a>=R or b<0 or b>=C) return;
	if(mapa[a][b]!='.') return;
	mapa[a][b]='x';
	U--;
	bool adentro=(((a<=0) or (b<=0) or mapa[a-1][b-1]!='*' )  and ((a<=0) or mapa[a-1][b]!='*' ) and ((a<=0) or (b>=C-1) or mapa[a-1][b+1]!='*') and ((b<=0) or mapa[a][b-1]!='*' ));
	adentro= adentro and ((b>=C-1) or mapa[a][b+1]!='*') and ((a>=R-1) or (b<=0) or mapa[a+1][b-1]!='*') and ((a>=R-1) or mapa[a+1][b]!='*' ) and ((a>=R-1) or (b>=C-1) or mapa[a+1][b+1]!='*');
	if(!adentro) return;
	checar(a-1,b-1);
	checar(a-1,b);
	checar(a-1,b+1);
	checar(a,b-1);
	checar(a,b+1);
	checar(a+1,b-1);
	checar(a+1,b);
	checar(a+1,b+1);
}

int main(){
	int T,t,M,F;
	t=0;
	bool resuelto;
	scanf("%d",&T);
	while(T--){
		t++;
		resuelto=false;
		scanf("%d%d%d",&R,&C,&M);
		F=R*C-M;//RM>=F>=1 siempre;
		printf("Case #%d:\n",t);
		if(R==1 or C==1){
			for(int i=0;i<R;i++) {
				for(int j=0;j<C;j++) {
					mapa[i][j]=car[(F>0)]; 
					if(F>0) F--; 
				} 
			}
			mapa[0][0]='c';
			resuelto=true;
		}
		else if(F==1){
			for(int i=0;i<R;i++) {
				for(int j=0;j<C;j++) {
					mapa[i][j]='*'; 
				} 
			}
			resuelto=true;
			mapa[0][0]='c';
		}
		else if(R==2){
			resuelto=(F>2) and ((F%2)==0);
			if(resuelto){
			F/=2;
			for(int i=0;i<R;i++){
				for(int j=0;j<F;j++){
					mapa[i][j]='.';
				}
				for(int j=F;j<C;j++){
					mapa[i][j]='*';
				}
			}
			mapa[0][0]='c';}
		}
		else if(C==2){
			resuelto=((F%2)==0) and (F>2);
			if(resuelto){
			F/=2;
			for(int i=0;i<F;i++){
				mapa[i][0]=mapa[i][1]='.';
			}
			for(int i=F;i<R;i++){
				mapa[i][0]=mapa[i][1]='*';
			}
			mapa[0][0]='c';}
		}
		else{
			resuelto = (((F%2)==0) and (F>=4) ) or (((F%2)==1) and (F>=9)  );
			if(resuelto){
				for(int i=0;i<R;i++) for(int j=0;j<C;j++) mapa[i][j]='*';
				mapa[0][0]='c';
				mapa[1][0]=mapa[0][1]=mapa[1][1]='.';
				if(F==6){
					mapa[2][0]=mapa[2][1]='.';
				}
				else if(F>=8){
					mapa[2][0]=mapa[2][1]=mapa[0][2]=mapa[1][2]='.';
					F-=8;
					for(int j=3;j<C and F>=2;j++){
						mapa[0][j]=mapa[1][j]='.';
						F-=2;
					}
					for(int i=3;i<R and F>=2;i++){
						mapa[i][0]=mapa[i][1]='.';
						F-=2;
					}
					for(int i=2; i<R and F>0;i++){
						for(int j=2;j<C and F>0; j++){
							mapa[i][j]='.';
							F--;
						}
					}

				}
			}
		}
		if(resuelto){
			for(int i=0;i<R;i++) { for(int j=0;j<C;j++) printf("%c",mapa[i][j]); printf("\n");}
			U=R*C-M;
			assert(mapa[0][0]=='c');
			mapa[0][0]='.';
			checar(0,0);
			assert(U==0);
		}
		else{
			printf("Impossible\n");

		}
	}
}
