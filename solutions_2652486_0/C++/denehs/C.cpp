#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>

#define RUN 100

using namespace std;

int R, N, M, K;

void solve () {
	int value[20];
	int p[20];

	for (int i=0; i<K; i++)
		cin >> p[i];

	vector <int> data;

	for (int i=2; i<=M; i++) {
		for (int j=0; j<K; j++) {
			if (p[j]%i==0)
				data.push_back (i);
		}
	}

	int c[20];

	for (int i=2; i<=M; i++) {
		for (int j=2; j<=M; j++) {
			for (int k=2; k<=M; k++) {
				c[0] = i;
				c[1] = j;
				c[2] = k;

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
