#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

bool submit=true;

int n;
char s[5][4];
int kx,ko,kt;
bool full,ans;
void det(int j,int k){
	if(s[j][k]=='O')ko++;
	if(s[j][k]=='X')kx++;
	if(s[j][k]=='T')kt++;
	if(s[j][k]=='.')full=false;
}
void put(int oo,int xx,int tt){
	if(oo==4 || (oo==3 && tt==1)){
		printf("O won\n");
		ans=true;
	}
	if(xx==4 || (xx==3 && tt==1)){
		printf("X won\n");
		ans=true;
	}
}
	
int main(){
	if(submit){
		freopen("A-small-attempt2.in.txt","r",stdin);
		freopen("A-small-attempt2.txt","w",stdout);
	}
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++){
		for(int j=0;j<5;j++) gets(s[j]);
		printf("Case #%d: ",i);
		full=true;
		ans=false;
		//hor
		for(int j=0;j<4;j++){
			if(ans) goto gg;
			kx=ko=kt=0;
			for(int k=0;k<4;k++) det(j,k);
			put(ko,kx,kt);
		}
		//ver
		for(int j=0;j<4;j++){
			if(ans) goto gg;
			kx=ko=kt=0;
			for(int k=0;k<4;k++) det(k,j);
			put(ko,kx,kt);
		}
		//dia
		if(ans) goto gg;
		kx=ko=kt=0;
		for(int j=0;j<4;j++) det(j,j);
		put(ko,kx,kt);
		//dia
		if(ans) goto gg;
		kx=ko=kt=0;
		for(int j=0;j<4;j++) det(j,3-j);
		put(ko,kx,kt);
		if(ans) goto gg;
		//put_ans
		if(!full) printf("Game has not completed\n");
		else printf("Draw\n");
		gg:;
	}
	return 0;
}
