#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 1010
using namespace std;
int n;
struct data{
	int a;
	int b;
};
data p[MAX];
char c[MAX];
int cmp(data x,data y){
	if(x.b!=y.b)
		return x.b<y.b;
	return x.a<y.a;
}
void ini(){
	for(int i=0;i<MAX;i++)
		c[i]=0;
}
int main(){
	int T;
	int ca=1;
	scanf("%d",&T);
	while(T--){
		ini();
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d%d",&p[i].a,&p[i].b);
		
		sort(p,p+n,cmp);
		/*for(int i=0;i<n;i++)
			printf("%d %d\n",p[i].a,p[i].b);*/
		int finish=1;
		int now=0;
		int star=0;
		int ans=0;
		while(now<n){
			int re=1;
			while(star<p[now].b && re){
				int end=n-1;
				re=0;
				while(end>now){
					if(c[end]){
						end--;
						continue;
					}
					if(star>=p[end].a){
						re=1;
						c[end]=1;
						ans++;
						star++;
						end--;
						break;
					}
					end--;
				}
			}
			
			
			if(star>=p[now].b){
				if(c[now])
					star+=1;
				else
					star+=2;
				ans++;
				now++;
				continue;
			}
			
			if(!c[now] && star>=p[now].a){
				c[now]=1;
				star++;
				ans++;
				re=1;
				while(star<p[now].b && re){
					int end=n-1;
					re=0;
					while(end>now){
						if(c[end]){
							end--;
							continue;
						}
						if(star>=p[end].a){
							re=1;
							c[end]=1;
							ans++;
							star++;
							end--;
							break;
						}
						end--;
					}
				}
			}
			if(star>=p[now].b){
				star+=1;
				ans+=1;
				now++;
			}
			else{
				finish=0;
				break;
			}
		}
		if(finish)
			printf("Case #%d: %d\n",ca++,ans);
		else
			printf("Case #%d: Too Bad\n",ca++);
	}
	return 0;
}
