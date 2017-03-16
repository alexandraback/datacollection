#include <iostream>
#include <vector>
#include <string>

using namespace std;

int factor(int x){
	if (x > 1)
		return x*factor(x - 1);
	return x;
}

int main(int argc, char** argv){
	int testCount;

	cin >> testCount;

	for (int i = 0; i < testCount; ++i){
		int result = 0;
		int carCount;
		cin >> carCount;
		int independantCars = carCount;
		vector<string> trainCars(carCount);
		for (int j = 0; j < carCount; ++j){
			cin >> trainCars[j];
		}
		for (int j = 0; j < 27 && result != -1; ++j){
			vector<string> sCars;
			char c = 'a' + j;
			for (int k = 0; k < carCount; ++k){
				for (int l = 0; l < trainCars[k].length(); ++l){
					if (trainCars[k][l] == c){
						sCars.push_back(trainCars[k]);
						break;
					}
				}
			}

			if (sCars.size() > 1){
				int swappable = 0;
				for (int k = 0; k < sCars.size(); ++k){
					char head = sCars[k][0];
					char tail = sCars[k][sCars[k].length() - 1];
					if ( head != c && tail != c){
						break;
						result = -1;
					}
					if (tail == c && head == c){
						++swappable;
					}
				}
				if (swappable > 1)
					result += factor(swappable);
				independantCars -= sCars.size()-1;
			}
		}
		result += factor(independantCars);
		if (result == -1) result = 0;
		cout << "Case #" << i + 1 << ": " << result << endl;
	}
}