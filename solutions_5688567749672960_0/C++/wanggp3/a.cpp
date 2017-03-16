#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000005;
#define INF 0x3f3f3f3f
int ans,n;
int d[N];
bool inq[N];
int reverse(int x){
	int ret=0;
	while(x){
		ret=ret*10+x%10;
		x/=10;
	}
	return ret;
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)d[i]=INF,inq[i]=0;
	d[1]=1;
	queue<int>Q;
	Q.push(1);
	inq[1]=1;
	while(!Q.empty()){
		int x=Q.front();Q.pop();
	//	cout<<d[x]<<' '<<x<<"fucl "<<endl;
		inq[x]=0;
		int nx=x+1;
		if(nx<=n && d[nx]>d[x]+1){
			d[nx]=d[x]+1;
			if(!inq[nx]){
				Q.push(nx);
				inq[nx]=1;
			}
		}
		int rx = reverse(x);
		if(rx<=n && d[rx]>d[x]+1){
			d[rx]=d[x]+1;
			if(!inq[rx]){
				Q.push(rx);
				inq[rx]=1;
			}
		}
	}
	printf("%d\n",d[n]);
}
int main(){	
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		printf("Case #%d: ",i+1);
		solve();
	}
	return 0;
}
