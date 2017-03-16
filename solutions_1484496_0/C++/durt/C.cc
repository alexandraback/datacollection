#include <iostream>
#include <algorithm>
using namespace std;

int N;
int a[1000];

struct SUBSET {
	int mask;
	int sum;
} subset[5000000];

bool comp(SUBSET a, SUBSET b) {
	return a.sum < b.sum;
}

int main() {
	int ncases;
	cin >> ncases;
	for (int icase = 1; icase <= ncases; icase++) {
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> a[i];
		cout << "Case #" << icase << ":" << endl;
		
		for (int s = 0; s < (1<<N); s++) {
			//compute sum, add to array
			int tmp = 0;
			for (int i = 0; i < N; i++)
				if (s & (1<<i))
					tmp += a[i];
			subset[s].mask = s;
			subset[s].sum = tmp;
		}
		
		sort(subset, subset + (1<<N), comp);
		
		bool impossible = true;
		for (int i = 1; i < (1<<N)-1; i++) {
			if (subset[i].sum == subset[i+1].sum) {
				impossible = false;
				int intersect = subset[i].mask & subset[i+1].mask;
				int l = subset[i].mask - intersect;
				int r = subset[i+1].mask - intersect;
				for (int j = 0; j < N; j++) {
					if (l & (1<<j))
						cout << a[j] << " ";
				}
				cout << endl;
				for (int j = 0; j < N; j++) {
					if (r & (1<<j))
						cout << a[j] << " ";
				}
				cout << endl;
				break;
			}
		}
		if (impossible)
			cout << "Impossible" << endl;
	}
	return 0;
}
