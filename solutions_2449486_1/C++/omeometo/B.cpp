#include <stdio.h>
#include <algorithm>
using namespace std;
main(){
	int testcase;
	scanf("%d ",&testcase);
	for(int casenum=1;casenum<=testcase;casenum++){
		printf("Case #%d: ",casenum);
		int board[101][101];
		int isiz,jsiz;
		scanf("%d%d",&isiz,&jsiz);
		for(int i=0;i<isiz;i++)for(int j=0;j<jsiz;j++)scanf("%d",&board[i][j]);
		bool ok=true;
		for(int i=0;i<isiz;i++)for(int j=0;j<jsiz;j++)for(int k=0;k<isiz;k++)for(int l=0;l<jsiz;l++)if(min(board[i][j],board[k][l])!=min(board[i][l],board[k][j]))ok=false;
		puts(ok?"YES":"NO");
	}
}