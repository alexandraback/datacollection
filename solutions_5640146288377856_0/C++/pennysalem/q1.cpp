#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main(){

	int T, R, C, W;
	int count;
	vector<vector<int>> vec;
	//build vector
	for(int i=1; i<=10+10; i++){
		vector<int> temp;
		temp.resize(i);
		vec.push_back(temp);
	}
	//print vector
	// for(int i=0; i<10; i++){
	// 	for(int j=0; j<vec[i].size(); j++){
	// 		cout << vec[i][j] << " ";
	// 	} cout << "\n";
	// }

	// for(int c=1; c<=10; c++){
	// 	for(int w=1; w<=c; w++){
	// 		int numPoss = c+1-w;
	// 		int numToHit = ceil(numPoss/w);
	// 		if(numPoss % w == 1){
	// 			vec[c].push_back(numToHit + w);
	// 		} else{
	// 			vec[c].push_back(numToHit + w);
	// 		}
	// 	}
	// }

	for(int i=0; i<10; i++){
		vec[i][i] = i+1;
		for(int j=0; j<i+1; j++){
			vec[i+j+1][i] = i+2;
		}
		// for(int j=0; j<10; j++){
		// 	vec[j][i] = vec[j-i][i]+1;
		// }
	}
	for(int i=0; i<10; i++){
		vec[i][0] = i+1;
	}
	vec[4][1] = 4;
	vec[5][1] = 4;
	vec[6][1] = 5;
	vec[7][1] = 5;
	vec[8][1] = 6;
	vec[9][1] = 6;
	vec[6][2] = 5;
	vec[7][2] = 5;
	vec[8][2] = 5;
	vec[9][2] = 6;
	vec[8][3] = 6;
	vec[9][3] = 6;
	
	//didin't have enough time to code it up

	// return 0;

	//print vector
	// for(int i=0; i<10; i++){
	// 	for(int j=0; j<vec[i].size(); j++){
	// 		cout << vec[i][j] << " ";
	// 	} cout << "\n";
	// }

	cin >> T;
	for(int i=0; i<T; i++){
		cin >> R >> C >> W;
		//R is always 1 in small dataset
		count = 0;

		count = vec[C-1][W-1];

		cout << "Case #" << (i+1) << ": " << count << "\n";
	} //for T
	
	return 0;
}