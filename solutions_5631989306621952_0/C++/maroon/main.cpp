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

const int strMax=1001;
char p[strMax],q[strMax],r[strMax],s[strMax];

void Solve(int caseNumber){
	scanf("%s",s);
	int l=strlen(s);
	REP(i,l){
		p[0]=s[i];
		REP(j,i)
			p[1+j]=r[j];
		REP(j,i)
			q[j]=r[j];
		q[i]=s[i];
		bool grt=true;
		REP(j,i+1)
			if(p[j]!=q[j]){
				grt=p[j]>q[j];
				break;
			}
		REP(j,i+1)
			r[j]=(grt?p:q)[j];
	}
	r[l]=0;
	printf("Case #%d: %s\n",caseNumber,r);
}

int main(){
	int t=read();
	REP(caseNumber,t){
		Solve(caseNumber+1);
	}
}