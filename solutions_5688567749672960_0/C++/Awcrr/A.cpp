#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000005;
int tm[MAXN],x,T,rev,digit[30];

int reverse(int x){
	int tot = 0;
	while(x){
		digit[tot ++] = x % 10;
		x /= 10;
	}
	for(int i = 0;i < tot;++ i)
		x = x * 10 + digit[i];
	return x;
}

int main(){
	//
	freopen("inputa","r",stdin); freopen("out","w",stdout);
	//
	memset(tm,-1,sizeof(tm));
	tm[1] = 1;
	for(int i = 1;i <= 1000000;++ i){
		rev = reverse(i);
		if(tm[rev] == -1 || tm[rev] > tm[i] + 1)
			tm[rev] = tm[i] + 1;
		if(tm[i + 1] == -1 || tm[i + 1] > tm[i] + 1) tm[i + 1] = tm[i] + 1;
	}
	scanf("%d",&T);
	for(int Cas = 1;Cas <= T;++ Cas){
		printf("Case #%d: ",Cas);
		scanf("%d",&x);
		printf("%d\n",tm[x]);
	}
	return 0;
}
