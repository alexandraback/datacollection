#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define int64 long long
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
int i,j,k,n,m,te,test,K,an;
int main() {
	freopen("new.in","r",stdin);
	freopen("new.out","w",stdout);
	scanf("%d",&test);
	For(te,1,test) {
		printf("Case #%d: ",te);
		scanf("%d%d%d",&n,&m,&K);
		n--; m--; K--;
		if (n<m) swap(n,m);
		K=min(K,m);
		an=0;
		For(i,0,n)For(j,0,m) if ((i&j)<=K) an++;
		printf("%d\n",an);
	}
	return 0;
}
