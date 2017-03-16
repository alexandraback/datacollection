#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>
#include <unordered_map>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template<typename T>
ostream& operator<<(ostream& str, const vector<T>& v) {
	str << "[";
	for(auto n : v) {
		str << n << ", ";
	}
	str << "]";
	return str;
}

template<typename K, typename V>
ostream& operator<<(ostream& str, const unordered_map<K, V>& v) {
	str << "{";
	for(auto&& p : v) {
		str << p.first << " => " << p.second << ", ";
	}
	str << "}";
	return str;
}

int simulate_war( vector<double> naomi,  vector<double> ken) {
	sort(ken.begin(), ken.end());

	int score = 0;
	while(!naomi.empty()) {
		double n = naomi.back();
		naomi.pop_back();

		auto l = lower_bound(ken.begin(), ken.end(), n);
		if(l == ken.end()) l = ken.begin();



		if(*l < n) score++;

		


		ken.erase( l );
	}

	return score;
}

int simulate_deceit(vector<double> naomi, vector<double> ken) {
	auto kbeg = ken.begin();
	auto kend = ken.end()-1;

	//auto nend = naomi.end();
	int score = 0;

	while(!naomi.empty()) {
		double n = naomi.back();
		naomi.pop_back();

		//cout << *kend << ", "  << n << endl;

		if(*kend > n) {
			kbeg++;
		} else {
			kend--;
			score++;
		}
	}

	return score;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;

		vector<double> naomi(n), ken(n);
		for (int i = 0; i < n; ++i)
		{
		 	cin >> naomi.at(i);
		} 

		for (int i = 0; i < n; ++i)
		{
		 	cin >> ken.at(i);
		}


		sort(naomi.begin(), naomi.end(), greater<double>());
		sort(ken.begin(), ken.end(), greater<double>());

		int war_score = simulate_war(naomi, ken);
		int deceit_score = simulate_deceit(naomi, ken);

		cout << "Case #" << i+1 << ": " << deceit_score << " " << war_score << endl;
	}
}