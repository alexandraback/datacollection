#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back

using namespace std;

using ll = long long;

int read(){
	int i;
	scanf("%d",&i);
	return i;
}

void Solve(int caseNumber){
	int k=read(),c=read(),s=read();
	if(k==1){
			printf("Case #%d: 1\n",caseNumber);
	}else if(c==1){
		if(s<k){
			printf("Case #%d: IMPOSSIBLE\n",caseNumber);
		}else{
			printf("Case #%d: ",caseNumber);
			REP(i,k)
				printf(i<k-1?"%d ":"%d\n",i+1);
		}
	}else{
		if(s<k-1){
			printf("Case #%d: IMPOSSIBLE\n",caseNumber);
		}else{
			printf("Case #%d: ",caseNumber);
			FOR(i,1,k)
				printf(i<k-1?"%d ":"%d\n",i+1);
		}
	}
}

int main(){
	int t=read();
	REP(caseNumber,t){
		Solve(caseNumber+1);
	}
}