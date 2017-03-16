#include <cstdio>

int T,N;
int cnt[18];
void count(long long vl) {
	if(vl<10) {
		cnt[vl]=1;
		return;
	}
	cnt[vl%10]=1;
	count(vl/10);
}
int main() {
	scanf("%d",&T);
	for(int ts=1;ts<=T;ts++) {
		scanf("%d",&N);
		int ok=0;
		long long now=N;
		for(int j=0;j<10;j++) cnt[j]=0;
		for(int i=1;i<102;i++) {
			count(now);
			int csum=0;
			for(int j=0;j<10;j++) csum+=cnt[j];
			if(csum>9) {
				ok=1;
				break;
			}
			now+=N;
		}
		if(ok) {
			printf("Case #%d: %lld\n",ts,now);
		} else {
			printf("Case #%d: INSOMNIA\n",ts);
		}
	}
	return 0;
}
