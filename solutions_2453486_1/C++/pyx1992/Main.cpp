#include<stdio.h>
char grid[4][4];
char won(){
	for(int i=0;i<4;i++){
		char c=grid[i][0];
		if(c=='.')
			continue;
		char cur;
		int cnt=0;
		for(int j=1;j<4;j++){
			cur=grid[i][j];
			if(cur=='.')
				break;
			else if(cur=='X'){
				if(c=='T')
					c=cur;
				else if(c=='O')
					break;
				cnt++;
			}else if(cur=='O'){
				if(c=='T')
					c=cur;
				else if(c=='X')
					break;
				cnt++;
			}else{
				cnt++;
			}
		}
		if(cnt==3){
			return c;
		}
	}
	for(int i=0;i<4;i++){
		char c=grid[0][i];
		if(c=='.')
			continue;
		char cur;
		int cnt=0;
		for(int j=1;j<4;j++){
			cur=grid[j][i];
			if(cur=='.')
				break;
			else if(cur=='X'){
				if(c=='T')
					c=cur;
				else if(c=='O')
					break;
				cnt++;
			}else if(cur=='O'){
				if(c=='T')
					c=cur;
				else if(c=='X')
					break;
				cnt++;
			}else{
				cnt++;
			}
		}
		if(cnt==3){
			return c;
		}
	}
	char c=grid[0][0];
	int cnt=0;
	for(int i=1;i<4;i++){
		if(grid[i][i]=='.')
			break;
		else if(grid[i][i]=='X'){
			if(c=='T'){
				c=grid[i][i];
				cnt++;
			}else if(c=='.'||c=='O')
				break;
			else
				cnt++;
		}else if(grid[i][i]=='O'){
			if(c=='T'){
				c=grid[i][i];
				cnt++;
			}else if(c=='.'||c=='X')
				break;
			else
				cnt++;
		}else{
			cnt++;
		}
	}
	if(cnt==3)
		return c;
	c=grid[0][3];
	cnt=0;
	for(int i=1;i<4;i++){
		if(grid[i][3-i]=='.')
			break;
		else if(grid[i][3-i]=='X'){
			if(c=='T'){
				c=grid[i][3-i];
				cnt++;
			}else if(c=='.'||c=='O')
				break;
			else
				cnt++;
		}else if(grid[i][3-i]=='O'){
			if(c=='T'){
				c=grid[i][3-i];
				cnt++;
			}else if(c=='.'||c=='X')
				break;
			else
				cnt++;
		}else{
			cnt++;
		}
	}
	if(cnt==3)
		return c;
	return '.';
}
int main(){
	int tc;
	scanf("%d",&tc);
	for(int t=0;t<tc;t++){
		printf("Case #%d: ",t+1);
		getchar();
		int cnt=0;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				scanf("%c",&grid[i][j]);
				if(grid[i][j]=='.')
					cnt++;
			}
			getchar();
		}
		char ans=won();
		if(ans=='.'){
			if(cnt==0)
				printf("Draw\n");
			else
				printf("Game has not completed\n");
		}else{
			printf("%c won\n",ans);
		}
	}
}
