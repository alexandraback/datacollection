#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
//#define LOCAL
const int N = 1200;
struct edge
{
	int t,next;
}e[N<<1];
int head[N],cnt;
int next_point[N];

inline void add(int s,int t){

}
void init(){
	memset(head,-1,sizeof(head));
	memset()
}
int main(){
	#ifdef LOCAL
	freopen("C-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T;
	for(int times=1;times<=T;times++){
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;i++) {
			int x;
			scanf("%d",&x);
			next_point[i]=x;
			add(x,i);
		}
		ans = 0;
		for(int i=1;i<=n;i++) dfs(i,1);
		printf("Case #%d: %d\n",times,ans);
	}
	return 0;
}