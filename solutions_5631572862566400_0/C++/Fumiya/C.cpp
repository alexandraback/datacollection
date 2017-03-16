#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int main(){
	int T; cin >> T;
	for(int caseNum=1;caseNum<=T;++caseNum){
		int N; cin >> N;
		vector<int> F(N);
		vector< vector<int> > g(N);
		for(int i=0;i<N;i++){
			cin >> F[i]; --F[i];
			g[F[i]].push_back(i);
		}
		vector<int> size(N, 0);
		int res = 0;
		int maxCircle = 0;
		for(int i=0;i<N;i++){
			if(size[i] != 0) continue;
			vector<int> used(N, 0);
			used[i] = 1;
			int p = F[i];
			int s = 1;
			while(!used[p]){
				++s;
				used[p] = 1;
				p = F[p];
			}
			if(p != i) continue;
			size[i] = s;
			maxCircle = max(maxCircle, s);
			p = F[i];
			while(p != i){
				size[p] = s;
				p = F[p];
			}
			if(s == 2){
				queue<int> qu;
				int add[2] = {0, 0};
				for(int j=0;j<2;j++){
					if(j == 0) qu.push(i);
					else qu.push(F[i]);
					while(!qu.empty()){
						p = qu.front(); qu.pop();
						for(int idx : g[p]){
							if(size[idx] != 0) continue;
							size[idx] = size[p]+1;
							add[j] = max(add[j], size[p]-1);
							qu.push(idx);
						}
					}
				}
				res += s + add[0] + add[1];
			}
		}
		printf("Case #%d: %d\n", caseNum, max(maxCircle, res));
	}
}
