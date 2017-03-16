#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;

int returnActions(int stackSize, int currentJ){
	float a = currentJ;
	float b = stackSize;
	return ceil(b/a)-1;
}

int main(){
	int SmallMAX = 9;
	int MAX = 1000;
	int bestScore = 1000, current;
	
	int T, D, temp;
	vector<int> P;

	//input
	cin >> T;
	for (int i = 0 ; i < T; i++){
		bestScore = 1000;
		cin >> D;
		for (int j = 0; j < D; j++){
			cin >> temp;
			P.push_back(temp);
		}
		//simulation at each level
		int maxElement = *max_element(P.begin(), P.end());
		for (int j = 1 ; j <= maxElement; j++){
			//determine whether or not to div this pancake pillar (has to be greater than the level)
			//if div, div by j, ceiling, -1, add to current
			current = 0;
			for (int k = 0; k < P.size(); k++){
				if (P[k]>j) {
					current+= returnActions(P[k],j);
				}
				if (current >= 1000) break;
			}
			current+=j;
			if (current <= bestScore) bestScore = current;
		}
		P.clear();
		cout << "Case #" << i+1 << ": " << bestScore <<endl;
	}
	return 0;
}
