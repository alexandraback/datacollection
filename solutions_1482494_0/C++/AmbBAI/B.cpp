#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Fuck{
	int a,b;
	friend bool operator< (const Fuck& x,const Fuck& y){
		if(x.b==y.b) return x.a<y.a;
		return x.b>y.b;
	}
}F[1005];

int val[1005][2];
int main(){
	freopen("B-small-attempt4.in","r",stdin);
	freopen("small-B.out","w",stdout);
	
	int t, cas=0;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d",&F[i].a,&F[i].b);
		}
		sort(F,F+n);
		
		for(int i=0;i<n;i++){
			val[i][0] = F[i].a;
			val[i][1] = F[i].b;
		}
		
		int star = 0;
		int ans = 0;
		int win = 0;
		

		
		while(true){
			bool flag = true;
			for(int i=0;i<n;i++){
				if(val[i][1]==-1) continue;
				if(val[i][1]<=star){
					if(val[i][0] == -1) star += 1;
					else star += 2;
					val[i][1] = val[i][0] = -1;
					flag = false;
					ans++;
					win++;
					break;
				}
			}
			if(win == n) break;
			if(flag){
				for(int i=0;i<n;i++){
					if(val[i][0]==-1) continue;
					if(val[i][0]<=star){
						val[i][0] = -1;
						ans++;
						star += 1;
						flag = false;
						break;
					}
				}
			}
			if(flag) break;
		}
		//printf("-- %d %d\n",star, n);
		printf("Case #%d: ",++cas);
		if(win!=n) puts("Too Bad");
		else printf("%d\n",ans);
	}
}