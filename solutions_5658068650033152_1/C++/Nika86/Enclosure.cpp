#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>

#ifdef _WIN32
#define LL "%I64d"
#else
#define LL "%lld"
#endif

#define inp(x) scanf("%d",&x)
#define inpf(x) scanf("%f",&x)

using namespace std;

typedef long long int ll;
typedef long long unsigned int ull;

int main() {
	int T;
	int N,M,K;
	int minStones;
	int thisStones;
	int area;


	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> K;
		
		if (N <= 2 || M <= 2 || K <= 3) {
			cout << "Case #" << t << ": " << K << endl;
		} else {
			minStones = K;
			for (int h = 2; h <= N; h++) {
				for (int w = 2; w <= M; w++) {
					int cornerMult = 1;
					int numCorners = 0;

					thisStones = 2*h + 2*w - 4;
					area = h*w;

					while (area >= K) {
						if (thisStones <= minStones) {
							minStones = thisStones;
						}

						thisStones--;
						area -= cornerMult;
						numCorners++;
						if (numCorners == 4) {
							numCorners = 0;
							cornerMult++;
						}
					}
				}
			}

			cout << "Case #" << t << ": " << minStones << endl;
		}
	}

	return 0;
}
