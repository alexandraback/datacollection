// (C) doctor
#include<vector>
#include<cstdio>
using namespace std;
int main(){
	//freopen("C.in","r",stdin);
	int T;scanf("%d",&T);
	for(int tc=1;tc<=T;tc++){
		int C,D,W; scanf("%d%d%d",&C,&D,&W);
		int added=0;
		long long mx=0;
		for(int i=0;i<D;i++){
			//printf("before i=%d: mx=%lld\n",i,mx);
			int v; scanf("%d",&v);
			if(mx>=W)continue;
			while (v>mx+1){
				// add mx+1.
				//printf("after adding %lld: mx=%lld\n",mx+1,mx+(long long)C*(mx+1));
				mx+=(long long)C*(mx+1);
				added++;
			}
			mx+=(long long)C*v;
		}
		while(mx<W)mx+=(long long)C*(mx+1),added++;
		printf("Case #%d: %d\n",tc,added);
	}
}
