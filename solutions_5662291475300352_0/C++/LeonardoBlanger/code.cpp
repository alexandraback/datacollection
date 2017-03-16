#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <stack>
#include <cstring>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;

#define INF (1 << 30)

int main(){
	freopen("C-small-1-attempt0.in", "r", stdin);
	freopen("output", "w", stdout);
	int tcase = 0;

	int T;
	scanf("%d", &T);

	while(T--){
		int N;
		scanf("%d", &N);

		vector<int> D, M;

		for(int i=0; i<N; i++){
			int d, h, m;
			scanf("%d%d%d", &d, &h, &m);

			for(int i=0; i<h; i++){
				D.push_back(d);
				M.push_back(m++);
			}
		}

		printf("Case #%d: ", ++tcase);

		if(D.size() < 2){
			printf("0\n");

		} else {
			if(M[0] < M[1]){
				swap(M[0], M[1]);
				swap(D[0], D[1]);
			}

			int S0 = D[0];
			double V0 = 360.0 / M[0];

			int S1 = D[1];
			double V1 = 360.0 / M[1];

			double t = (S1 - S0) / (V0 - V1);
			double pos = S0 + V0 * t;

			if(pos > 360){
				printf("0\n");

			} else {
				double t0 = (360 - pos) / V0;
				double P1 = V1 * t0;

				if(P1 >= 720 - pos){
					printf("1\n");
				} else {
					printf("0\n");
				}
			}
		}
	}
}