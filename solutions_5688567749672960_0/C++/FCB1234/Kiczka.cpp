#include <queue>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int mxn=10000005;

int d[mxn], N;

int reverse(int a){
	int w=0;
	while(a>0){
		w*=10;
		w+=a%10;
		a/=10;
	}
	return w;
}

void rek(){
	queue <int> Q;
	d[1]=1;
	Q.push(1);
	while(!Q.empty()){
		int k=Q.front();
		//printf("%d %d\n", k, d[k]);
		if(k==N)
			return;
		Q.pop();
		int x=reverse(k);
		if(x<=N&&d[x]==0&&x!=k){
			d[x]=d[k]+1;
			Q.push(x);
		}
		if(k+1<=N&&d[k+1]==0){
			d[k+1]=d[k]+1;
			Q.push(k+1);
		}
	}
}

int main() {
	int q;
	scanf("%d", &q);
	for(int i=1;i<=q;++i){
		int n;
		scanf("%d", &n);
		N=n;
		rek();
		printf("Case #%d: %d\n", i, d[n]);
		for(int i=0;i<=n;++i)
			d[i]=0;
	}
	return 0;
}
