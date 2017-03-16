#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int j,p,s,k;
vector<vector<int>> G;
vector<int> v;

int go(int source,int sink){
	if (v[source]) return 0;
	v[source]=1;
	if (source==sink) return 1;
	for(int &x:G[source]){
		if (go(x,sink)){
			G[x].push_back(source);
			x=G[source].back();
			G[source].pop_back();
			return 1;
		}
	}
	return 0;
}

int flow(int source,int sink){
	int res=0;
	v.resize(sink+1);
	while(1){
		fill(begin(v),end(v),0);
		if (!go(source,sink)) break;
		++res;
	}
	return res;
}

int main(){
	int cases;
	scanf("%d",&cases);
	for(int t=1;t<=cases;++t){
		printf("Case #%d: ",t);
		scanf("%d%d%d%d",&j,&p,&s,&k);
		int n1=j*p+j*s+p*s;
		int n2=j*p*s;
		int source=n1+n2;
		int sink=source+1;
		G.clear();
		G.resize(sink+1,vector<int>());
		for(int a=0;a<j;++a){
			for(int b=0;b<p;++b){
				for(int c=0;c<s;++c){
					//G[a*p+b].push_back(n1+a*p*s+b*s+c);
					//G[j*p+a*s+c].push_back(n1+a*p*s+b*s+c);
					//G[j*p+j*s+b*s+c].push_back(n1+a*p*s+b*s+c);
					G[j*p+j*s+b*s+0].push_back(n1+a*p*s+b*s+c);
				}
			}
		}
		for(int i=0;i<n1;++i){
			for(int b=0;b<k;++b){
				G[source].push_back(i);
			}
		}
		for(int i=0;i<n2;++i){
			for(int b=0;b<1;++b){
				G[n1+i].push_back(sink);
			}
		}
		int res=flow(source,sink);
		printf("%d\n",res);
		for(int x:G[sink]){
			x-=n1;
			int a=x/(p*s)+1;
			int b=x%(p*s)/s+1;
			int c=x%(p*s)%s+1;
			printf("%d %d %d\n",a,b,c);
		}
	}
	return 0;
}
