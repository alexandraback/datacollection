#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,cas=0,flag,cnt[3],ans;
char g[5][5];
inline int search(){
	flag=0;
	for(int i=0;i<4;++i){
		cnt[0]=cnt[1]=cnt[2]=0;
		for(int j=0;j<4;++j){
			if(g[i][j]=='X') cnt[1]++;
			else if(g[i][j]=='O') cnt[2]++;
			else if(g[i][j]=='T') cnt[0]++;
			else flag=1;
		}
		if(cnt[0]+cnt[1]==4) return 1;
		if(cnt[0]+cnt[2]==4) return 2;
	}
	for(int i=0;i<4;++i){
		cnt[0]=cnt[1]=cnt[2]=0;
		for(int j=0;j<4;++j){
			if(g[j][i]=='X') cnt[1]++;
			else if(g[j][i]=='O') cnt[2]++;
			else if(g[j][i]=='T') cnt[0]++;
			else flag=1;
		}
		if(cnt[0]+cnt[1]==4) return 1;
		if(cnt[0]+cnt[2]==4) return 2;
	}
	cnt[0]=cnt[1]=cnt[2]=0;
	for(int i=0;i<4;++i){
		if(g[i][i]=='X') cnt[1]++;
		else if(g[i][i]=='O') cnt[2]++;
		else if(g[i][i]=='T') cnt[0]++;
		else flag=1;
	}
	if(cnt[0]+cnt[1]==4) return 1;
	if(cnt[0]+cnt[2]==4) return 2;
	cnt[0]=cnt[1]=cnt[2]=0;
	for(int i=0;i<4;++i){
		if(g[3-i][i]=='X') cnt[1]++;
		else if(g[3-i][i]=='O') cnt[2]++;
		else if(g[3-i][i]=='T') cnt[0]++;
		else flag=1;
	}
	if(cnt[0]+cnt[1]==4) return 1;
	if(cnt[0]+cnt[2]==4) return 2;
	if(!flag) return 3;
	return 4;
}
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		printf("Case #%d: ",++cas);
		for(int i=0;i<4;++i) scanf("%s",g[i]);
		ans=search();
		if(ans==1) printf("X won\n");
		else if(ans==2) printf("O won\n");
		else if(ans==3) printf("Draw\n");
		else printf("Game has not completed\n");
	}
	return 0;
}
