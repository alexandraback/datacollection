#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <cassert>
using namespace std;

int C, D, V;
int mark[100];
int vis[100];
vector<int> st;


bool check(){
	bool ok = false;
	for(int i=1;i<=V;++i){
		if(vis[i] != 1) return false;
	}
	return true;
}


void run() {
	int dd = st.size();
	for(int i=0;i<=V;++i)vis[i] = 0;
	for(int b=1;b<(1<<dd);++b){
		int cnt = 0;
		for(int i=0;i<dd;++i){
			if(b & (1<<i)) {
				cnt += st[i];
			}
		}
		if(cnt > V) continue;
		vis[cnt] = 1;
	}
}

int main(){

	int TC;
	scanf("%d",&TC);
	for(int tc=1;tc<=TC;++tc){
		printf("Case #%d:", tc);
		scanf("%d%d%d",&C,&D,&V);
		int x;
		for(int i=0;i<100;++i)vis[i] = mark[i] = 0;
		st.clear();
		for(int i=0;i<D;++i){
			scanf("%d",&x);
			mark[x] = 1;
			st.push_back(x);
		}
		int ans = 8;
		for(int i=0;i<(1<<8);++i){
			bool ok = true;
			int k = __builtin_popcount(i);
			for(int j=0;j<8;++j){
				if(i & (1<<j)) {
					if(mark[j+1]) {
						ok = false;
						break;
					}
				}
			}
			if(!ok)continue;
			for(int j=0;j<8;++j){
				if(i & (1<<j)) {
					if(mark[j+1]) {
						ok = false;
						break;
					}
					st.push_back(j+1);
				}
			}
			run();
			if(check()){
				ans = k;
				break;
			}
			for(int j=0;j<k;++j){
				st.pop_back();
			}
		}
		printf(" %d\n",ans);
	}
	return 0;
}