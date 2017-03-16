#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

#define EPS 1e-6

bool cmpd(pair<int, double> a, pair<int, double> b) {
	return a.second < b.second;
}

bool cmpi(pair<int, double> a, pair<int, double> b) {
	return a.first < b.first;
}


void once() {
	int n;
	vector<pair<int, double> > scores;
	vector<double> answ;
	double total;
	cin >> n;
	scores.resize(n);
	answ.resize(n);

	for(int i = 0; i < n; i++) {
		cin >> scores[i].second;
		total += scores[i].second;
		scores[i].first = i;
	}

//	sort(scores.begin(), scores.end(), cmpd);
	
	for(int i = 0; i < n; i++) {
		double l = 0.0, r = 100.0, m;		
		while((r - l) > EPS) {
			m = (r + l) / 2.0;
			double got = scores[i].second + (total * m / 100.0);
			double rem = 100.0 - m;
			for(int j = 0; j < n; j++)
				if(j != i && scores[j].second < got)
					rem -= 100.0 * (got - scores[j].second) / total;
			if(rem < 0.0)
				r = m;
			else 
				l = m;
		}
		answ[scores[i].first] = (r + l) / 2.0;
	}
	
	for(int i = 0; i < n; i++)
		printf("%.6lf ", answ[i]);
	
}

int main() {
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		once();
		cout << endl;
	}
	return 0;
}