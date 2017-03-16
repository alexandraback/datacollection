#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//#include <algorithm>
#include <set>

using namespace std;

int found = 0;
vector<long> values;
bool state[20];
ofstream fout ("1BC.out");
ifstream fin ("1BC.in");

void search(int tofind,int sum,int index) {
	if (found == 2) return;
	if (sum > tofind) return;
	if (sum == tofind) {
		bool first = true;
		for (int i = 0; i < values.size(); i++) {
			if (state[i]) {
				if (!first) fout << " ";
				else first = false;
				fout << values[i];
			}
		}
		found++;
		fout << endl;
		return;
	}
	if (index >= values.size()) return;
	search(tofind,sum,index+1);
	sum+=values[index];
	state[index] = true;
	search(tofind,sum,index+1);
	state[index] = false;
}
	
void find(int tofind) {
	for (int i = 0; i < 20; i++) state[i] = false;
	found = 0;
	search(tofind,0,0);
}

int main() {
	int T;
	fin >> T;
	for (int t = 1; t <= T; t++) {
		while (values.size() > 0) values.pop_back();
		set<long> sum;
		int N;
		sum.insert(0);
		fin >> N;
		for (int i = 0; i < N; i++) {
			values.push_back(0);
			fin >> values[i];
		}
		long tofind = -1;
		for (int i = 0; i < N; i++) {
			set<long>::iterator it;
			set<long> next;
			for (it = sum.begin(); it != sum.end(); it++) {
				int before = next.size();
				next.insert(*it);
				if (next.size()-before != 1) {
					tofind = *it;
					break;
				}
				next.insert(*it+values[i]);
				if (next.size()-before != 2) {
					tofind = *it+values[i];
					break;
				}
			}
			sum = next;
			if (tofind != -1) break;
		}
		fout << "Case #" << t << ":" << endl;
		find(tofind);
	}
    return 0;
}