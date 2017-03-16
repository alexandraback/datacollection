#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <string>
#define INF 2000000000
#define ii pair<int, int>

using namespace std;

int main() {
	int ntc,n,s,p,minp,x,cand,cands;
	scanf("%d",&ntc);
	for (int tc=1;tc<=ntc;tc++) {
		scanf("%d %d %d",&n,&s,&p);
		p=p*3;
		cand=0,cands=0;
		for (int i=0;i<n;i++) {
			scanf("%d",&x);
			if (x>=p-2) {
				cand++;
			} else if (x==p-3 && p-3>0) {
				cands++;	
			} else if (x==p-4 && p-4>0) {
				cands++;
			}
		}
		printf("Case #%d: %d\n",tc,cand+min(cands,s));	
	}
    return 0;
}
