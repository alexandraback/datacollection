#include<stdio.h>
#include<algorithm>
using namespace std;



char s[5][5];

bool c(char k){


	if(s[0][0]==k){
		if(s[0][0]==k && s[0][1]==k && s[0][2]==k && s[0][3]==k) return true;
		if(s[0][0]==k && s[1][0]==k && s[2][0]==k && s[3][0]==k) return true;
		if(s[0][0]==k && s[1][1]==k && s[2][2]==k && s[3][3]==k) return true;
	}

	if(s[0][3]==k){
		if(s[0][3]==k && s[1][3]==k && s[2][3]==k && s[3][3]==k) return true;
		if(s[3][0]==k && s[2][1]==k && s[1][2]==k && s[0][3]==k) return true;
	}
	
	if(s[3][1]==k){
		if(s[0][1]==k && s[1][1]==k && s[2][1]==k && s[3][1]==k) return true;
		if(s[3][0]==k && s[3][1]==k && s[3][2]==k && s[3][3]==k) return true;
	}

	if(s[2][2]==k){
		if(s[0][2]==k && s[1][2]==k && s[2][2]==k && s[3][2]==k) return true;
		if(s[2][0]==k && s[2][1]==k && s[2][2]==k && s[2][3]==k) return true;
	}

	if(s[1][0]==k && s[1][1]==k && s[1][2]==k && s[1][3]==k) return true;
	
	return false;

}

int main(){
	int n,i,j,k,x,y;
	bool e,t;
//	freopen("A-large.in","r",stdin);
//	freopen("A-large.txt","w",stdout);
	scanf("%d",&n);
	getchar();
	for(i=1;i<=n;i++){

		printf("Case #%d: ",i);

		gets(s[0]);
		gets(s[1]);
		gets(s[2]);
		gets(s[3]);
		gets(s[4]);
		t=e=false;

		for(j=0;j<4;j++){
			for(k=0;k<4;k++){
				if(s[j][k]=='T') {x=j;y=k;t=true;}
				if(s[j][k]=='.') e=true;
			}
		}

		if(t)
			s[x][y]='X';
		if(c('X')){
			printf("X won\n");
		}

		else {
			if(t)
				s[x][y]='O';
			if(c('O'))
				printf("O won\n");
			else if(e)
				printf("Game has not completed\n");
			else
				printf("Draw\n");
		}
	}


return 0;
}
