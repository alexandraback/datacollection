#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

char s[7][7];
int op[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

bool is(int x,int y){
	int i,j,c,k,nx,ny;
	for(i=0,j=7;i<4;i++,j--){
		c = 1;
		nx = x+op[i][0];
		ny = y+op[i][1];
		while(nx>=0 && nx<4 && ny>=0 && ny<4 && (s[nx][ny]==s[x][y] || s[nx][ny]=='T')){
			c++;
			nx += op[i][0];
			ny += op[i][1];
		}
		nx = x+op[j][0];
		ny = y+op[j][1];
		while(nx>=0 && nx<4 && ny>=0 && ny<4 && (s[nx][ny]==s[x][y] || s[nx][ny]=='T')){
			c++;
			nx += op[j][0];
			ny += op[j][1];
		}
		if(c==4)
			return true;
		if(c>4)
			while(1);
	}
	return false;
}

int main()
{
    //freopen("A-large.in","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int T,t,i,j;
	scanf(" %d",&T);
	for(t=1;t<=T;t++){
		gets(s[0]);
		for(i=0;i<4;i++)
			gets(s[i]);
		int emp = 0,win = -1;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				if(s[i][j]=='.'){
					emp++;
					continue;
				}else if(s[i][j]=='T')
					continue;
				else{
					if(is(i,j))
						win = s[i][j]=='X' ? 1 : 2;
				}
			}
		}
		if(win==-1){
			if(emp==0)	printf("Case #%d: Draw\n",t);
			else	printf("Case #%d: Game has not completed\n",t);
		}else{
			if(win==1)	printf("Case #%d: X won\n",t);
			else	printf("Case #%d: O won\n",t);
		}
	}
    
    return 0;
}