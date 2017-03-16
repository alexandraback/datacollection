#include <bits/stdc++.h>
using namespace std;

int bc(int n)
{
	int c = 0;
	for (int i=1; i<=n; i<<=1)
		if (n & i) c++;
	return c;
}

int T, i, N;

int main() {
	cin >> T;
	for (int t=1; t<=T; t++) {
		cin >> N;
		vector <pair <string,string>> S(N);
		for (int i=0; i<N; i++)
			cin >> S[i].first >> S[i].second;

		cout << "Case #" << t << ": ";

		int worst = 0;
		for (int mask=0; mask<(1<<N); mask++) {
			int cur_bc = bc(mask);
			if (cur_bc > worst) {
				int cur = 0;
				for (int i=0; i<N; i++) if (mask & (1<<i)) {
					bool f=false, s=false;
					for (int j=0; j<N; j++) if ((mask & (1<<j)) == 0) {
						if (S[i].first == S[j].first) f = true;
						if (S[i].second == S[j].second) s = true;
					}
					if (f && s) cur++;
				}
				if (cur == cur_bc)
					worst = cur_bc;
			}
		}

		cout << worst << endl;
	}
}
