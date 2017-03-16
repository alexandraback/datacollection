#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

void solveSmall(const vector<int>& initKey, const vector<int>& openKey, const vector< vector<int> >& getKey){
	static vector<int> path[1<<20];
	for(int i=0;i<(1<<20);i++) path[i].clear();
	int start[201], curKey[201];
	for(int i=0;i<=200;i++) start[i] = 0;
	for(int i=0;i<initKey.size();i++) start[initKey[i]]++;
	for(int i=0;i<(1<<openKey.size());i++){
		if(i && path[i].empty()) continue;
		memcpy(curKey, start, sizeof(curKey));
		for(int j=0;j<openKey.size();j++){
			if(!(i&(1<<j))) continue;
			curKey[openKey[j]]--;
			for(int k=0;k<getKey[j].size();k++)
				curKey[getKey[j][k]]++;
		}
		path[i].push_back(0);
		for(int j=0;j<openKey.size();j++){
			if(i&(1<<j)) continue;
			if(curKey[openKey[j]] > 0){
				path[i].back() = j;
				if(path[i|(1<<j)].empty() || path[i|(1<<j)] > path[i]) path[i|(1<<j)] = path[i];
			}
		}
		path[i].pop_back();
	}
	int all = (1<<openKey.size())-1;
	if(path[all].empty()){
		cout << " IMPOSSIBLE" << endl;
		return ;
	}
	for(int i=0;i<path[all].size();i++)
		cout << " " << path[all][i]+1;

	bool ok = true;
	for(int i=0;i<path[all].size();i++){
		if(start[openKey[path[all][i]]] <= 0) ok = false;
		start[openKey[path[all][i]]]--;
		for(int j=0;j<getKey[path[all][i]].size();j++)
			start[getKey[path[all][i]][j]]++;
	}
	if(!ok) cout << "================FAIL========================" << endl;

	cout << endl;
}

int main(){
	int T; cin >> T;
	for(int test=1;test<=T;test++){
		int K, N; cin >> K >> N;
		vector<int> initKey(K), openKey(N);
		vector< vector<int> > getKey(N);
		for(int i=0;i<K;i++) cin >> initKey[i];
		for(int i=0;i<N;i++){
			cin >> openKey[i];
			int t; cin >> t;
			getKey[i].assign(t, 0);
			for(int j=0;j<t;j++) cin >> getKey[i][j];
		}
		printf("Case #%d:", test);
		solveSmall(initKey, openKey, getKey);
	}
}
