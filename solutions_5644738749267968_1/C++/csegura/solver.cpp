#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void load(vector<double> &data, int N){
	for (int j = 0; j < N; j++){
		double tmp;
		cin >> tmp;
		data.push_back(tmp);
	}
}

int main(){
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		int N;
		cin >> N;
		vector<double> data1, data2;
		load(data1, N);
		load(data2, N);
		sort(data1.begin(), data1.end());
		sort(data2.begin(), data2.end());
		vector<double> data2Copy = data2;
		//Simulate war
		int pointsWar = 0;
		for (int j = data1.size() - 1; j >= 0; j--){
			if (data2[0] > data1[j]){
				data2.erase(data2.begin());
			} else if (data2[data2.size()-1] < data1[j]){
				data2.erase(data2.begin());
				pointsWar++;
			} else {
				for (int k = data2.size() - 1; k >= 0; k--){
					if ((data2[k] > data1[j]) && (data2[k-1] < data1[j])){
						data2.erase(data2.begin() + k);
					}
				}
			}
		}
		data2 = data2Copy;
		//Simulate Deceitful War
		int pointsDeceitfulWar = 0;
		int firstAvailable = 0;
		int lastAvailable = data2.size() - 1;
		for (int j = 0; j < data1.size(); j++){
			if (data1[j] > data2[firstAvailable]){
				pointsDeceitfulWar++;
				firstAvailable++;
			} else {
				lastAvailable--;
			}
		}
		cout << "Case #" << (i + 1) << ": " << pointsDeceitfulWar << " " << pointsWar << endl; 
	}
}
