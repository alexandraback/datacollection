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

int c[2500];
int n;

void Input(){
	memset(c,0,sizeof(c));
	n=read();
	REP(i,n*(n*2-1))
		c[read()-1]++;
}

int ans[50];

void Solve(){
	int k=0;
	REP(i,2500)
		if(c[i]%2)
			ans[k++]=i+1;
	REP(i,n)
		printf(i<n-1?"%d ":"%d\n",ans[i]);
}

int main(){
	int t=read();
	REP(caseNumber,t){
		Input();
		printf("Case #%d: ",caseNumber+1);
		Solve();
	}
}