#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;


int TTT,a[20][20];
char tmp[20],s[20][20];

bool check(){
/*	for (int i=0; i<4; i++){
		for (int j=0; j<4; j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}*/
	for (int i=0; i<4; i++){
		for (int j=0; j+3<4; j++){
			bool t=true;
			for (int k=j+0; k<j+4; k++){
				if (!a[i][k]) t=false;
			}
			if (t) return true;
		}
	}
	for (int i=0; i<4; i++){
		for (int j=0; j+3<4; j++){
			bool t=true;
			for (int k=j+0; k<j+4; k++){
				if (!a[k][i]) t=false;
			}
			if (t) return true;
		}
	}
	
	for (int l=-3; l<4; l++){
		for (int j=0; j+3<4; j++){
			bool t=true;
			for (int k=j; k<j+4; k++){
				int i=k+l;
				if (i<0 || i>=4) { t=false; break; }
				if (!a[i][k]) t=false;
			}
			if (t) return true;
		}
	}
	
	for (int l=0; l<6; l++){
		for (int j=0; j+3<4; j++){
			bool t=true;
			for (int k=j; k<j+4; k++){
				int i=l-k;
				if (i<0 || i>=4) { t=false; break; }
				if (!a[i][k]) t=false;
			}
			if (t) return true;
		}
	}
	
	return false;
}


int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&TTT);
	for (int TT=1; TT<=TTT; TT++){
		printf("Case #%d: ",TT);
		for (int i=0; i<4; i++) scanf("%s",s[i]);
		
		//for (int i=0; i<4; i++) printf("%s\n",s[i]);
		
		char ch='X';
		for (int i=0; i<4; i++){
			for (int j=0; j<4; j++){
				if (s[i][j]==ch || s[i][j]=='T'){
					a[i][j]=1;
				}
				else a[i][j]=0;
				
			}
		}
		if (check()){
			printf("X won\n"); continue;
		}
		
		ch='O';
		for (int i=0; i<4; i++){
			for (int j=0; j<4; j++){
				if (s[i][j]==ch || s[i][j]=='T'){
					a[i][j]=1;
				}
				else a[i][j]=0;
				
			}
		}
		if (check()){
			printf("O won\n"); continue;
		}
		
		bool hasdot=false;
		for (int i=0; i<4; i++){
			for (int j=0; j<4; j++){
				if (s[i][j]=='.'){
					hasdot = true; break;
				}
			}
			if (hasdot) break;
		}
		if (!hasdot){
			printf("Draw\n"); continue;
		}
		
		printf("Game has not completed\n");
	}
	
	fclose(stdout);
	fclose(stdin);
}
