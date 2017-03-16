#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

long long fact(long long n) {
	long long ret = 1;
	for (long long i = 2; i <= n; ++i){
		ret = (ret * i) % 1000000007;
	}
	return ret;
}

long long brut(vector<string>& v, vector<bool>& used, string& s) {
	// check s
	vector<char> lused(256, false);
	for (int i = 0; i < s.size(); ++i) {
		if (i > 0 && s[i] == s[i - 1]) continue;
		if (lused[s[i]]) return 0;
		lused[s[i]] = true;
	}
	bool last = true;
	long long ret = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (used[i]) continue;
		last = false;
		s += v[i];
		used[i] = true;
		ret += brut(v, used, s);
		used[i] = false;
		s.resize(s.size() - v[i].size());
	}
	if (last) return 1;
	return ret;
}

long long brut(vector<string>& v) {
	vector<bool> used(v.size(), false);
	string s;
	return brut(v, used, s);
}

int main() {
	int T;
	cin >> T;
	for (int q = 1; q <= T; ++q) {
		cerr << q << endl;
		int N;
		cin >> N;
		string s;
		vector<string> cars(N);
		vector<bool> disallowed(256, false);
		map<char, int> oneLetterCars;
		bool possible = true;
		set<string> carExists;
		vector<string> corg;
		for (int i = 0; i < N; ++i) {
			string& car = cars[i];
			cin >> car;
			corg.push_back(car);
			for (int j = 0; j + 1 < car.size(); ++j) {
				if (car[j] == car[j + 1]) {
					car.erase(car.begin() + j + 1);
					--j;
				}
			}
			for (auto& c : car) {
				if (c != car[0] && c != car.back()) {
					if (disallowed[c]) possible = false;
					disallowed[c] = true;
				}
			}
			if (disallowed[car[0]] || disallowed[car.back()]) possible = false;
			if (car.size() == 1) {
				car = car + car;
				carExists.insert(car); // not needed
				oneLetterCars[car[0]] ++;
				if (oneLetterCars[car[0]] > 1) {
					--N;
					--i;
					cars.resize(N);
				}
				continue;
			}
			if (carExists.find(car) != carExists.end()) possible = false;
			carExists.insert(car);
		}
		// merge
		for (int i = 0; possible && i < cars.size(); ++i) {
			for (int j = 0; j < cars.size(); ++j) {
				if (i == j) continue;
				if (cars[i][0] == cars[j].back()) {
					cars[j] += cars[i];
					auto& car = cars[j];
					{
						for (int j = 0; j + 1 < car.size(); ++j) {
							if (car[j] == car[j + 1]) {
								car.erase(car.begin() + j + 1);
								--j;
							}
						}
						if (car[0] == car.back() && car.size() > 2) possible = false;
						char c = cars[i][0];
						if (c != car[0] && c != car.back()) {
							if (disallowed[c]) possible = false;
							disallowed[c] = true;
						}
						if (disallowed[car[0]] || disallowed[car.back()]) possible = false;
					}
					cars.erase(cars.begin() + i);
					i = -1;
					break;
				}
			}
		}
		for (int i = 0; i < cars.size(); ++i) {
			if (cars[i][0] == cars[i].back()) continue;
			for (int j = i+1; j < cars.size(); ++j) {
				if (cars[j][0] == cars[j].back()) continue;
				if (cars[i][0] == cars[j][0] || cars[i].back() == cars[j].back()) possible = false;
			}
		}
		long long ans = 1;
		if (!possible) ans = 0;
		//for (int i = 1; i < cars.size(); ++i) ans = (ans * 2) % 1000000007;
		ans = (ans * fact(cars.size())) % 1000000007;
		for (auto& m : oneLetterCars) ans = (ans * fact(m.second)) % 1000000007;
		long long ansBrut = brut(corg);
if (ans != ansBrut) {
	cerr << "dupa " << q << ": " << ans << " vs " << ansBrut << endl;
	ans = ansBrut;
		}
		cout << "Case #" << q << ": " << ans << endl;
	}
	return 0;
}