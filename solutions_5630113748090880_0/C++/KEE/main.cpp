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
int g[60][60];
int cur = 0;
bool cmp(vector<int> & a,vector<int>& b){
	return a[cur] < b[cur];
}
int fr[51],fc[51];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("out.txt","w",stdout);
	freopen("B-small-attempt0.in","r",stdin);
	int T,C = 1;
	cin>>T;
	while(T--){
		cout<<"Case #"<<C++<<": ";
		int N;
		cin>>N;
		cur = 0;
		vector<vector<int>> a(2*N-1);
		for(int i = 0;i+1 < 2*N;i++){
			a[i].resize(N);
			for(int j = 0;j < N;j++){
				cin>>a[i][j];
			}
		}
		memset(g,-1,sizeof g);
		int ms = -1,to = 0;
		map<int,vector<vector<int> > > tab;
		while(cur < N){
			sort(a.begin()+to,a.end(),cmp);
			tab[cur].push_back(a[to]);
			to++;
			if(to < 2*N -1 && a[to-1][cur] == a[to][cur]){
				tab[cur].push_back(a[to]);
				to++;
			}
			else ms = cur;
			cur++;
		}
		deque<pair<int,vector<int> > > r,c;
		memset(fr,0,sizeof fr);
		memset(fc,0,sizeof fc);
		bool row = false;;
		if(tab[0].size() > 1){
			r.push_back({0,tab[0][0]}),fr[0] = true;
			c.push_back({0,tab[0][1]}),fc[0] = true;
		}else{
			r.push_back({1,tab[1][0]}),fr[1] = true;
			c.push_back({1,tab[1][1]}),fc[1] = true;
		}
		while(true){
			if(r.size() == 0 && c.size() == 0){
				break;
			}
			while(!r.empty()){
				if(r.front().first == ms)row = false;
				for(int i = 0; i < N;i++){
					g[r.front().first][i] = r.front().second[i];
				}
				r.pop_front();
			}
			while(!c.empty()){
				if(c.front().first == ms)row = true;
				for(int i = 0; i < N;i++){
					g[i][c.front().first] = c.front().second[i];
				}
				c.pop_front();
			}
			bool f = false;
			for(int i = 0;i < N;i++){
				for(int j = 0;j < N;j++){
					if(g[i][j] == -1)continue;
					if(g[j][i] == -1)continue;
					if(g[i][j] != g[j][i]){
						if(!fr[i]){
							for(auto & v : tab[i]){
								if(v[j] == g[i][j]){
									f = true;
									fr[i] = true;
									r.push_back({i,v});
								}
							}
						}
						if(!fc[i]){
							for(auto & v : tab[i]){
								if(v[j] == g[j][i]){
									f = true;
									fc[i] = true;
									c.push_back({i,v});
								}
							}
						}
						if(!fr[j]){
							for(auto & v : tab[j]){
								if(v[i] == g[j][i]){
									f = true;
									fr[j] = true;
									r.push_back({j,v});
								}
							}
						}
						if(!fc[j]){
							for(auto & v : tab[j]){
								if(v[i] == g[i][j]){
									f = true;
									fc[j] = true;
									c.push_back({j,v});
								}
							}
						}
					}
				}
			}
			if(!f){
				for(int i = 0;!f && i < N;i++){
					if(fr[i])continue;
					for(int k = 0;k < tab[i].size();k++){
						auto & v = tab[i][k];
						bool can = true;
						for(int j = 0;j < N;j++){
							if(g[i][j] == -1)continue;
							if(v[j] != g[i][j]){
								can = false;
								break;
							}
						}
						if(can){
							f = true;
							r.push_back({i,v});
							fr[i] = true;
							if(tab[i].size() > 1 && !fc[i]){
								c.push_back({i,tab[i][!k]});
							}
							break;
						}
					}
				}
			}
		}
		for(int i = 0;i < N;i++)for(int j = 0;j < N;j++)cerr<<g[i][j]<<" \n"[j+1 == N];
		cerr<<endl;
		vector<int> res;
		for(int i = 0;i < N;i++){
			if(row)cout<<g[ms][i];
			else cout<<g[i][ms];
			cout<<" \n"[i+1 == N];
		}

	}
	return 0;
}
/**/
