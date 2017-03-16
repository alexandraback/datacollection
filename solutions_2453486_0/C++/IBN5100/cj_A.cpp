#include<cstdio>
#include<cstring>
char grid[4][5];
bool check(char a){
	bool find=false;
	for(int i=0;i<4;i++){
		int num=0;
		for(int j=0;j<4;j++){
			if(grid[i][j]==a||grid[i][j]=='T')num++;
		}
		if(num==4)find=true;
	}
	for(int j=0;j<4;j++){
		int num=0;
		for(int i=0;i<4;i++){
			if(grid[i][j]==a||grid[i][j]=='T')num++;
		}
		if(num==4)find=true;
	}
	int num=0;
	for(int i=0;i<4;i++){
		if(grid[i][i]==a||grid[i][i]=='T')num++;
	}
	if(num==4)find=true;
	num=0;
	for(int i=0;i<4;i++){
		if(grid[i][3-i]==a||grid[i][3-i]=='T')num++;
	}
	if(num==4)find=true;
	return find;
}
int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("data.out","w",stdout);
	int T,ct=1;
	scanf("%d",&T);
	while(T--){
		printf("Case #%d: ",ct++);
		for(int i=0;i<4;i++)scanf("%s",grid[i]);
		if(check('X'))printf("X won\n");
		else if(check('O'))printf("O won\n");
		else {
			int sum=0;
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
					if(grid[i][j]!='.')sum++;
				}
			}
			if(sum==16)printf("Draw\n");
			else printf("Game has not completed\n");
		}
	}
}
