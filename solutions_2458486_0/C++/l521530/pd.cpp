
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define N 410
typedef long long int LL;

using namespace std;

int n;
int key[N],dif[N];
vector<int> btvec[N];
int bt[N];
vector<int> box[N];

void input(){
	for(int i=0;i<N;i++){
		box[i].clear();
		btvec[i].clear();
	}
	memset(key,0,sizeof(key));
	memset(dif,0,sizeof(dif));

	int k;
	scanf("%d%d",&k,&n);
	for(int i=0,x; i<k; i++){
		scanf("%d",&x);
		key[x]++;
		dif[x]++;
	}
	for(int i=0,x,y;i<n;i++){
		scanf("%d%d",&bt[i],&x);
		btvec[bt[i]].push_back(i);
		dif[bt[i]]--;
		for(int j=0; j<x; j++){
			scanf("%d",&y);
			dif[y]++;
			box[i].push_back(y);
		}	
	}
}
int used[N],list[N];

void put(int a){
	used[a]=1;
	key[bt[a]]--;
	FOR(it,box[a]){
		key[*it]++;
	}
}
void rel(int a){
	used[a]=0;
	key[bt[a]]++;
	FOR(it,box[a]){
		key[*it]--;
	}
}

bool easygame(){
	int enc[N],enb[N];
	memset(enc,0,sizeof(enc));
	memset(enb,0,sizeof(enb));
	queue<int> q;
	for(int i=0;i<N;i++){
		if(key[i]){
			q.push(i);
			enc[i] = 1;
		}
	}
	while(!q.empty()){
		int t = q.front(); q.pop();
		FOR(itt, btvec[t]){
			int b = *itt;
			if(used[b]) continue;
			enb[b] = 1;
			FOR(it, box[b]){
				if(enc[*it]==0){
					enc[*it]=1;
					q.push(*it);
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		if(used[i]==0 && enb[i]==0)return false;
	}
	return true;
}

void solve(){
	//for(int i=0;i<=n;i++)printf("%d ",key[i]);puts("key");
	static int zi=0;
	for(int i=0;i<N;i++){
		if(dif[i]<0){
			printf("Case #%d: IMPOSSIBLE\n",++zi);
			return;
		}
	}
	memset(used,0,sizeof(used));
	memset(list,-1,sizeof(list));	
	if(!easygame()){
		printf("Case #%d: IMPOSSIBLE\n",++zi);
		return;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if( used[j] || key[bt[j]]<=0 )continue;
			//printf("test %d %d\n",i, j);
			//for(int k=0;k<=n;k++)printf("%d ",key[k]);puts("key");
			put(j);
			//for(int k=0;k<=n;k++)printf("%d ",key[k]);puts("key");
			if(easygame()){
				list[i]=j;
				break;
			}
			rel(j);
		}
	}
	printf("Case #%d:",++zi);
	for(int i=0;i<n;i++)printf(" %d",list[i]+1);
	puts("");
}

int main(){

	int zn;
	scanf("%d",&zn);
	while(zn--){
		input();
		solve();
	}

	return 0;
}
