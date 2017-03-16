#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXP 1005

int outb(vector<int> b) {
	int n = b.size();
	for (int i = 0; i < n; i++) {
		cout << b[i] << '\t';
	}
	cout << endl;
	return 0;
}

int solve(vector<int> a) {
	int nd = a.size();
	vector<int> b(MAXP, 0);
	for (int i = 0; i < nd; i++) {
		b[a[i]]++;
	}
	int last_i = 0;
	int nb = b.size();
	for (int i = nb - 1; i > 0; i--) {
		if (b[i] != 0) {
			last_i = i;
			break;
		}
	}
	//outb(b);
	int best_t = last_i;
	int t;
	//cout << "last_i " <<  last_i << endl;
	for (int i = 1; i < last_i; i++) {
		if (b[i + 1] > b[i])
			continue;
		t = i;
		for (int j = i + 1; j <= last_i; j++) {
			if (b[j] == 0) 
				continue;
			t += (j - 1) / i * b[j];
		}
		if (t < best_t) {
			best_t = t;
		}
	//	cout << i << " | " << t << endl;
	}
	return best_t;
}

int main() {
	int nt;
	cin >> nt;
	int d;
	for (int i = 0; i < nt; i++) {
		cin >> d;	
		vector<int> a(d);
		for (int j = 0; j < d; j++) {
			cin >> a[j];
//			cout << a[j] << " ";
		}
		cout << "Case #" << i + 1 << ": " << solve(a) << endl;
		//cout << "------------" << endl;
	}
	return 0;
}
