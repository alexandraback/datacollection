#include<cstdio>
using namespace std;
int cas,n,s,p,x,ps,ans;
int main(){
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	scanf("%d",&cas);
	for(int ca=1;ca<=cas;ca++){
		scanf("%d%d%d",&n,&s,&p);
		ps=0,ans=0;
		for(int i=0;i<n;i++){
			scanf("%d",&x);	
			if(x>=3*p-2)ans++;
			else if(x>=3*p-4&&!(x==0&&p==1)&&ps<s)ps++,ans++;
		}
		printf("Case #%d: %d\n",ca,ans);
	}
	return 0;
}
