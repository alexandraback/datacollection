#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TC, T;
int topics;
char topicName[1010][2][30];
int topicCoor[1010][2];
int topicUsed[1010];
char nameIndex[2][1010][30];
int i, x, y, c, nI0, nI1, ans;

int Max(int a, int b){
	if (a>b) return a;
	return b;
}

void DFS(int level, int tmpAns){
	if (topics-level+tmpAns<=ans) return ;
	if (level==topics){
		if (tmpAns>ans) ans = tmpAns;
		return ;
	}
	
	int i;
	for (i=0; i<topics; i++) if (!topicUsed[i]){
		int tmpV0 = 0;
		int tmpV1 = 0;
		for (x=0; x<topics; x++) if (i!=x) if (topicUsed[x]){
			if (topicCoor[i][0]==topicCoor[x][0]) tmpV0 = 1;
			if (topicCoor[i][1]==topicCoor[x][1]) tmpV1 = 1;
		}
		
		if (tmpV0&&tmpV1){
			topicUsed[i] = 1;
			DFS(level+1, tmpAns+1);
			return ;
		}
		
		topicUsed[i] = 1;
		DFS(level+1, tmpAns);
		topicUsed[i] = 0;
	}
	return ;
}

int main(){
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("C-small-attempt2.out", "w", stdout);
	
	scanf("%d", &TC);
	for (T=1; T<=TC; T++){
		printf("Case #%d: ", T);
		scanf("%d", &topics);
		nI0 = 0;
		nI1 = 0;
		
		for (i=0; i<topics; i++){
			scanf("%s%s", topicName[i][0], topicName[i][1]);
			for (x=0; x<nI0; x++) if (!strcmp(topicName[i][0], nameIndex[0][x])) break;
			topicCoor[i][0] = x;
			if (x==nI0){
				strcpy(nameIndex[0][nI0], topicName[i][0]);
				nI0++;
			}
			for (x=0; x<nI1; x++) if (!strcmp(topicName[i][1], nameIndex[1][x])) break;
			topicCoor[i][1] = x;
			if (x==nI1){
				strcpy(nameIndex[1][nI1], topicName[i][1]);
				nI1++;
			}
		}
		
		ans = topics - Max(nI0, nI1);
		DFS(0, 0);
		printf("%d\n", ans);
		
	}
	
	
	return 0;
}
/*
3 3 HYDROCARBON COMBUSTION QUAIL BEHAVIOR QUAIL COMBUSTION 3 CODE JAM SPACE JAM PEARL JAM 2 INTERGALACTIC PLANETARY PLANETARY INTERGALACTIC
*/

