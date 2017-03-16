#include<stdio.h>

char s[5][5];

int check(char c){
	
	int i,j,add;
	for(i=0;i<4;i++){
		add=0;
		for(j=0;j<4;j++){
			if(s[i][j] == c) add++;
		}
		if(add==4) return 1;
	}
	
	for(i=0;i<4;i++){
		add=0;
		for(j=0;j<4;j++){
			if(s[j][i]==c) add++;
		}
		if(add==4) return 1;
	}
	
	add=0;
	for(i=0;i<4;i++) if(s[i][i]==c) add++;
	if(add==4) return 1;
	add=0;
	j=0;
	for(i=3;i>=0;i--){
		if(s[i][j]==c) add++;
		j++;
	}
	
	if(add==4) return 1;
	
	return 0;
}

int main(){
	int t,i,j,k,tx,ty,sum;
	
	freopen("A-small-attempt1.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	gets(s[0]);
	//printf("%d\n",t);
	char c[4];
	for(k=1;k<=t;k++){
		sum=0;
		tx=-1;
		ty=-1;
		for(i=0;i<5;i++){gets(s[i]);/*puts(s[i]);*/}
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(s[i][j]=='T'){tx=i;ty=j;}
				if(s[i][j]=='.') sum++;
			}
		}
		
		printf("Case #%d: ",k);
		if(tx!=-1 && ty!=-1) s[tx][ty]='X';
		if(check('X')){puts("X won"); continue;}
		if(tx!=-1 && ty!=-1) s[tx][ty]='O';
		if(check('O')){puts("O won"); continue;}
		if(sum==0){puts("Draw");continue;}
		else puts("Game has not completed");		
	}
	return 0;
}
