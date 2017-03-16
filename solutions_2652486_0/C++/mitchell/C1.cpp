#include <bitset>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <deque>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <complex>
#include <cstring>
#include <map>
#include <stack>
using namespace std;
int numways[64][126];
long long probs[64];
int nums[3];
int main(){
	for(int i=0;i<64;i++){
		nums[0] = 2 + (i % 4);
		nums[1] = 2 + ((i / 4) % 4);
		nums[2] = 2 + ((i / 16) % 4);
		for(int j=0;j<126;j++){
			numways[i][j] = 0;
		}
		for(int j=0;j<8;j++){
			int prod = 1;
			if(j % 2){
				prod *= nums[0];
			}
			if((j/2) % 2){
				prod *= nums[1];
			}
			if((j/4) % 2){
				prod *= nums[2];
			}
			numways[i][prod] ++;
		}
	}
	int T, R, N, M, K;
	cin >> T >> R >> N >> M >> K;
	cout << "Case #1\n";
	for(int i=0;i<R;i++){
		for(int k=0;k<64;k++){
			probs[k] = 1;
		}
		for(int j=0;j<K;j++){
			int prod;
			cin >> prod;
			for(int k=0;k<64;k++){
				probs[k] *= numways[k][prod];
			}
		}
		int maxindex = 0;
		for(int k=0;k<64;k++){
			if(probs[k] > probs[maxindex]){
				maxindex = k;
			}
		}
		cout << (2 + (maxindex % 4)) << "" <<  (2 + ((maxindex / 4) % 4)) << "" << (2 + ((maxindex / 16) % 4)) << endl;
	}
}
