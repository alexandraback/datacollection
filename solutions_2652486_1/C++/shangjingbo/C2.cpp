#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int T,test=1;
	for (scanf("%d",&T);test<=T;++test){
		printf("Case #%d:\n",test);
		int correct=0;
		int R,n,M,K;
		scanf("%d%d%d%d",&R,&n,&M,&K);
		for (int r=0;r<R;++r){
			int answer[n];
			for (int i=0;i<n;++i){
				answer[i]=rand()%(M-1)+2;
			}
			int a[K],bak[K];
			for (int i=0;i<K;++i){
				//scanf("%d",&a[i]);
				a[i]=1;
				for (int j=0;j<n;++j){
					if (rand()&1){
						a[i]*=answer[j];
					}
				}
				bak[i]=a[i];
			}
			
			for (int c6=0;c6<=n;++c6){
				for (int c8=0;c8+c6<=n;++c8){
					int maxi[10]={0},total=0;
					for (int i=0;i<K;++i){
						int cnt[10]={0};
						int x=a[i];
						for (int j=2;j<=x;++j){
							while (x%j==0){
								++cnt[j];
								x/=j;
							}
						}
						int delta=min(cnt[2],cnt[3]);
						delta=min(delta,c6);
						cnt[2]-=delta;
						cnt[3]-=delta;
						
						delta=min(cnt[2]/3,c8);
						cnt[2]-=delta;
						
						for (int j=0;j<10;++j){
							maxi[j]=max(maxi[j],cnt[j]);
						}
					}
					int c5=maxi[5];
					int c7=maxi[7];
					int c3=maxi[3];
					int c2 = maxi[2] % 2;
					int c4 = maxi[2] / 2;
					if (c4>0 && c6+c8+c3+c5+c7+c2+c4+1<=n){
						c2+=2;
						c4--;
					}
					if (c2+c3+c4+c5+c6+c7+c8<=n){
						for (int i=0;i<c3;++i) printf("3");
						for (int i=0;i<c7;++i) printf("7");
						for (int i=0;i<c8;++i) printf("8");
						for (int i=0;i<c5;++i) printf("5");
						for (int i=0;i<c2;++i) printf("2");
						for (int i=0;i<c4;++i) printf("4");
						for (int i=0;i<c6;++i) printf("6");
						
						for (int i=c2+c3+c4+c5+c6+c7+c8;i<n;++i) printf("2");
						puts("");
						goto Break;
					}
				}
			}
			for (int i=0;i<n;++i) printf("2");
			puts("");
			Break:;
		}
	}
	return 0;
}
