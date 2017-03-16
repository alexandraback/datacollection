#include <cstdio>
#include <cstring>
using namespace std;
int t,r,n,m,k;
int maxn=0,best;
int prod[10],cnt[10];
int main(){
	scanf("%d",&t);
	printf("Case #1:\n");
	scanf("%d %d %d %d",&r,&n,&m,&k);
	for(int x=0;x<r;x++){
		best=234;
		maxn=0;
		for(int y=0;y<k;y++) scanf("%d",&prod[y]);
		for(int a=2;a<6;a++){
			for(int b=a;b<6;b++){
				for(int c=b;c<6;c++){
					memset(cnt,0,sizeof(cnt));
					for(int y=0;y<8;y++){
						int ans=1;
						t=y;
						if(t%2==1) ans*=a;
						t/=2;
						if(t%2==1) ans*=b;
						t/=2;
						if(t%2==1) ans*=c;
						for(int z=0;z<k;z++) if(ans==prod[z]) cnt[z]++;
					}
					int ans=1;
					for(int y=0;y<k;y++){
						ans*=cnt[y];
					}
					if(ans>maxn){
						best=a*100+b*10+c;
						maxn=ans;
					}
				}
			}
		}
		printf("%d\n",best);
	}
	return 0;
}
					
