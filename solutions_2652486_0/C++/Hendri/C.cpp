#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

int T;
int R, N, M, K;
int prod[10];

int main() {
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		cout << "Case #" << tt << ":" << endl;
		cin >> R >> N >> M >> K;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < K; j++) {
				cin >> prod[j];
			}
			for (int a = 2; a <= M; a++) {
				for (int b = 2; b <= M; b++) {
					for (int c = 2; c <= M; c++) {
						set<int> pos;
						pos.insert(1);
						pos.insert(a);pos.insert(a*b);pos.insert(a*c);pos.insert(a*b*c);
						pos.insert(b);pos.insert(b*c);
						pos.insert(c);
						bool ok = true;
						for (int x = 0; x < K; x++) {
							if (pos.find(prod[x]) == pos.end()) {
								ok = false;
								break;
							}
						}
						if (ok) {
							cout << a << b << c << endl;
							goto next;
						}
					}
				}
			}
			for (int j = 0; j < K; j++) {
				cerr << prod[j] << " ";
			}
			cerr << endl;
			next:;
		}
	}
	return 0;
}
