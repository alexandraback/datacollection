#include<stdio.h>
char p[10][10];
void sol(int uuu){
	printf("Case #%d: ",uuu);
	for(int i=0;i<4;i++)
		scanf("%s",p[i]);
	int end=1;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(p[i][j]=='.')
				end=0;
	for(int i=0;i<4;i++){
		int flag=p[i][0]=='T'?p[i][1]:p[i][0];
		for(int j=0;j<4;j++){
			if(p[i][j]!=flag&&p[i][j]!='T'){
				flag=0;
				break;
				}
			}
		if(flag=='O'){
			puts("O won");
			return;
			}
		else if(flag=='X'){
			puts("X won");
			return;
			}
		}
	for(int j=0;j<4;j++){
		int flag=p[0][j]=='T'?p[1][j]:p[0][j];
		for(int i=0;i<4;i++){
			if(p[i][j]!=flag&&p[i][j]!='T'){
				flag=0;
				break;
				}
			}
		if(flag=='O'){
			puts("O won");
			return;
			}
		else if(flag=='X'){
			puts("X won");
			return;
			}
		}
	int flag=p[0][0]=='T'?p[1][1]:p[0][0];
	for(int i=0;i<4;i++){
		if(p[i][i]!=flag&&p[i][i]!='T'){
			flag=0;
			break;
			}
		}
	if(flag=='O'){
		puts("O won");
		return;
		}
	else if(flag=='X'){
		puts("X won");
		return;
		}
	flag=p[0][3]=='T'?p[1][2]:p[0][3];
	for(int i=0;i<4;i++){
		if(p[i][3-i]!=flag&&p[i][3-i]!='T'){
			flag=0;
			break;
			}
		}
	if(flag=='O'){
		puts("O won");
		return;
		}
	else if(flag=='X'){
		puts("X won");
		return;
		}
	if(end)
		puts("Draw");
	else
		puts("Game has not completed");
	}
int main(){
	freopen("A-large.in","r",stdin);
	freopen("PA.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int ti=0;ti<t;ti++)
		sol(ti+1);
	return 0;
	}
