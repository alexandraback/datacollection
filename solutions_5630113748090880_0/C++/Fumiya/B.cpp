#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int T; cin >> T;
	for(int caseNum=1;caseNum<=T;++caseNum){
		int N; cin >> N;
		vector< vector<int> > v;
		for(int i=0;i<2*N-1;i++){
			vector<int> vi(N);
			for(int j=0;j<N;j++) cin >> vi[j];
			v.push_back(vi);
		}
		sort(v.begin(), v.end());
		vector<int> line(2*N-1, -1);
		vector< vector< vector<int> > > vl(N);
		for(int i=0;i<N;i++){
			int minVal = 1000000;
			for(int j=0;j<v.size();j++){
				if(line[j] != -1) continue;
				minVal = min(minVal, v[j][i]);
			}
			for(int j=0;j<v.size();j++){
				if(minVal == v[j][i]){
					line[j] = i;
					vl[i].push_back(v[j]);
				}
			}
		}
		vector<int> sameLine;
		int missing = -1;
		for(int i=0;i<N;i++){
			if(vl[i].size() == 1){
				sameLine = vl[i][0];
				missing = i;
			}
		}
		vector<int> res;
		for(int i=0;i<N;i++){
			if(missing == i){
				res.push_back(sameLine[missing]);
				continue;
			}
			vector<int> a;
			for(int j=0;j<vl[i].size();j++){
				a.push_back(vl[i][j][missing]);
			}
			if(a[0] == sameLine[i]){
				res.push_back(a[1]);
			} else {
				res.push_back(a[0]);
			}
		}
		printf("Case #%d:", caseNum);
		for(int i=0;i<res.size();++i) cout << " " << res[i];
		cout << endl;
	}
}

