#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 1005,oo = ~0U>>2;
int w,r,c,ans;

int main(){
	freopen("input","r",stdin); freopen("output","w",stdout);
	int __;
	scanf("%d",&__);
	for(int Cas = 1;Cas <= __;++ Cas){
		printf("Case #%d: ",Cas);
		scanf("%d%d%d",&r,&c,&w);
		ans = (r - 1) * (c / w);
		if(c % w == 0)
			ans += (c - 1) / w + w;
		else
			ans += c / w + w;
		printf("%d\n",ans);
	}
	return 0;
}
