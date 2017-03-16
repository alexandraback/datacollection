#include <iostream>
#include <vector>
using namespace std;

void recur(vector<pair<int, int> > orig, vector<pair<int, int> > list, int &max, vector<pair<int, int> > &answer) {
	
	if (list.empty()) {
		for (int i = 0; i < orig.size(); i++) {
			vector<pair<int, int>>::iterator it = orig.begin() + i;
			pair<int, int> p = orig[i];
			list.push_back(p);
			vector<pair<int, int> > copy = orig;
			copy.erase(copy.begin() + (it - orig.begin()));
			recur(copy, list, max, answer);
			list.pop_back();
		}
		return;
	}

	pair<int, int> first = list.front(), last = list.back();

	if (list.size() > max) {
		bool big = true;
		for (int i = 0; i < list.size(); i++) {
			pair<int, int> p = list[i];
			pair<int, int> last = i > 0 ? list[i - 1] : list.back();
			pair<int, int> next = i < list.size() - 1 ? list[i + 1] : list.front();
			if (!(p.second == last.first || p.second == next.first)){
				big = false;
				break;
			}
		}
		if (big) {
			max = list.size();
			answer = list;
		}
	}
	
	for (vector<pair<int, int> >::iterator it = orig.begin(); it != orig.end(); it++) {
		int one = it->first, two = it->second;
		pair<int, int> p = *it;
		if (first.first == two || last.second == one || last.first == two || first.second == one) {
			list.push_back(p);
			vector<pair<int, int> > copy = orig;
			copy.erase(copy.begin()+(it-orig.begin()));
			recur(copy, list, max, answer);
			list.pop_back();
		}
	}
}

int main() {
	int t, n, temp;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		vector<pair<int, int> > v;
		for (int j = 1; j <= n; j++) {
			cin >> temp;
			v.push_back(make_pair(j,temp));
		}
		vector<pair<int, int> > list, answer;
		int max = 0;
		recur(v, list, max, answer);
		cout << "Case #" << i << ": " << max << endl;
	}

	return 0;
}