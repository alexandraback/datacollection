#include<cstdio>
#include<set>
using namespace std;
set<char> lit[30];
char S[150],D[150];
char TR[30];
int main(){
	freopen("date.in","r",stdin);
	freopen("date.out","w",stdout);
	TR[0]='y';
	TR[1]='h';
	TR[2]='e';
	TR[3]='s';
	TR[4]='o';
	TR[5]='c';
	TR[6]='v';
	TR[7]='x';
	TR[8]='d';
	TR[9]='u';
	TR[10]='i';
	TR[11]='g';
	TR[12]='l';
	TR[13]='b';
	TR[14]='k';
	TR[15]='r';
	TR[16]='z';
	TR[17]='t';
	TR[18]='n';
	TR[19]='w';
	TR[20]='j';
	TR[21]='p';
	TR[22]='f';
	TR[23]='m';
	TR[24]='a';
	TR[25]='q';
	int T;
	scanf("%d",&T);
	fgets(S,10,stdin);
	for(int i=1;i<=T;++i){
		fgets(S,1000,stdin);
		printf("Case #%d: ",i);
		for(int j=0;('a'<=S[j] && S[j]<='z') || S[j]==' ';++j){
			if(S[j]==' '){
				printf(" ");
				continue;
			}
			printf("%c",TR[S[j]-'a']);
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
