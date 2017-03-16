#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
#define y1 y1_
#define ran() (rand()<<15|rand())

const int mo=(int)1e9+7,inf=(int)1e9;
const ll linf=(ll)1e18;

int n,m,L;

int f[1<<21],g[1<<21];

int Main(){
	scanf("%d%d%d",&n,&m,&L);
	f[0]=0;
	for(int s=1;s<1<<(m-L+1);s++){
		if(s==(s&-s)){
			f[s]=1;
			continue;
		}
		f[s]=inf;
		for(int i=0;i<m;i++){
			int now=0;
			int t;
			t=s&~(((1<<L)-1)<<(i-L+1));
			if(t!=s){
				now=max(now,1+f[t]);
			}
			else
				now=inf;
			t=s&(((1<<L)-1)<<(i-L+1));
			if(t!=s){
				now=max(now,1+f[t]);
			}
			else
				now=inf;
			f[s]=min(f[s],now);
		}
	//	printf("f[%d]=%d\n",s,f[s]);
	}
	for(int s=1;s<1<<(m-L+1);s++){
		if(s==(s&-s)){
			g[s]=L;
			continue;
		}
		g[s]=inf;
		for(int i=0;i<m;i++){
			int now=0;
			int t;
			t=s&~(((1<<L)-1)<<(i-L+1));
			if(t!=s){
				now=max(now,1+g[t]);
			}
			else
				now=inf;
			t=s&(((1<<L)-1)<<(i-L+1));
			if(t!=s){
				now=max(now,g[t]);
			}
			else
				now=inf;
			g[s]=min(g[s],now);
		}
	}
	return f[(1<<(m-L+1))-1]*(n-1)+g[(1<<(m-L+1))-1];
}

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A.out","w",stdout);
	int T; scanf("%d",&T);
	for(int Case=1;Case<=T;Case++)
		printf("Case #%d: %d\n",Case,Main());
	scanf("\n");
}
