// Brute force... will only work for easy input

#include <bits/stdc++.h>
using namespace std;

int N;
int bf[20];

int ans;

int spot[20];
bool hit[20];

bool checkSpots(int d) {
	for (int i = 1; i <= d; i++) {
		int l = (i-2+d)%d + 1;
		int r = i%d + 1;
		if (!(spot[l] == bf[spot[i]] || spot[r] == bf[spot[i]]))
			return false;
	}
	return true;
}

void search(int d) {
	if (d > N)
		return;
	for (int i = 1; i <= N; i++) {
		if (!hit[i]) {
			spot[d] = i;
			hit[i] = 1;
			if (checkSpots(d)) {
				ans = max(ans, d);
			}
			search(d+1);
			hit[i] = 0;
		}
	}
}

int main() {
	int ncases;
	cin >> ncases;
	for (int icase = 1; icase <= ncases; icase++) {
		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> bf[i];
		
		ans = 0;
		search(1);
		
		cout << "Case #" << icase << ": " << ans << endl;
	}
	return 0;
}
