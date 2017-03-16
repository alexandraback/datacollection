#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <cmath>
#include <cstdio>

using namespace std;

double H;
int N, M;

double C[100][100];
double F[100][100];

#define INF 999999999

void solve()
{
	double D[100][100];
	int dx[4] = {0, 0, -1, 1};
	int dy[4] = {-1, 1, 0, 0};
	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++) 
			D[i][j] = INF;
	
	D[0][0] = 0;
	
	int conti = 1;
	while (conti) {
		conti = 0;

		for (int i=0; i<N; i++)
			for (int j=0; j<M; j++) 
				for (int k=0; k<4; k++) {
					if (D[i][j] >= INF/10) continue;

					int next_i = i + dx[k];
					int next_j = j + dy[k];
					if (0<=next_i && next_i < N
						&& 0<=next_j && next_j < M) {
						
						double h = H;

						double c = C[i][j];
						double f = F[i][j];

						double next_c = max(H,C[next_i][next_j]);
						double next_f = max(H,F[next_i][next_j]);

						if (next_c - next_f < 50.0) continue;
						if (c - next_f < 50.0) continue;	
						if (next_c - f < 50.0) continue;

						D[next_i][next_j] = 0;
					}
				}

	}
//	cout << endl;
//	for (int i=0; i<N; i++) {
//		for (int j=0; j<M; j++) cout << D[i][j] << " ";
//		cout << endl;
//	}
	conti = 1;
	while (conti) {
		conti = 0;

		for (int i=0; i<N; i++)
			for (int j=0; j<M; j++) 
				for (int k=0; k<4; k++) {
					if (D[i][j] >= INF / 10) continue;
					int next_i = i + dx[k];
					int next_j = j + dy[k];
					if (0<=next_i && next_i < N
						&& 0<=next_j && next_j < M) {
						
						double h = H - D[i][j] * 10;

						double c = C[i][j];
						double f = F[i][j];

						double next_c = C[next_i][next_j];
						double next_f = F[next_i][next_j];

						double wait =0.0;
						if (next_c - next_f < 50.0) continue;
						if (c - next_f < 50.0) continue;	
						if (next_c - f < 50.0) continue;

						double cur_f = max(f, h);
						double cur_next_f = max(next_f, h);


						if (next_c - cur_next_f < 50.0) {
							wait = (50.0 - (next_c - cur_next_f)) / 10;
						}
						if (c - cur_next_f + wait*10 < 50.0) {
							wait = (50.0 - (c - cur_next_f)) /10;
						}
						if (next_c - cur_f + wait*10 < 50.0) {
							wait = (50.0 - (next_c - cur_f)) / 10;
						}

						double time = D[i][j] + wait;

						h = H - D[i][j]*10 - wait*10;
						double speed = 10;
						if (h - F[i][j] >= 20.0) speed = 1.0;
						else speed = 10.0;

						double tmp = D[i][j] + wait + speed;

						if (tmp < D[next_i][next_j]) {
							D[next_i][next_j] = tmp;
							conti = 1;
						}
					}
				}

	}

	//cout << D[N-1][M-1] << endl;
	printf("%.8f\n", D[N-1][M-1]);
}


int main()
{
	int case_num;
	cin >> case_num;

	for (int t=1; t<=case_num; t++) {
		// initialization, IO
		cin >> H >> N >> M;
		for (int i=0; i<N; i++)	
		for (int j=0; j<M; j++)
			cin >> C[i][j];

		for (int i=0; i<N; i++)	
		for (int j=0; j<M; j++)
			cin >> F[i][j];

		cout << "Case #" << t << ": ";
		solve();

	}
}
