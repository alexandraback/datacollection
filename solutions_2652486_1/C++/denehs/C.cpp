#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>

#define RUN 10000

using namespace std;

int R, N, M, K;

void solve () {
	srand((unsigned)time(NULL));
	int value[20];
	int p[20];

	for (int i=0; i<K; i++)
		cin >> p[i];

	vector <int> data;

	for (int i=2; i<=M; i++) {
		for (int j=0; j<K; j++) {
			if (p[j]==1)
				continue;
			if (p[j]%i==0)
				data.push_back (i);
		}
	}

	int c[20];
	for (int run=0; run<RUN && data.size()>0; run++) {
		for (int i=0; i<N; i++) {
			c[i] = data[rand()%data.size()];
		}

		bool valid = true;
		for (int s=0; s<K; s++) {
			int t = p[s];
			for (int v=0; v<N; v++) {
				if (t%c[v]==0)
					t /= c[v];
			}
			if (t>1) {
				valid = false;
				break;
			}
		}

		if (valid) {
			for (int v=0; v<N; v++)
				cout << c[v];
			return;
		}
	}
	for (int v=0; v<N; v++)
		cout << 2;
}

int main () {
	int testcases;

	cin >> testcases;

	for (int testcase=1; testcase<=testcases; testcase++) {
		cout << "Case #" << testcase << ":" << endl;
		cin >> R >> N >> M >> K;

		for (int r=0; r<R; r++) {
			solve ();
			cout << endl;
		}

	}

	return 0;
}
