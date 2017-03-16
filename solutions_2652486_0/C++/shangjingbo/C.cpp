#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
	int T,test=1;
	for (scanf("%d",&T);test<=T;++test){
		printf("Case #%d:\n",test);
		int R,n,M,K;
		scanf("%d%d%d%d",&R,&n,&M,&K);
		for (int r=0;r<R;++r){
			int maxi[10]={0},total=0;
			for (int i=0;i<K;++i){
				int cnt[10]={0};
				int x;
				scanf("%d",&x);
				for (int j=2;j<=x;++j){
					while (x%j==0){
						++cnt[j];
						x/=j;
					}
				}
				for (int j=0;j<10;++j){
					maxi[j]=max(maxi[j],cnt[j]);
				}
			}
			int c3 = maxi[3];
			int c5 = maxi[5];
			int c2 = maxi[2] % 2;
			int c4 = maxi[2] / 2;
			if (c4>0 && c3+c5+c2+c4+1<=n){
				c2+=2;
				c4--;
			}
			if (c2+c3+c4+c5<=n){
				for (int i=0;i<c3;++i) printf("3");
				for (int i=0;i<c5;++i) printf("5");
				for (int i=0;i<c2;++i) printf("2");
				for (int i=0;i<c4;++i) printf("4");
				for (int i=c2+c3+c4+c5;i<n;++i) printf("2");
				puts("");
			}else{
				for (int i=0;i<n;++i) printf("2");
				puts("");
			}
		}
	}
	return 0;
}
