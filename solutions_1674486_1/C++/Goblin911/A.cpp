#include<queue>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

struct edge{
	int d;
	edge* next;
};

edge* b[1001],*I;
int n,c[1001],f[1001],v[1001];
void addedge(int x,int y){
	//cout<<x<<' '<<y<<endl;
	edge* t=new edge();t->d=y;t->next=b[x];b[x]=t;
}

void init(){
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	scanf("%d",&n);int t,x;
	for (int i=1;i<=n;i++){
		scanf("%d",&t);
		for (int j=1;j<=t;j++){
			scanf("%d",&x);
			addedge(i,x);
			c[x]++;
		}
	}
}


void solve(){
	for (int i=1;i<=n;i++) if (c[i]==0) {
		queue<int> q;q.push(i);memset(v,0,sizeof(v));v[i]=1;
		while (!q.empty()){
			int x=q.front();q.pop();
			for (I=b[x];I;I=I->next){
				if (v[I->d]) {
					printf("Yes");
					return;
				}
				v[I->d]=1;
				q.push(I->d);
			}
		}
	}
	printf("No");
	return;
}

int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int t,T;cin>>T;
	for (t=1;t<=T;t++){
		printf("Case #%d: ",t);
		init();
		solve();
		printf("\n");
	}
}