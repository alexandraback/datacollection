#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

bool found=false;
vector<bool> met(1000, false);
vector< vector<int> > inc;

void print(vector<int> a) {
	cout << "<";
	for (int i=0; i<(int)a.size(); ++i)
		cout << a[i] << ",";
	cout << ">" << endl;
}

void rec(int start) {
	if (!found) for (int i=0; i<(int)inc[start].size(); ++i) {
		if (met[inc[start][i]])
			found=true;
		met[inc[start][i]]=true;
		rec(inc[start][i]);
	}
}

int main() {
	int N; cin >> N;
	for (int I=0; I<N; ++I) {
		cout << "Case #" << I+1 << ": ";

		found=false;
		inc.clear();

		int n; cin >> n;
		for (int i=0; i<n; ++i) {
			vector<int> a;
			int num; cin >> num;
			for (int j=0; j<num; ++j) {
				int read; cin >> read;
				a.push_back(read-1);
			}
			inc.push_back(a);
		}

		for (int i=0; i<n; ++i) {
			met.assign(1000, false);
			rec(i);
			if (found)
				break;
		}

		if (found) {
			cout << "Yes";
		} else {
			cout << "No";
		}

		cout << endl;
	}
}
