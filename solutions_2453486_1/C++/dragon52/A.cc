#include<cstdio>
#include<iostream>
#include<ctype.h>
#define FOR(i,n) for(int i = 0 ; i < n ; i++)

using namespace std;

char grid[4][4];

int main(){
	int t;
	bool won;
	char c;
	int val=0;
	scanf("%d",&t);
	FOR(cs,t){		
		FOR(i,4)
			FOR(j,4){
				while(isspace(c=getchar()));
				grid[i][j] = c;
			}
		/*FOR(i,4){
			FOR(j,4){
				printf("%c",grid[i][j]);
			}
			printf("\n");
		}*/

		val = 0;
		FOR(i,4){
		    won = true;
			FOR(j,4) if(grid[i][j]=='.' or grid[i][j]=='O') won = false;
			if(won) {val = 2; goto found;}
		}
		FOR(i,4){
		    won = true;
			FOR(j,4) if(grid[j][i]=='.' or grid[j][i]=='O') won = false;
			if(won) {val = 2; goto found;}
		}
		// diagonals
		won = true;
		FOR(i,4){
			if(grid[i][i]=='.' or grid[i][i]=='O') won= false;			
		}
		if(won) {val = 2; goto found;}
		
		won = true;
		FOR(i,4){
			if(grid[3-i][i]=='.' or grid[3-i][i]=='O') won= false;			
		}
		if(won) {val = 2; goto found;}
		// check for O
		FOR(i,4){
		    won = true;
			FOR(j,4) if(grid[i][j]=='.' or grid[i][j]=='X') won = false;
			if(won) {val = 3; goto found;}
		}
		FOR(i,4){
		    won = true;
			FOR(j,4) if(grid[j][i]=='.' or grid[j][i]=='X') won = false;
			if(won) {val = 3; goto found;}
		}
		
		won = true;
		FOR(i,4){
			if(grid[i][i]=='.' or grid[i][i]=='X') won= false;			
		}
		if(won) {val = 3; goto found;}
		won = true;
		FOR(i,4){
			if(grid[3-i][i]=='.' or grid[3-i][i]=='X') won= false;			
		}
		if(won) {val = 3; goto found;}
		// incomplete
		FOR(i,4)
			FOR(j,4){
				if(grid[i][j]=='.'){ val = 1 ; goto found;}
			}

		found:
			if(val==1){
				printf("Case #%d: Game has not completed\n",cs+1);
			}
			else if(val==2)
				printf("Case #%d: X won\n",cs+1);
			else if(val==3)
				printf("Case #%d: O won\n",cs+1);
			else
				printf("Case #%d: Draw\n",cs+1);
		}
		return 0;
}