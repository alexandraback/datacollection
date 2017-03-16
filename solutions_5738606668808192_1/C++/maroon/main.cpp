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
	int n=read();
	int j=read();
	printf("Case #%d:\n",caseNumber);
	REP(i,j){
		printf("1");
		for(int k=(n-2)/2-1;k>=0;k--){
			int s=(i>>k)&1;
			printf("%d%d",s,s);
		}
		printf("1 3 4 5 6 7 8 9 10 11\n");
	}
}

int main(){
	int t=read();
	REP(caseNumber,t){
		Solve(caseNumber+1);
	}
}