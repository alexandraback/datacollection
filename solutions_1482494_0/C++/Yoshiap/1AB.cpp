#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ofstream fout ("1AB.out");
    ifstream fin ("1AB.in");
	int T;
	fin >> T;
	for (int t = 1; t <= T; t++) {
		vector<pair<int,int> > ones;
		vector<int> twos;
		int N;
		fin >> N;
		for (int i = 0; i < N; i++) {
			int a,b;
			fin >> a >> b;
			ones.push_back(make_pair(a,b));
		}
		int ans = 0;
		int count = 0;
		bool fail = false;
		while (!ones.empty() || !twos.empty()) {
			ans++;
			if (!twos.empty()) {
				bool found = false;
				for (int i = 0; i < twos.size(); i++) {
					if (twos[i] <= count) {
						found = true;
						twos.erase(twos.begin()+i);
						count++;
						break;
					}
				}
				if (found) continue;
			}
			if (!ones.empty()) {
				bool one = false,two = false;
				int oneindex = -1,onemax = -1;
				for (int i = 0; i < ones.size(); i++) {
					if (ones[i].second <= count) {
						two = true;
						ones.erase(ones.begin()+i);
						count += 2;
						break;
					}
					else if (ones[i].first <= count) {
						one = true;
						if (ones[i].second > onemax) {
							onemax = ones[i].second;
							oneindex = i;
						}
					}
				}
				if (one && !two) {
					twos.push_back(ones[oneindex].second);
					ones.erase(ones.begin()+oneindex);
					count++;
				}
				if (one || two) continue;
			}
			fail = true;
			break;
		}
		if (fail) fout << "Case #" << t << ": Too Bad" << endl;
		else fout << "Case #" << t << ": " << ans << endl;
	}
    return 0;
}