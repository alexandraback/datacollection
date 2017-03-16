#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
long long l[10],r[10];
int d[10],h[10],m[10];
int ans,n;
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n==1){
			scanf("%d%d%d",&d[0],&h[0],&m[0]);
			d[1]=d[0],h[1]=0,m[1]=m[0]+1;
		}
		else {
			scanf("%d%d%d",&d[0],&h[0],&m[0]);
			scanf("%d%d%d",&d[1],&h[1],&m[1]);
		}
		for (int i=0;i<2;i++){
			l[i]=(long long)m[i]*(360-d[i]);
			r[i]=(long long)m[i]*(720-d[i]);
		}
		if(l[0]>l[1]) {swap(l[0],l[1]);swap(r[0],r[1]);}
		if(l[1]>=r[0]) ans=1;
		else ans=0;
		if(h[0]==1&&h[1]==0) ans=0;
		printf("Case #%d: %d\n",ca++,ans);
	}
	return 0;
}
