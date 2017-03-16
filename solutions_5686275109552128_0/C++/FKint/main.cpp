#include <bits/stdc++.h>
#include <cstdio>
using namespace std;


int get_time(int maximal, vector<int> &v){
	int total = 0;
	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it){
		total += (*it - 1) / maximal;
	}
	return total;
}

int main(){
	std::ios::sync_with_stdio(false);
	int nb_testcases; cin >> nb_testcases;
	for(int current_testcase = 1; current_testcase <= nb_testcases; ++current_testcase){
		int D; cin >> D;
		vector<int> v;
		int heighest = 0;
		for(int i = 0; i < D; ++i){
			int t;
			cin >> t;
			v.push_back(t);
			heighest = max(heighest, t);
		}
		int best_time = heighest;
		for(int i = 1; i < heighest; ++i){
			int curr_time = get_time(i, v) + i;
			best_time = min(curr_time, best_time);
		}
		cout << "Case #" << current_testcase << ": " << best_time << endl;
	}
    return 0;
}
