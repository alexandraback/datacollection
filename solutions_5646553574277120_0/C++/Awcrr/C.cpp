#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[105],v,c,d,ret;
bool vis[105];

int main(){
	freopen("input","r",stdin); freopen("output","w",stdout);
	int __;
	scanf("%d",&__);
	for(int Cas = 1;Cas <= __;++ Cas){
		printf("Case #%d: ",Cas);
		scanf("%d%d%d",&c,&d,&v);
		memset(vis,0,sizeof(vis));
		for(int i = 0;i < d;++ i){
			scanf("%d",&a[i]);
			if(a[i] <= v)
				vis[a[i]] = true;
		}
		for(int i = 0;i < (1 << d);++ i){
			int sum = 0;
			for(int j = 0;j < d;++ j)
			if((i >> j) & 1)
				sum += a[j];
			if(sum <= v && !vis[sum]) vis[sum] = true;
		}
		ret = 0;
		for(int i = 1;i <= v;++ i)
		if(!vis[i]){
			for(int j = v;j >= 1;-- j)
			if(vis[j] && j + i <= v)
				vis[j + i] = true;
			vis[i] = true;
			++ ret;
		}
		printf("%d\n",ret);
	}
	return 0;
}
