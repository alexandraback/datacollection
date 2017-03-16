#include <cstdio>
int main (){
	bool YN,YN_2,b;
	char s[4][4];
	int T,filled=0,i,j,k;
	scanf("%d\n",&T);
	for (i=1;i<=T;i++){
		YN=0;
		YN_2=0;
		filled=0;
		for (j=0;j<4;j++){
			for (k=0;k<4;k++){
				scanf("%c",&s[j][k]);
				if (s[j][k]!='.') filled++;
			}
			scanf("\n");
		}
		scanf("\n");
		for (j=0;j<4;j++){
			b=1;
			for (k=0;k<4;k++){
				if (s[j][k]!='O' && s[j][k]!='T'){
					b=0;
				}
			}
			if (b==1) YN=1;
			b=1;
			for (k=0;k<4;k++){
				if (s[k][j]!='O' && s[k][j]!='T'){
					b=0;
				}
			}
			if (b==1) YN=1;
		}
		b=1;
		for (j=0;j<4;j++){
			if (s[j][j]!='O' && s[j][j]!='T'){
				b=0;
			}
		}
		if (b==1) YN=1;
		b=1;
		for (j=0;j<4;j++){
			if (s[j][3-j]!='O' && s[j][3-j]!='T'){
				b=0;
			}
		}
		if (b==1) YN=1;
		for (j=0;j<4;j++){
			b=1;
			for (k=0;k<4;k++){
				if (s[j][k]!='X' && s[j][k]!='T'){
					b=0;
				}
			}
			if (b==1) YN_2=1;
			b=1;
			for (k=0;k<4;k++){
				if (s[k][j]!='X' && s[k][j]!='T'){
					b=0;
				}
			}
			if (b==1) YN_2=1;
		}
		b=1;
		for (j=0;j<4;j++){
			if (s[j][j]!='X' && s[j][j]!='T'){
				b=0;
			}
		}
		if (b==1) YN_2=1;
		b=1;
		for (j=0;j<4;j++){
			if (s[j][3-j]!='X' && s[j][3-j]!='T'){
				b=0;
			}
		}
		if (b==1) YN_2=1;
		if (YN==1){
			printf("Case #%d: O won\n",i);
		} else if (YN_2==1){
			printf("Case #%d: X won\n",i);
		} else if (filled!=16){
			printf("Case #%d: Game has not completed\n",i);
		} else {
			printf("Case #%d: Draw\n",i);
		}
	}
	return 0;
}
