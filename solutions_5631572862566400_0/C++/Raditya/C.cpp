#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long LL;
typedef pair<int,int> pii;
const int N = 1000;
vector<int> balik[N];
vector<int> ciklus;
int ar[N];
bool udah[N];
int maks = 0;
int kena = -1;
inline void proses(int x){
	udah[x] = 1;
	if(udah[ar[x]]) kena = ar[x];
	else {
		proses(ar[x]);
	}
	udah[x] = 0;
}
int dfs(int v){
	udah[v] = 1;
	if(balik[v].size() == 0) return 1;
	else{
		int ans = 0;
		for(int i = 0;i < balik[v].size();++i){
			int x = balik[v][i];
			ans = max(ans, dfs(x));
		}
		return ans+1;
	}
}
int main(){
	int t;
	scanf("%d", &t);
	for(int tc = 1; tc <= t;++tc){
		int n;
		scanf("%d",&n);
		memset(udah,0,sizeof udah);
		maks = 0;
		for(int i = 0;i < n; ++i){
			balik[i].clear();
		}
		for(int i = 0;i < n; ++i){
			int a;
			scanf("%d", &a);
			a--;
			ar[i] = a;
			balik[a].pb(i);
		}

		//mulai pemrosesan
		for(int i = 0; i < n; ++i){
			if(!udah[i]){
				proses(i);
				ciklus.clear();
				ciklus.pb(kena);
				int temp = ar[kena];
				while(temp != kena){
					ciklus.pb(temp);
					temp = ar[temp];
				}
				for(int j = 0; j < (int) ciklus.size(); ++j) udah[ciklus[j]] = 1;
				int max1 = 0, max2 = 0;
				for(int j = 0; j < (int) ciklus.size(); ++j){
					int makstemp = 0;
					int v = ciklus[j];
					for(int k = 0;k < balik[v].size(); ++k){
						int u = balik[v][k];
						if(!udah[u]){
							int ans = dfs(u);
							makstemp = max(makstemp, ans);
						}
					}
					if(makstemp > max1){
						max2 = max1;
						max1 = makstemp;
					}
					else if(makstemp > max2){
						max2 = makstemp;
					}
				}
				if(ciklus.size() == 2){
					maks = max(maks, 2 + max1 + max2);
				}
				else{
					maks = max(maks, (int)ciklus.size());
				}
			}
		}
		printf("Case #%d: %d\n", tc, maks);
	}
}