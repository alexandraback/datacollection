#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int N;
int K[300], TK[300];
int CK[300][300], CKn[300];
int T[300];
set<int> canOpen[300];
bool canTrans[300][300];
bool opened[300];

set<int> visited;

bool moveOn(int* r, int curr){
	if(curr==N) return true;
	for(int i=1;i<=N;i++) if(!opened[i] && TK[T[i]]<1) return false;
	int state=0;
	for(int i=1;i<=N;i++) if(opened[i]) state+=1<<(i-1);
	if(visited.find(state)!=visited.end()) return false;
	visited.insert(state);
	for(int i=1;i<=N;i++){
		if(!opened[i] && K[T[i]]>0){
			opened[i]=true;
			K[T[i]]--;TK[T[i]]--;
			for(int j=0;j<CKn[i];j++) K[CK[i][j]]++;
			r[curr]=i;
			if(moveOn(r,curr+1)) return true;
			for(int j=0;j<CKn[i];j++) K[CK[i][j]]--;
			K[T[i]]++;TK[T[i]]++;
			opened[i]=false;
		}
	}
	return false;
}

void solveCase(int ct){
	visited.clear();
	memset(K,0,sizeof(K));memset(TK,0,sizeof(TK));
	memset(CK,0,sizeof(CK));
	memset(canTrans,0,sizeof(canTrans));
	memset(opened,0,sizeof(opened));
	for(int i=0;i<300;i++) canOpen[i].clear();
	int KN;
	scanf("%d%d",&KN,&N);
	while(KN--){
		int x;scanf("%d",&x);K[x]++;TK[x]++;
	}
	for(int i=1;i<=N;i++){
		scanf("%d%d",&T[i],&CKn[i]);
		canOpen[T[i]].insert(i);
		for(int j=0;j<CKn[i];j++){
			scanf("%d",&CK[i][j]);
			TK[CK[i][j]]++;
		}
	}
	int res[300];
	memset(res,0,sizeof(res));
	bool r=moveOn(res,0);
	printf("Case #%d: ",ct);
	if(r){
		for(int i=0;i<N;i++) printf("%d ",res[i]);
		printf("\n");
	}else{
		printf("IMPOSSIBLE\n");
	}
 }


int main(int argc, char *argv[]) {
	freopen("D-small-attempt2.in","r",stdin);
	freopen("D-small-attempt2.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		solveCase(t);
	}
}