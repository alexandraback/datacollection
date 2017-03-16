#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

int calc_dw_point(vector<double>&n, vector<double>&k);
int calc_w_point(vector<double>&n, vector<double>&k);

int main(){
	int T;
	cin >> T;
	for (int t=1;t<=T;++t){
		//Read input
		int N;
		cin >> N;
		vector<double> Naomi, Ken;
		for (int i=0;i<N;++i) {
			double temp;
			cin >> temp;
			Naomi.push_back(temp);
		}
		for (int i=0;i<N;++i) {
			double temp;
			cin >> temp;
			Ken.push_back(temp);
		}
		
		//Preprocess by sorting
		sort(Naomi.begin(), Naomi.end());
		sort(Ken.begin(), Ken.end());
		
		//Get the point
		int dw_point = calc_dw_point(Naomi, Ken);
		int w_point = calc_w_point(Naomi, Ken);
		
		//Output the result
		cout << "Case #" << t << ": " << dw_point << " " << w_point << endl;
	}
	
	return 0;
}

int calc_dw_point(vector<double>&n, vector<double>&k){
	int k_used[1001] = {0};
	int point = 0;
	for (int i=0;i<n.size();++i){
		double cur_n = n[i];
		double min_k = 1.0, max_k = 0;
		int min_k_index = 0, max_k_index = 0;
		for (int j=0;j<k.size();++j){
			if (k_used[j] == 0 && k[j] < min_k){
				min_k = k[j];
				min_k_index = j;
			}
			if (k_used[j] == 0 && k[j] > max_k){
				max_k = k[j];
				max_k_index = j;
			}
		} //for j
		if (cur_n < min_k) {
			k_used[max_k_index] = 1;
			continue;
		}
		else {
			k_used[min_k_index] = 1;
			point++;
			continue;
		}
	} //for i
	return point;
}

int calc_w_point(vector<double>&n, vector<double>&k) {
	int k_used[1001] = {0};
	int point = 0;
	for (int i=0;i<n.size();++i){
		double cur_n = n[i];
		//find the minimum k that is more than n[i] or just minimum k
		double min_k = 1.0, chosen_k = 1.1;
		int min_k_index = 0, chosen_k_index = -1;
		for (int j=0;j<k.size();++j){
			if(k_used[j] == 0 && k[j] < min_k){
				min_k = k[j];
				min_k_index = j;
			}
			if (k_used[j] == 0 && k[j] > cur_n && k[j] < chosen_k){
				chosen_k = k[j];
				chosen_k_index = j;
			}
		} // for j
		if (chosen_k_index == -1){
			//it means Ken don't have any larger box and he chose smallest box
			k_used[min_k_index] = 1;
			point++;
			continue;
		}
		else {
			k_used[chosen_k_index] = 1;
			continue;
		}
	} //for i
	return point;
}
