#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
	int T;
	cin >> T;
	for (int k = 0; k < T; ++k){
		int N;
		cin >> N;
		vector<float> naomi;
		for (int i = 0; i < N; ++i){
			float v;
			cin >> v;
			naomi.push_back(v);
		}
		vector<float> ken;
		for (int i = 0; i < N; ++i){
			float v;
			cin >> v;
			ken.push_back(v);
		}
		sort(naomi.begin(), naomi.end());
		sort(ken.begin(), ken.end());
		vector<float> copyN = naomi;
		vector<float> copyK = ken;
		/*for (int i = 0; i < N; ++i){
			cout << naomi[i] << endl;
		}
		for (int i = 0; i < N; ++i){
			cout << ken[i] << endl;
		}*/
		int war = 0;
		for (int i = 0; i < N; ++i){
			if (copyN.back() > copyK.back()){
				war++;
				copyN.pop_back();
			} else {
				copyN.pop_back();
				copyK.pop_back();
			}
		}
		int dWar = 0;
		int j = 0;
		for (int i = 0; i < N; ++i){
			for (; j < (int)naomi.size(); ++j){
				if (naomi[j] > ken[i]){
					break;
				}
			}
			if (j < (int)naomi.size()){
				dWar ++;
			} else break;
			j++;
		}
		cout << "Case #" << k+1 << ": " << dWar << " " << war << endl;
		//printf("Case #%d: %.7lf\n", k+1, 0.0);
	}
	return 0;
}
