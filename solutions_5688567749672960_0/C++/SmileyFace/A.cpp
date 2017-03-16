#include <bits/stdc++.h>
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

int dist[1000009];
queue<int> q;

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	dist[1]=1;
	q.push(1);
	while(q.size()){
		int v=q.front();q.pop();
		//printf("%d ",v);
		int x1=v+1;
		if(x1<1000009&&dist[x1]==0){
			dist[x1]=dist[v]+1;
			q.push(x1);
		}
		int x2=0;
		int v2=v;
		while(v){
			x2*=10;
			x2+=v%10;
			v=(v-v%10)/10;
		}
		if(x2<1000009&&dist[x2]==0){
			dist[x2]=dist[v2]+1;
			q.push(x2);
		}
	}
	int tc;scanf("%d",&tc);
	for(int tcno=1;tcno<=tc;tcno++){
		int n;scanf("%d",&n);
		printf("Case #%d: %d\n",tcno,dist[n]);
	}
}
