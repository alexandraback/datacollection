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

int T,C,D,V,A[155],ANS;
bool ok[155];

int main () {
	
	scanf("%d",&T);
	
	FOE(tc,1,T) {
		
		scanf("%d%d%d",&C,&D,&V);
		
		FOR(i,0,D) scanf("%d",A+i);
		ANS=0;
		SET(ok,0);
		ok[0]=1;
		
		printf("Case #%d: ",tc);
		
		
		
		FOR(i,0,D) 
			FOD(j,V,A[i]) if (ok[j-A[i]]) ok[j]=1;
		
		FOE(i,1,V) if (!ok[i]) {
			ANS++;
			FOD(j,V,i) if (ok[j-i]) ok[j]=1;
		}
		
		printf("%d\n",ANS);
		
	}
	
	return 0;
}

