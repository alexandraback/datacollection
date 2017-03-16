#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <strings.h>
#include <stdlib.h>

using namespace std;

int E, R, N;
int values[10];
int maxGain = 0;

void solve(int n, int gain, int currentEnergy){
	if (n == N){
		maxGain = max(gain, maxGain);
		return;
	}
	for (int i = 0; i <= currentEnergy; i++){
		solve(n + 1, gain + values[n] * i, min(currentEnergy - i + R, E));
	}
}
	

int main(){
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		maxGain = 0;
		cin >> E >> R >> N;
		for (int j = 0; j < N; j++){
			cin >> values[j];
		}
		solve(0, 0, E);
		cout << "Case #" << (i + 1) << ": " << maxGain << endl; 
	}
}
