#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct greater1
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};


int dwar(vector<double> &naomi, vector<double> &ken) {
	int n = naomi.size();
	int k = ken.size();
	--n;
	--k;
	int np = 0;
	while(n >= 0 and k >= 0) {
		if(naomi[n] > ken[k]) {
			--k;
			--n;
			++np;
		} else {
			--k;
		}
	}
	return np;
}

int war(vector<double> &naomi, vector<double> &ken) {
	int n = 0;
	int k = 0;
	int np = 0;
	while(n < naomi.size() and k < ken.size()) {
		if(naomi[n] > ken[k]) {
			++k;
			++np;
		} else {
			++n;
			++k;
		}
	}
	return np;
}


int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i) {
		int n; 
		cin >> n;
		vector<double> naomi(n);
		vector<double> ken(n);
		for(int j = 0; j < n; ++j) {
			cin >> naomi[j];
		}
		for(int j = 0; j < n; ++j) {
			cin >> ken[j];
		}
		sort(naomi.begin(), naomi.end());
		sort(ken.begin(), ken.end());
		cout << "Case #" << i+1 << ": ";
		cout << dwar(naomi,ken) << " " << war(naomi,ken) << endl;
	}
}