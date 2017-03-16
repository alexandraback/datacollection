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

int T,R,C,W,V;

int main () {
	
	scanf("%d",&T);
	
	FOE(tc,1,T) {
		
		scanf("%d%d%d",&R,&C,&W); 
		
		printf("Case #%d: ",tc);
		
		V=0;
		
		FOR(i,0,R-1) V+=C/W;
		
		int pos=0;
		
		while (pos<=C && C-pos>=2*W) {
			pos+=W;
			V++;
		}
		
		V+=min(C-pos,W+1);
		
		printf("%d\n",V);
		
	}
	
	return 0;
}

