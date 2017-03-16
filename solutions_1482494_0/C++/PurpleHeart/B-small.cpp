#include <cstdio>
#include <utility>
#include <cstring>
#define MAXN 1005

using namespace std;

int cases, n, mark[MAXN];
pair<int,int> p[MAXN];

int main(){
	scanf("%d",&cases);
	for(int xx = 1; xx <= cases; ++xx){
		scanf("%d",&n);
		for(int i = 0; i < n; ++i)
			scanf("%d%d",&p[i].first,&p[i].second);
		int x = 0, ans = 0;
		memset(mark,0,sizeof(mark));
		while(x != n*2){
			//find 0 -> 2
			bool ok = false;
			for(int i = 0; i < n; ++i)
				if(mark[i] == 0 && p[i].second <= x){
					mark[i] = 2;
					x += 2;
					ans++;
					ok = true;
				}
			//find 1 -> 2
			if(!ok){
				for(int i = 0; i < n; ++i)
					if(mark[i] == 1 && p[i].second <= x){
						mark[i] = 2;
						x++;
						ans++;
						ok = true;
					}
			}
			//find 0 -> 1
			if(!ok){
				int best = -1, best_i = -1;
				for(int i = 0; i < n; ++i)
					if(mark[i] == 0 && p[i].first <= x && p[i].second >= best){
						best = p[i].second;
						best_i = i;
					}
				if(best_i != -1){
					mark[best_i] = 1;
					x++;
					ans++;
					ok = true;
				}
			}

			if(!ok)break;
		}
		if(x==n*2)printf("Case #%d: %d\n",xx,ans);
		else printf("Case #%d: Too Bad\n",xx);
	}
}
