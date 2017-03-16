#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#define FOR(i,n) for(int i=0;i<n;++i)

#include <unordered_set>

using namespace std;



int main(void) {
	int t;
	scanf("%d",&t);
	FOR(k,t) {
		int r,c,w;
		scanf("%d%d%d",&r,&c,&w);
		int ans = 0;
		if(w==c) {
			ans = r+c-1;
		}
		else {
			ans = r*(c/w); // miss
			ans+=w-1+(c%w==0?0:1);
		}
		printf("Case #%d: %d\n",k+1,ans);
	}
}