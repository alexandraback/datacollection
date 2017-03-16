#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int main(){
	int T,map[10][10],q[10];
	char s[20][20];
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	for (int caseT=1;caseT<=T;caseT++){
		for (int i=0;i<4;i++) scanf("%s",s[i]);
		memset(map,0,sizeof(map));
		bool com=true;
		for (int i=0;i<4;i++)
			for (int j=0;j<4;j++){
				if (s[i][j]=='.') com=false;
				if (s[i][j]=='X') map[i+1][j+1]=1;
				if (s[i][j]=='O') map[i+1][j+1]=2;
				if (s[i][j]=='T') map[i+1][j+1]=3;
			}
		bool f1=false,f2=false;
		for (int i=1;i<=4;i++){
			memset(q,0,sizeof(q));
			for (int j=1;j<=4;j++) q[map[i][j]]++;
			if (!q[0]){
				if (q[1]==4||(q[1]==3&&q[3]==1)) f1=true;
				if (q[2]==4||(q[2]==3&&q[3]==1)) f2=true;
			}
			memset(q,0,sizeof(q));
			for (int j=1;j<=4;j++) q[map[j][i]]++;
			if (!q[0]){
				if (q[1]==4||(q[1]==3&&q[3]==1)) f1=true;
				if (q[2]==4||(q[2]==3&&q[3]==1)) f2=true;
			}
		}
		memset(q,0,sizeof(q));
		for (int j=1;j<=4;j++) q[map[j][j]]++;
		if (!q[0]){
			if (q[1]==4||(q[1]==3&&q[3]==1)) f1=true;
			if (q[2]==4||(q[2]==3&&q[3]==1)) f2=true;
		}
		memset(q,0,sizeof(q));
		for (int j=1;j<=4;j++) q[map[5-j][j]]++;
		if (!q[0]){
			if (q[1]==4||(q[1]==3&&q[3]==1)) f1=true;
			if (q[2]==4||(q[2]==3&&q[3]==1)) f2=true;
		}
		printf("Case #%d: ",caseT);
		if (!com&&!f1&&!f2){
			printf("Game has not completed\n"); continue;
		}
		if (com&&!f1&&!f2){
			printf("Draw\n"); continue;
		}
		if (f1){
			printf("X won\n"); continue;
		}
		if (f2){
			printf("O won\n"); continue;
		}
	}
	return 0;
}
