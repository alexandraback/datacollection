#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int y = 1; y <= t; y++){
		cout << "Case #" << y << ": ";
		int N;
		cin >> N;
		vector<pair<string, string>> data;
		data.assign(N, pair<string, string>());
		map<string, int> first, second;
		for (int i = 0; i < N; i++){
			cin >> data[i].first >> data[i].second;
			auto it = first.find(data[i].first);
			if (it == first.end()){
				first.insert(pair<string, int>(data[i].first, 1));
			}
			else{
				it->second++;
			}
			it = second.find(data[i].second);
			if (it == second.end()){
				second.insert(pair<string, int>(data[i].second, 1));
			}
			else{
				it->second++;
			}
		}
		int ans = 0;
		for (auto it = first.begin(); it != first.end();it++){
			if (it->second > 1){
				ans++;
			}
		}
		cout <<ans;

		cout << endl;
	}
}