#include <cstdio>
#include <algorithm>
using namespace std;

int tqn,tqi,n,x,y,X,Y,ms,it,a[55][55],i,ans;

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&tqn);
	for(tqi=1;tqi<=tqn;tqi++){
		scanf("%d%d%d",&n,&x,&y);
		if(abs(x)>20||abs(y)>20||y<0){
			printf("Case #%d: %.10lf\n",tqi,0.0);
			continue;
		}
		x+=20;ans=0;
		X=x,Y=y;
		for(ms=0;ms<(1<<n);ms++){
			++it;
			a[20][0]=it;
			for(i=1;i<n;i++){
				x=20,y=20;
				while(y>0){
					if(y>1&&a[x][y-2]!=it){--y;continue;}
					if(a[x-1][y-1]==it&&a[x+1][y-1]==it){a[x][y]=it;break;}
					if(a[x-1][y-1]==it){--y;++x;continue;}
					if(a[x+1][y-1]==it){--y;--x;continue;}
					if(ms&(1<<i))++x;else --x;
					--y;
				}				
				a[x][y]=it;
			}
			ans+=a[X][Y]==it;
		}
		printf("Case #%d: %.10lf\n",tqi,1.0*ans/(1<<n));
	}
	return 0;
}