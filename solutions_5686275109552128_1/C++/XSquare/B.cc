#include <iostream>
#include <set>
#include <vector>

using namespace std;

int compute (vector <int> &v, int k){
	int n = v.size();
	int suma = 0;
	for (int i = 0; i < n; ++i){
		if (v[i]%k == 0) suma += v[i]/k-1;
		else suma += v[i]/k;
	}
	return suma+k;
}

int main(){
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t){
		int n;
		cin >> n;
		vector <int> v(n);
		int in = 1, en = 1;
		for (int i = 0; i < n; ++i){
			int a;
			cin >> a;
			en = max(en, a);
			v[i] = a;
		}
		int tt = 1239423;
		for (int i = 1; i <= en; ++i) tt = min(tt, compute(v, i));
		cout << "Case #" << t << ": " << tt << endl;
	}
}
