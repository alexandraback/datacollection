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

void comp(int tc){
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; ++i){
		string s;
		cin >> s;
		char prev = '\0';
		for (char c : s){
			if (c != prev){
				v[i] += c;
				prev = c;
			}
		}
	}
	
	int count = 0;
	vector<int> ind(n);
	for (int i = 0; i < n; ++i)
		ind[i] = i;

	do{
		bool flag[27] = {};

		string all;
		for (int curInd : ind)
			all += v[curInd];

		int prev = 26;
		bool ok = true;
		for (char c : all){
			int cur = c - 'a';
			if (cur != prev){
				if (flag[cur]){
					ok = false;
					break;
				}
				flag[cur] = true;
				prev = cur;
			}
		}

		if (ok)
			count = (count + 1) % 1000000007;
		
	} while (next_permutation(ind.begin(), ind.end()));

	cout << "Case #" << tc << ": " << count << endl;

}

int main(){
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc){
		comp(tc);
	}
}