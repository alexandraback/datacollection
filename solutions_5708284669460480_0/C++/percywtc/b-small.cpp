#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define FOR(i,s,e) for (int i=s;i<e;i++)
#define FOE(i,s,e) for (int i=s;i<=e;i++)
#define FOD(i,s,e) for (int i=s;i>=e;i--)
#define SET(a,e) memset(a,e,sizeof(a))
#define LL long long
#define LD long double
#define pb push_back
#define x first
#define y second

int T,K,L,S;
char key[255],tar[255],cur[255];
double MAX,cases,ANS;

bool equ(int st) {
	FOR(i,0,L) if (cur[st+i]!=tar[i]) return 0;
	return 1; 
}

double check() {
	double ret=0;
	
	FOR(i,0,S-L+1) if (equ(i)) ret+=1.0;
	
	return ret;
}

void test(int p) {
	
	if (p==S) {
		cases++;
		MAX=max(MAX,check());
		return;
	}
	
	FOR(i,0,K) {
		cur[p]=key[i];
		test(p+1);
	}
}

void find(int p) {
	
	if (p==S) {
		ANS+=(MAX-check())/cases;
		return;
	}
	
	FOR(i,0,K) {
		cur[p]=key[i];
		find(p+1);
	}
}

int main () {
	
	scanf("%d",&T);
	
	FOE(tc,1,T) {
		SET(cur,0);
		MAX=cases=ANS=0;
		
		scanf("%d%d%d",&K,&L,&S);
		scanf("%s%s",key,tar);
		
		printf("Case #%d: ",tc);
		
		test(0);
		SET(cur,0);
		
		find(0);
		
		printf("%.10f\n",ANS);
		
	}
	
	return 0;
}

