#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <strings.h>
#include <stdlib.h>
#include <math.h>
//#include "bigint/BigIntegerLibrary.hh"

using namespace std;

int main(){
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		long long currentSize;
		cin >> currentSize;
		int N;
		cin >> N;
		vector<int> motes;
		for (int j = 0; j < N; j++){
			int tmp;
			cin >> tmp;
			motes.push_back(tmp);
		}
		sort(motes.begin(), motes.end());
		int bestSolution = motes.size();//Remove all
		int currentCost = 0;
		if (currentSize == 1){
			cout << "Case #" << (i + 1) << ": " << motes.size() << endl; 
		} else {
			for (int j = 0; j < motes.size(); j++){
				if (motes[j] < currentSize){
					currentSize += motes[j];
				} else {
					//Option 1: remove remaining
					bestSolution = min(bestSolution, (int)(currentCost + motes.size() - j));
					//Option 2: add elements
					while(currentSize <= motes[j]){
						currentSize = currentSize + (currentSize - 1);
						currentCost++;
					}
					currentSize += motes[j];
				}
			}
			bestSolution = min(currentCost, bestSolution);
			cout << "Case #" << (i + 1) << ": " << bestSolution << endl; 
		}
	}
}
