#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;
int cnt[4];//X,O,T,.
char map[10][10];
bool check(int a){
	if(cnt[a]==4 || (cnt[a]==3 && cnt[2]==1))
		return true;
	return false;
}
string pro(){
	int i,j;
	for(i=0;i<4;i++){
		cnt[0]=cnt[1]=cnt[2]=cnt[3]=0;
		for(j=0;j<4;j++){
			if(map[i][j]=='X')
				cnt[0]++;
			else if(map[i][j]=='O')
				cnt[1]++;
			else if(map[i][j]=='T')
				cnt[2]++;
			else cnt[3]++;
		}
		if(check(0))
			return "X won";
		if(check(1))
			return "O won";
	}
	for(i=0;i<4;i++){
		cnt[0]=cnt[1]=cnt[2]=cnt[3]=0;
		for(j=0;j<4;j++){
			if(map[j][i]=='X')
				cnt[0]++;
			else if(map[j][i]=='O')
				cnt[1]++;
			else if(map[j][i]=='T')
				cnt[2]++;
			else cnt[3]++;
		}
		if(check(0))
			return "X won";
		if(check(1))
			return "O won";
	}
	cnt[0]=cnt[1]=cnt[2]=cnt[3]=0;
	for(i=0;i<4;i++){
			if(map[i][i]=='X')
				cnt[0]++;
			else if(map[i][i]=='O')
				cnt[1]++;
			else if(map[i][i]=='T')
				cnt[2]++;
			else cnt[3]++;
	}
		if(check(0))
			return "X won";
		if(check(1))
			return "O won";
	cnt[0]=cnt[1]=cnt[2]=cnt[3]=0;
	for(i=0;i<4;i++){
			if(map[i][3-i]=='X')
				cnt[0]++;
			else if(map[i][3-i]=='O')
				cnt[1]++;
			else if(map[i][3-i]=='T')
				cnt[2]++;
			else cnt[3]++;
	}
		if(check(0))
			return "X won";
		if(check(1))
			return "O won";
	cnt[0]=cnt[1]=cnt[2]=cnt[3]=0;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(map[j][i]=='X')
				cnt[0]++;
			else if(map[j][i]=='O')
				cnt[1]++;
			else if(map[j][i]=='T')
				cnt[2]++;
			else cnt[3]++;
		}
	}
	if(cnt[0]+cnt[1]+cnt[2]==16)
		return "Draw";
	return "Game has not completed";
}
int main(){
	int test,i,j,testt;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&testt);
	for(test=1;test<=testt;test++){
		for(i=0;i<4;i++)
			scanf("%s",map[i]);
		printf("Case #%d: %s\n",test,pro().c_str());
	}
	return 0;
}
