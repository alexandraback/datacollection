#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n1, n2, n3, limit;
vector< vector<int> > answer;
vector< vector<int> > cur;
vector< vector<int> > c12, c13, c23;

void process(int v1, int v2, int v3) {
	if((n3 - v3) + (n2 - v2 - 1) * n3 + (n1 - v1 - 1) * n2 * n3 + cur.size() <= answer.size()) return;
	if(c12[v1][v2] + 1 <= limit && c13[v1][v3] + 1 <= limit && c23[v2][v3] + 1 <= limit) {
		vector<int> v;
		v.push_back(v1 + 1);
		v.push_back(v2 + 1);
		v.push_back(v3 + 1);

		cur.push_back(v);
		if(cur.size() > answer.size()) {
			answer = cur;
		}

		c12[v1][v2]++;
		c13[v1][v3]++;
		c23[v2][v3]++;

		if(v3 + 1 < n3) {
			process(v1, v2, v3 + 1);
		} else if(v2 + 1 < n2) {
			process(v1, v2 + 1, 0);
		} else if(v1 + 1 < n1) {
			process(v1 + 1, 0, 0);
		}

		cur.pop_back();
		c12[v1][v2]--;
		c13[v1][v3]--;
		c23[v2][v3]--;
	}

	if(v3 + 1 < n3) {
		process(v1, v2, v3 + 1);
	} else if(v2 + 1 < n2) {
		process(v1, v2 + 1, 0);
	} else if(v1 + 1 < n1) {
		process(v1 + 1, 0, 0);
	}
}

int main(int argc, char** argv) {
	int t;
	cin >> t;
	for(int iter = 0; iter < t; iter++) {
		cin >> n1 >> n2 >> n3 >> limit;

		answer.clear();
		cur.clear();
		c12.clear();
		c13.clear();
		c23.clear();

		c12.resize(n1);
		c13.resize(n1);
		c23.resize(n2);
		for(int i = 0; i < n1; i++) {
			c12[i].resize(n2);
			c13[i].resize(n3);
		}
		for(int i = 0; i < n2; i++) {
			c23[i].resize(n3);
		}
		process(0, 0, 0);
		cout << "Case #" << iter + 1 << ": " << answer.size() << endl;
		for(int i = 0; i < answer.size(); i++) {
			cout << answer[i][0] << " " << answer[i][1] << " " << answer[i][2] << endl;
		}
	}
	return 0;
}
