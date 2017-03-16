/**/
#include<bits/stdc++.h>
using namespace std;
/***********************************************/
/*      ____________
 *     /            \
 *    /  /\      /\  \
 *   /  /  \    /  \  \
 *   \                /
 *    \     \___/    /
 *     \____________/
 */
const long long mod = 1000000007;
vector<vector<int> > graph;
int vis[1001];
int cnt[1001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("out.txt","w",stdout);
	freopen("C-large.in","r",stdin);
	int T,C = 1;
	cin>>T;
	while(T--){
		cout<<"Case #"<<C++<<": ";
		int N,x;
		cin>>N;
		graph.clear();
		graph.resize(N);
		int res = 0;
		for(int i = 0;i < N;i++){
			cin>>x;
			graph[i].push_back(x-1);
		}
		memset(cnt,-1,sizeof cnt);
		for(int i = 0;i < N;i++){
			memset(vis,0,sizeof vis);
			int cur = i,sz = 0,pre = -1;
			bool ci = false;
			while(!vis[cur]){
				sz++;
				vis[cur] = true;
				for(auto & j : graph[cur]){
					if(j != pre){
						pre = cur;
						cur = j;
						if(vis[j])ci = true;
						break;
					}
				}
			}
			if(ci && cur == i){
				res = max(res,sz);
			}
			if(!ci){
				cnt[cur] = max(cnt[cur],sz);
			}
		}
		int sc = 0;
		for(int i = 0;i < N;i++){
			if(cnt[i] == -1)continue;
			sc += cnt[i];
			if(cnt[graph[i][0]] != -1)sc --;
		}
		assert(sc <= N);
		res = max(res,sc);
		cout<<res<<'\n';
	}
	return 0;
}
/**/
