#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

float Naomi[1000];
float Ken[1000];

int N, T;

int war() {
	int left = 0, right = N-1, result = 0;
	for (int i = N-1; i >= 0; i--) {
		if (Naomi[i] > Ken[right]) {
			result++;
			left++;
		} else {
			right--;
		}
	}
	return result;
}

int deceitfullwar() {
	int left = 0, right = N-1, result = 0;
	for (int i = 0; i < N; i++) {
		if (Naomi[i] > Ken[left]) {
			result++;
			left++;
		} else {
			right++;
		}
	}
	return result;
}

int main(){
	ifstream ifs("inputD.txt");
	if (ifs.is_open()) {
		ofstream ofs("outputD.txt");
		if (ofs.is_open()) {
			ifs >> T;
			for (int i = 1; i <= T; i++) {
				ifs >> N;
				for (int j = 0; j < N; j++)
					ifs >> Naomi[j];
				for (int j = 0; j < N; j++)
					ifs >> Ken[j];
				sort(begin(Naomi), begin(Naomi)+N);
				sort(begin(Ken), begin(Ken)+N);
				ofs << "Case #" << i <<": " << deceitfullwar() << " " << war() << endl;
			}		
			ofs.close();
		}
		ofs.close();
	}
	return 0;
}
