#include <cstdio>

char map[20][20];

bool ck(char c){
	int i,j;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++)
			if(map[i][j]!=c&&map[i][j]!='T')
				break;
		if(j==4)return true;
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++)
			if(map[j][i]!=c&&map[j][i]!='T')
				break;
		if(j==4)return true;
	}
	for(i=0;i<4;i++)
		if(map[i][i]!=c&&map[i][i]!='T')
			break;
	if(i==4)return true;
	for(i=0;i<4;i++)
		if(map[i][3-i]!=c&&map[i][3-i]!='T')
			break;
	if(i==4)return true;
	return false;
}

int main(){
	int t,c,i,j,k;
	scanf("%d",&t);
	for(c=1;c<=t;c++){
		for(i=0;i<4;i++)
			scanf("%s",map[i]);
		printf("Case #%d: ",c);
		if(ck('O')){
			puts("O won");
		}else if(ck('X')){
			puts("X won");
		}else{
			bool draw = true;
			for(i=0;i<4;i++)
				for(j=0;j<4;j++)
					if(map[i][j]=='.')
						draw = false;
			if(draw){
				puts("Draw");
			}else{
				puts("Game has not completed");
			}
		}
	}
	return 0;
}
