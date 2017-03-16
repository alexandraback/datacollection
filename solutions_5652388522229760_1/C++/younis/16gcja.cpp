#include<cstdio>
bool ava[10];
int cnt;
inline void doit(int n){
	while(n){
		if(ava[n%10]){
			cnt++;
			ava[n%10]=false;
		}
		n/=10;	
	}
}
int main(){
	freopen("A-large.bin","r",stdin);
	freopen("output.txt","w",stdout);
	int t;scanf("%d",&t);
	int n,x;
	for(int cas=1;cas<=t;cas++){
		scanf("%d",&n);
		if(!n){printf("Case #%d: INSOMNIA\n",cas);continue;}
		for(x=0;x<10;x++)ava[x]=true;
		cnt=0;
		x=n;
		doit(x);
		while(cnt<10){
			x+=n;
			doit(x);
		}
		printf("Case #%d: %d\n",cas,x);
	}
	return 0;
}
