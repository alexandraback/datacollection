#include "iostream"
#include "cstring"
#include "cstdio"
using namespace std;
char s[10][10];
bool check(char ch)
{
	for(int i=0;i<4;i++){
		if(s[i][0]==ch||s[i][0]=='T'){
			bool tmp=0;
			for(int j=1;j<4;j++){
				if(s[i][j]!=ch&&s[i][j]!='T'){
					tmp=1;
					break;
				}
			}
			if(!tmp) return true;
		}
		if(s[0][i]==ch||s[0][i]=='T'){
			bool tmp=0;
			for(int j=1;j<4;j++){
				if(s[j][i]!=ch&&s[j][i]!='T'){
					tmp=1;
					break;
				}
			}
			if(!tmp) return true;
		}
	}
	if(s[0][0]==ch||s[0][0]=='T'){
		bool tmp=0;
		for(int j=1;j<4;j++){
			if(s[j][j]!=ch&&s[j][j]!='T'){
				tmp=1;
				break;
			}
		}
		if(!tmp) return true;
	}
	if(s[0][3]==ch||s[0][3]=='T'){
		bool tmp=0;
		for(int j=1;j<4;j++){
			if(s[j][3-j]!=ch&&s[j][3-j]!='T'){
				tmp=1;
				break;
			}
		}
		if(!tmp) return true;
	}
	return false;
}
int main(void)
{
	freopen("A-small-attempt0.in","r",stdin);
	int T,g=0;
	scanf("%d",&T);
	while(T--){
		int sum=0;
		for(int i=0;i<4;i++){
			scanf("%s",s[i]);
		}
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(s[i][j]=='.'){
					sum++;
				}
			}
		}
		printf("Case #%d: ",++g);
		if(check('X')){
			printf("X won\n");
		}else if(check('O')){
			printf("O won\n");
		}else if(sum==0){
			printf("Draw\n");
		}else{
			printf("Game has not completed\n");
		}

	}
	return 0;
}