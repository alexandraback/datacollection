#include <iostream>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 1000

vector<int> L[MAXN],Lrev[MAXN];
int visited[MAXN];
vector< pair<int, int> > bff;

int dfs(int cur, int forbidden){
	int ret = 1;

	for(int to : Lrev[cur]){
		if(to != forbidden)
			ret = max(ret,1 + dfs(to, forbidden));
	}

	return ret;
}

int main(){
  int T,N;

  cin >> T;
  
  for(int tc = 1;tc <= T;++tc){
  	cin >> N;

  	for(int i = 0;i < N;++i){
  		L[i].clear();
  		Lrev[i].clear();
  	}

  	for(int i = 0,to;i < N;++i){
  		cin >> to;
  		--to;
  		L[i].push_back(to);
  		Lrev[to].push_back(i);
  	}

  	int ans = 0;
  	bff.clear();

  	for(int i = 0;i < N;++i){
  		memset(visited,-1,sizeof visited);

  		int cur = i,cont = 0;

  		while(visited[cur] == -1){
  			visited[cur] = cont++;
  			cur = L[cur][0];
  		}

  		int len = cont - visited[cur];
  		ans = max(ans,len);

  		if(len == 2){
  			int a = cur,b = L[cur][0];
  			if(b < a) swap(a,b);
  			bff.push_back(make_pair(a,b));
  		}
  	}

  	sort(bff.begin(),bff.end());
  	bff.erase(unique(bff.begin(),bff.end()),bff.end());

  	int total = 0;

  	for(pair<int, int> p : bff){
  		int r1 = p.first,r2 = p.second;
  		total += dfs(r1,r2) + dfs(r2,r1);
  	}

  	ans = max(ans,total);

    cout << "Case #" << tc << ": " << ans << "\n";
  }
  
  return 0;
}
