#include <cmath>
#include <vector>
#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
typedef long long Long;

typedef vector<int> VI;
typedef vector<VI> VVI;
int main() {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int TC;
	cin >> TC;
	for(int tc = 1; tc <= TC; ++tc){
		
		VVI G;
		int N;
		cin >> N;
		VI V(N);
		for(int i = 0; i < N; ++i){
			cin >> V[i];
			V[i]--;
		}
		VI VIS(N,0);
		for(int i = 0; i < N; ++i){
			int j = i;
			VI T;
			while(VIS[j] == 0){
				VIS[j] = 1;
				j = V[j];
			}
			while(VIS[j] == 1){
				VIS[j] = 2;
				T.push_back(j);
				j = V[j];
			}
			if(T.size()){
				G.push_back(T);
//				for(int j = 0; j < T.size(); ++j){
//					cout << T[j] << " ";
//				}
//				cout << endl;
			}
			for(int j = 0; j < N; ++j)
				if(VIS[j] == 1)
					VIS[j] = 0;
		}
		vector<int> G2(N, 0);
		for(int i = 0; i < N; ++i){
			int j = i, cnt = 1;
			while(VIS[j] != 2){
				j = V[j];
				cnt++;
			}
			G2[j] = max(G2[j], cnt);
		}
//		for(int i = 0; i < N; ++i){
//			cout << G2[i] << " ";
//		}
//		cout << endl;
		int A = 0;
		for(int i = 0; i < G.size(); ++i){
			A = max(A, (int)G[i].size());
		}
		int TA = 0;
		for(int i = 0; i < G.size(); ++i){
			if(G[i].size() != 2)continue;
			TA += G2[G[i][0]] + G2[G[i][1]];
		}
		cout << "Case #" << tc << ": " << max(A, TA) << endl;
	}
}


/*
 ######
 ######
 ######
 ######
*/
