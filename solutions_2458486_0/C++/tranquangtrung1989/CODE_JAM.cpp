#include <iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
#define cin fin
#define cout fout
ifstream fin("in.txt");
ofstream fout("out.txt");
using namespace std;
int T, K, N, Ti, Ki, key;
vector<int> bfS(int idx, map<int, int> setKey,
		map<int, vector<int> > mapKey, vector<int> openKey,
		map<int, int> isCheck, vector<int> result){

		if(setKey[openKey[idx]]>0){
			queue <int> Q;
			Q.push(idx);
			while(!Q.empty()){
				if(isCheck[Q.front()]==0&&setKey[openKey[Q.front()]]>0){
						for(int ix=0;ix<mapKey[Q.front()].size();ix++)
						setKey[mapKey[Q.front()][ix]]++;
						setKey[openKey[Q.front()]]--;
						isCheck[Q.front()]=1;
						result.push_back(Q.front());
						if(result.size()==N) return result;

				}
				Q.pop();
				for(int i=0;i<N;i++){
					if(isCheck[i]==0&&setKey[openKey[i]]>0)
					Q.push(i);
				}
			}
		}
		return result;
}
int main() {
	map<int, int> setKey;
	map<int, vector<int> > mapKey;
	vector<int> openKey (N);
	cin >> T;
	for(int t=1; t<=T;t++){
		cin >> K >> N;
		setKey.clear();
		mapKey.clear();
		openKey.resize(N);
		for(int i=0;i<K;i++){
			cin >> key;
			setKey[key]++;
		}

		for(int i=0;i<N;i++){
			cin >> Ti >>Ki;
			openKey[i]= Ti;
			vector<int> tmp(Ki);
			for(int ii=0;ii<Ki;ii++) cin >> tmp[ii];
			mapKey[i]=tmp;
		}

		vector<int> result, rs;
		map<int, int> isCheck;
		for(int i=0;i<N;i++){
			result=bfS(i, setKey, mapKey, openKey, isCheck, rs);
			if(result.size()==N) break;
		}

		cout<<"Case #"<<t<<": ";
		if(result.size()==N) {
			for(int i=0;i<N;i++){
				if(i>0) cout<<" ";
				cout<<result[i]+1;
			}
		}
		else cout<<"IMPOSSIBLE";
		cout<<endl;
	}


	return 0;
}
