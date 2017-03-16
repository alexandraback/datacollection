#include <iostream>
using namespace std;
char tab[5][5];
int check(){
	int ans = 0;
	int col[4]={0},row[4]={0},x = 0,y=0;
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(tab[i][j] == '.'){
				ans=-1;
				row[i] = -20;
				col[j] = -20;
				if(i == j)x = -20;
				if(i+j == 3)y = -20;
			}
			else if(tab[i][j] == 'X'){
				row[i] += 1;
				col[j] += 1;
				if(i == j)x += 1;
				if(i+j == 3)y += 1;
			}
			else if(tab[i][j] == 'O'){
				row[i] += 50;
				col[j] += 50;
				if(i == j)x += 50;
				if(i+j == 3)y += 50;
			}
		}
		for(i=0;i<4;i++){
			if(row[i] == 4 || row[i] == 3)return 1;
			if(row[i] == 150 || row[i] == 200)return 2;
			if(col[i] == 4 || col[i] == 3)return 1;
			if(col[i] == 150 || col[i] == 200)return 2;
		}
		if(x == 4 || x == 3)return 1;
		if(x == 150 || x == 200)return 2;
		if(y == 4 || y == 3)return 1;
		if(y == 150 || y == 200)return 2;
		return ans;
}
int main(){
	//freopen("A-small-practice.in","r",stdin);
	//freopen("A-small-practice.out","w",stdout);
	int t,nt,i,j;
	scanf("%d",&t);
	for(nt = 1;nt <= t;nt ++)
	{
		for(i=0;i<4;i++)
			scanf("%s",tab[i]);
		printf("Case #%d: ",nt);
		switch(check())
		{
		case 0: printf("Draw");break;
		case 1: printf("X won");break;
		case 2: printf("O won");break;
		default:printf("Game has not completed");break;
		}
		printf("\n");
	}
	return 0;
}