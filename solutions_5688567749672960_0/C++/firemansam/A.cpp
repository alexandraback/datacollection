#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int tcs, visit[1000050], n;
queue<ii> bfs;
int rev(int k){
	int l = 0;
	while(k > 0){
		l *= 10;
		l += (k % 10);
		k /= 10;
	}
	return l;
}
int main(){
	scanf("%i", &tcs);
	for(int tc=1;tc<=tcs;tc++){
		scanf("%i", &n);
		while(!bfs.empty()) bfs.pop();
		memset(visit, 0, sizeof visit);
		bfs.push(ii(1, 1));
		while(!bfs.empty()){
			ii t = bfs.front();
			bfs.pop();
			if(visit[t.first]) continue;
			visit[t.first] = 1;
			if(t.first == n){ printf("Case #%i: %i\n", tc, t.second); break; }
			bfs.push(ii(t.first + 1, t.second + 1));
			int k = rev(t.first);
			if(k != t.first) bfs.push(ii(k, t.second + 1));
		}
	}
}