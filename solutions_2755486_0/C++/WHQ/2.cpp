#include <iostream>

#include <cstring>

#include <string>

#include <cstdio>

#include <cmath>d

#include <fstream>

using namespace std;



int n, wall[5000], w[15], e[15], s[15], d[15], num[15], deltap[15], deltas[15], deltad[15];

int main() {

	freopen("fuck.in", "r", stdin);

	freopen("fuck.out", "w", stdout);

	int t;

	scanf("%d", &t);

	for (int l = 1; l <= t; l++) {

		cin >> n;

		memset(wall, 0, sizeof(wall));

		for (int i = 0; i < n; i++) {

			scanf("%d%d%d%d%d%d%d%d", &d[i], &num[i], &w[i], &e[i], &s[i], &deltad[i], &deltap[i], &deltas[i]);

			w[i] += 500;

			e[i] += 500;

		}

		int res = 0;

		for (int i = 0; i < 670000; i++) {

			int list[5000], delta[5000];

			list[0] = 0;

			for (int j = 0; j < n; j++) {

				if (d[j] == i && num[j] > 0) {

					bool cando = false;

					for (int k = w[j] + 1; k <= e[j]; k++) {

						if (wall[k] < s[j]) {

							list[0]++;

							list[list[0]] = k;

							delta[list[0]] = s[j];

							cando = true;

						}

					}

					if (cando) res++;

					d[j] += deltad[j];

					w[j] += deltap[j];

					e[j] += deltap[j];

					s[j] += deltas[j];

					num[j]--;

				}

			}

			for (int j = 1; j <= list[0]; j++) wall[list[j]] = max(wall[list[j]], delta[j]);

		}

		cout << "Case #" << l << ": " <<  res << "\n";

	}

	return 0;

}
