#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>
#include <utility>
#include <unordered_map>
#include <map>


typedef unsigned long long ull;
typedef long long ll;

const ll MOD = 1000000007;

using namespace std;

template<typename T>
ostream& operator<<(ostream& str, const vector<T>& v) {
	str << "[";
	for(auto n : v) {
		str << n << ", ";
	}
	str << "]";
	return str;
}

template<typename T>
ostream& operator<<(ostream& str, const set<T>& v) {
	str << "{";
	for(auto n : v) {
		str << n << ", ";
	}
	str << "}";
	return str;
}


ll factorial(ll n) {
	ll prod = 1;
	for(int i=2; i<=n; ++i) prod = (prod*i) % MOD;

	return prod;
}

int main() {
	int ncases;
	cin >> ncases;

	for(int c=1; c<=ncases; ++c) {
		ull count = 0;
		bool possible = true;

		set<char> starts, ends;
		//vector<string> words;

		map<char, vector<string>> words;

		int n;
		cin >> n;
		for(int i=0; i<n; ++i) {
			string car;
			cin >> car;
			words[car.front()].push_back(car);
			starts.insert(car.front());
			ends.insert(car.back());
		}

		//cout << starts << endl;
		//cout << ends << endl;
		vector<int> independent;

		for(auto& vs : words) {
			int same = 0;
			char other = -1;
			char cur = vs.first;
			
			for(auto w : vs.second) {
				char bk = w.back();
				if(other > 0 && other != cur && bk != cur) {
					//cout << "other > 0" << other << endl;
					possible = false;  goto impossible;
				} else if(other != cur) {
					other = bk;
				}

				int bef = true;
				for(int i=0; i<w.size(); ++i) {
					//cout << w.at(i) << " -> " << binary_search(starts.begin(), starts.end(), w.at(i)) << endl;

					if(bef && w.at(i) != cur) bef = false;
					if(!bef && w.at(i) != bk && (binary_search(starts.begin(), starts.end(), w.at(i)) || binary_search(ends.begin(), ends.end(), w.at(i)))) { 
						//cout << "!bef" << endl;
						possible = false;  goto impossible; 
					}
				}

				if(bef) ++same;
			}

			//cout << "other: " << other << endl;
			if(!binary_search(starts.begin(), starts.end(), other) || same == vs.second.size()) {
				int prod = 1;
				for(int i=0; i<same-1; ++i) prod = (2*prod) % MOD;

				independent.push_back(prod);
			}
		}

impossible:

		if(!possible)
			cout << "Case #" << c << ": 0" << endl;
		else {
			ll fact= factorial(independent.size());
			//cout << independent.size() << ", " << fact << endl;
			//cout << independent << endl;
			for(auto i: independent) fact = (fact*i) % MOD;
			cout << "Case #" << c << ": " << fact << endl;
		}
	}
}