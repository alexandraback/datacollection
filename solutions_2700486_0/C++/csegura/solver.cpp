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

int cases;
int success;
int N, X, Y;
int currentStop[50000];

void checkAll(int current){
	//Fall in (25, infinity)
	if (current == N){
		/*cout << "FIN" << endl;
		for (int i = 25000 - 10; i <= 25010; i++){
			cout << currentStop[i] << " ";
		}
		cout << endl;*/
		cases++;
		if (currentStop[X] > Y){
			success++;
		}
		return;
	}

	//Check if can go to left and right
	int currentHorizontal = 25000;
	bool canGoLeft = false;
	if (currentStop[currentHorizontal-1] + 1 == currentStop[currentHorizontal]){
		canGoLeft = true;
	} else {
		canGoLeft = false;
	}
	bool canGoRight = false;

	if (currentStop[currentHorizontal+1] + 1 == currentStop[currentHorizontal]){
		canGoRight = true;
	} else {
		canGoRight = false;
	}


	//Going to left
	currentHorizontal = 25000;
	bool moved = false;
	if (canGoLeft){
		while (true){
			if (currentStop[currentHorizontal] == -1){
				if (moved){
					currentStop[currentHorizontal] += 2;
					int prev1 = currentStop[currentHorizontal+1];
					int prev2 = currentStop[currentHorizontal-1];
					currentStop[currentHorizontal+1] = max(currentStop[currentHorizontal+1], currentStop[currentHorizontal] - 1); 
					currentStop[currentHorizontal-1] = max(currentStop[currentHorizontal-1], currentStop[currentHorizontal] - 1); 
					checkAll(current+1);
					if (!canGoRight){
						checkAll(current+1);
					}
					currentStop[currentHorizontal] -= 2;
					currentStop[currentHorizontal+1] = prev1;
					currentStop[currentHorizontal-1] = prev2;
				}
				break;
			} else if (currentStop[currentHorizontal-1] + 1 == currentStop[currentHorizontal]){
					moved = true;
					currentHorizontal--;
			} else if ((currentStop[currentHorizontal-1] >= currentStop[currentHorizontal]) && (currentStop[currentHorizontal+1] >= currentStop[currentHorizontal])){//Blocked
				if (moved){
					currentStop[currentHorizontal] += 2;
					int prev1 = currentStop[currentHorizontal+1];
					int prev2 = currentStop[currentHorizontal-1];
					currentStop[currentHorizontal+1] = max(currentStop[currentHorizontal+1], currentStop[currentHorizontal] - 1); 
					currentStop[currentHorizontal-1] = max(currentStop[currentHorizontal-1], currentStop[currentHorizontal] - 1); 
					checkAll(current+1);
					if (!canGoRight){
						checkAll(current+1);
					}
					currentStop[currentHorizontal] -= 2;
					currentStop[currentHorizontal+1] = prev1;
					currentStop[currentHorizontal-1] = prev2;
				}
				break;
			} else {//Can't move
				break;
			}
		}
	}

	//Going to right
	currentHorizontal = 25000;
	moved = false;
	if (canGoRight){
		while (true){
			if (currentStop[currentHorizontal] == -1){
				if (moved){
					currentStop[currentHorizontal] += 2;
					int prev1 = currentStop[currentHorizontal+1];
					int prev2 = currentStop[currentHorizontal-1];
					currentStop[currentHorizontal+1] = max(currentStop[currentHorizontal+1], currentStop[currentHorizontal] - 1); 
					currentStop[currentHorizontal-1] = max(currentStop[currentHorizontal-1], currentStop[currentHorizontal] - 1); 
					checkAll(current+1);
					if (!canGoLeft){
						checkAll(current+1);
					}
					currentStop[currentHorizontal] -= 2;
					currentStop[currentHorizontal+1] = prev1;
					currentStop[currentHorizontal-1] = prev2;
				}
				break;
			} else if (currentStop[currentHorizontal+1] + 1 == currentStop[currentHorizontal]){
					moved = true;
					currentHorizontal++;
			} else if ((currentStop[currentHorizontal-1] >= currentStop[currentHorizontal]) && (currentStop[currentHorizontal+1] >= currentStop[currentHorizontal])){//Blocked
				if (moved){
					currentStop[currentHorizontal] += 2;
					int prev1 = currentStop[currentHorizontal+1];
					int prev2 = currentStop[currentHorizontal-1];
					currentStop[currentHorizontal+1] = max(currentStop[currentHorizontal+1], currentStop[currentHorizontal] - 1); 
					currentStop[currentHorizontal-1] = max(currentStop[currentHorizontal-1], currentStop[currentHorizontal] - 1); 
					checkAll(current+1);
					if (!canGoLeft){
						checkAll(current+1);
					}
					currentStop[currentHorizontal] -= 2;
					currentStop[currentHorizontal+1] = prev1;
					currentStop[currentHorizontal-1] = prev2;
				}
				break;
			} else {
				break;
			}
		}
	}

	//Blocked
	currentHorizontal = 25000;
	if ((currentStop[currentHorizontal] <= currentStop[currentHorizontal-1]) && (currentStop[currentHorizontal] <= currentStop[currentHorizontal+1])){
		currentStop[currentHorizontal] += 2;
		int prev1 = currentStop[currentHorizontal+1];
		int prev2 = currentStop[currentHorizontal-1];
		currentStop[currentHorizontal+1] = max(currentStop[currentHorizontal+1], currentStop[currentHorizontal] - 1); 
		currentStop[currentHorizontal-1] = max(currentStop[currentHorizontal-1], currentStop[currentHorizontal] - 1); 
		checkAll(current+1);
		checkAll(current+1);
		currentStop[currentHorizontal] -= 2;
		currentStop[currentHorizontal+1] = prev1;
		currentStop[currentHorizontal-1] = prev2;
	}
}

int main(){
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		cases = 0;
		success = 0;
		for (int j = 0; j < 50000; j++){
			currentStop[j] = -1;
		}
		cin >> N >>  X >> Y;
		X += 25000;
		checkAll(0);
		cout << "Case #" << (i + 1) << ": " << (double)(success) / cases << endl;
	}
}
