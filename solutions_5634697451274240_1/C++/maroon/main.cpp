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

char str[128];

void Solve(int caseNumber){
	scanf("%s",str);
	int ans=1;
	int n=strlen(str);
	FOR(i,1,n)
		if(str[i]!=str[i-1])
			ans++;
	if(str[n-1]=='+')
		ans--;
	printf("Case #%d: %d\n",caseNumber,ans);
}

int main(){
	int t=read();
	REP(caseNumber,t){
		Solve(caseNumber+1);
	}
}