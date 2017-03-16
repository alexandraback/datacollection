#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <utility>
#include <cmath>
#include <list>
#include <map>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
int lawn[128][128];
int Hmax[128];
int Vmax[128];
int main(){
	int T;
	cin >> T;
	for(int t=0;t<T;t++){
		int M, N;
		cin >> M >> N;
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				cin >> lawn[i][j];
			}
		}
		for(int i=0;i<M;i++){
			Hmax[i] = 0;
			for(int j=0;j<N;j++){
				Hmax[i] = max(Hmax[i], lawn[i][j]);
			}
		}
		for(int j=0;j<N;j++){
			Vmax[j] = 0;
			for(int i=0;i<M;i++){
				Vmax[j] = max(Vmax[j], lawn[i][j]);
			}
		}
		bool answer = true;
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				answer &= (lawn[i][j] == min(Hmax[i], Vmax[j]));
			}
		}
		if(answer){
			cout << "Case #" << (t+1) << ": YES" << endl;
		} else {
			cout << "Case #" << (t+1) << ": NO" << endl;
		}
	}
	return 0;
}
