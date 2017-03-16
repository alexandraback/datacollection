#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <limits>
#include <utility>
#include <functional>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cmath>
//#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
//using namespace boost::multiprecision;

enum POS{
	Begin,
	End,
	Both,
	Mid
};

static const long long MOD = 1000000007;

long long fact(int n){
	long long res = 1;
	for (int i = 2; i <= n; ++i){
		res = (res * i) % MOD;
	}
	return res;
}

void comp(int tc){
	int occ[26][4] = {};

	int n;
	cin >> n;
	vector<vector<int>> v(n);
	for (int i = 0; i < n; ++i){
		string s;
		cin >> s;
		char prev = '\0';
		for (char c : s){
			if (c != prev){
				v[i].push_back(c - 'a');
				prev = c;
			}
		}
	}

	bool ok = true;

	vector<int> both(26);
	vector<int> begin(26, -1);
	vector<int> end(26, -1);

	for (vector<int> &s : v){
		if (s.front() == s.back()){
			if (s.size() > 1){
				ok = false;
				break;
			}

			occ[s.front()][Both]++;
			both[s.front()]++;
		}
		else{
			occ[s.front()][Begin]++;
			occ[s.back()][End]++;

			begin[s.front()] = s.back();
			end[s.back()] = s.front();
		}
		
		for (int i = 1; i < (int)s.size() - 1; ++i){
			occ[s[i]][Mid]++;
		}
	}

	for (int i = 0; i < 26; ++i){
		if (occ[i][Begin] > 1 ||
			occ[i][End] > 1 ||
			occ[i][Mid] > 1 ||
			((occ[i][Begin] || occ[i][End] || occ[i][Both]) && occ[i][Mid])){
			ok = false;
			break;
		}
	}

	if (!ok){
		cout << "Case #" << tc << ": " << 0 << endl;
		return;
	}

	vector<long long> groups;
	bool flag[26] = {};
	for (int i = 0; i < 26; ++i){
		if (flag[i])
			continue;
		flag[i] = true;

		if (both[i] == 0 && begin[i] == -1 && end[i] == -1)
			continue;

		long long cur = fact(both[i]);
		int next = begin[i];
		while (next != -1){
			if (flag[next]){
				ok = false;
				break;
			}
			flag[next] = true;

			cur = (cur * fact(both[next])) % MOD;
			next = begin[next];
		}

		if (!ok)
			break;

		int prev = end[i];
		while (prev != -1){
			if (flag[prev]){
				ok = false;
				break;
			}
			flag[prev] = true;

			cur = (cur * fact(both[prev])) % MOD;
			prev = end[prev];
		}

		if (!ok)
			break;

		groups.push_back(cur);
	}

	if (!ok){
		cout << "Case #" << tc << ": " << 0 << endl;
		return;
	}

	long long f = fact((int)groups.size());
	for (long long ll : groups){
		f = (f * ll) % MOD;
	}

	cout << "Case #" << tc << ": " << f << endl;
}

int main(){
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc){
		comp(tc);
	}
}