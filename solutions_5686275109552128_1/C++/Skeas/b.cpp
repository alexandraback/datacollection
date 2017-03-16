#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

int D,P[1005];
priority_queue<int> q;

int main() {
	int T,cs; scanf("%d",&T);
	for(cs=1;cs<=T;++cs) {
		printf("Case #%d: ",cs);
		scanf("%d",&D);
		for(int i=0;i<D;++i) scanf("%d",P+i);

		int ans = 1<<30;
		for(int c=1;c<=1000;++c) {
			int tmp = c;
			for(int i=0;i<D;++i) if(P[i] > c) {
				tmp += (P[i]-c + c-1) / c;
			} ans = min(ans, tmp);
		} printf("%d\n",ans);
	}
}
