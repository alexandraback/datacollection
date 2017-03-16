#include<cstdio>
#include<cstring>
using namespace std;
char a[6][6];
int TT,T,i,j;
bool f1,f2;
int main(){
//	freopen("A-large.in","r",stdin);
//	freopen("A-large.out","w",stdout);
	scanf("%d\n",&TT);
for(T=1;T<=TT;T++){
	printf("Case #%d: ",T);
	memset(a,0,sizeof(a));
	for(i=1;i<=4;i++)scanf("%s",a[i]+1);
	for(i=1;i<=4;i++){
		f1=1;f2=1;
		for(j=1;j<=4;j++){
			if(a[i][j]=='O')f1=0;
			if(a[i][j]=='X')f2=0;
			if(a[i][j]=='.')f1=f2=0;
		}
		if(f1||f2)break;
	}
	if(f1){
		printf("X won\n");
		continue;
	}
	if(f2){
		printf("O won\n");
		continue;
	}
	for(j=1;j<=4;j++){
		f1=1;f2=1;
		for(i=1;i<=4;i++){
			if(a[i][j]=='O')f1=0;
			if(a[i][j]=='X')f2=0;
			if(a[i][j]=='.')f1=f2=0;
		}
		if(f1||f2)break;
	}
	if(f1){
		printf("X won\n");
		continue;
	}
	if(f2){
		printf("O won\n");
		continue;
	}
	f1=f2=1;
	for(i=1;i<=4;i++){
		if(a[i][i]=='O')f1=0;
		if(a[i][i]=='X')f2=0;
		if(a[i][i]=='.')f1=f2=0;
	}
	if(f1){
		printf("X won\n");
		continue;
	}
	if(f2){
		printf("O won\n");
		continue;
	}
	f1=f2=1;
	for(i=1;i<=4;i++){
		if(a[i][4-i+1]=='O')f1=0;
		if(a[i][4-i+1]=='X')f2=0;
		if(a[i][4-i+1]=='.')f1=f2=0;
	}
	if(f1){
		printf("X won\n");
		continue;
	}
	if(f2){
		printf("O won\n");
		continue;
	}
	f1=0;
	for(i=1;i<=4;i++)for(j=1;j<=4;j++)
		if(a[i][j]=='.')f1=1;
	if(f1){
		printf("Game has not completed\n");
		continue;
	}else printf("Draw\n");
}
}