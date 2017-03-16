#include <cstdlib>
#include <iostream>

using namespace std;

int queue[500000][2];

int main(int argc, char *argv[])
{
	int nC, cId;
	int C[100][100];
	int F[100][100];
	double dis[100][100];

	char inQueue[100][100];
	int head, tail;
	int vec[4][2] = { 
		{ 0, -1}, { 0, 1}, { 1, 0}, { -1, 0}
	};

	scanf("%d", &nC);
	for (cId = 1; cId <= nC; cId++)
	{
		int H, nRow, nCol;
		scanf("%d%d%d", &H, &nRow, &nCol);
		for (int i = 0; i < nRow; i++) {
		for (int j = 0; j < nCol; j++) {
			scanf("%d", &C[i][j]);
		}
		}
		for (int i = 0; i < nRow; i++) {
		for (int j = 0; j < nCol; j++) {
			scanf("%d", &F[i][j]);
		}
		}
		memset(dis, -1, sizeof(dis));
		for (int i = 0; i < nRow; i++) {
		for (int j = 0; j < nCol; j++) {
			dis[i][j] = -1;
		}
		}
		dis[0][0] = 0;
		head = 0;
		tail = 1;
		queue[0][0] = 0;
		queue[0][1] = 0;
		memset(inQueue, 0, sizeof(inQueue));
		inQueue[0][0] = 1;

		while(head < tail) {
			int r, c;
			r = queue[head][0];
			c = queue[head][1];
			inQueue[r][c] = 0;

			int newR, newC;
			for (int i = 0; i < 4; i++) {
				newR = r + vec[i][0];
				newC = c + vec[i][1];
				if (newR < 0 || newC < 0 || newR >= nRow || newC >= nCol) {
					continue;
				}

				if (F[newR][newC] > C[r][c] - 50 ||
					F[newR][newC] > C[newR][newC] - 50 ||
					F[r][c] > C[newR][newC] - 50) {
					continue;
				}

				double newTime = dis[r][c];
				if (C[newR][newC] - H < 50) {
					double timeWait = (H - (C[newR][newC] - 50)) / 10.0;
					if (timeWait > newTime) {
						newTime = timeWait;
					}
				}

				if (newTime > 0) {
					double waterAtCurrent = H - newTime * 10 - F[r][c];
					if (waterAtCurrent > 20 - 1e-6)
					{
						newTime = newTime + 1;
					}
					else
					{
						newTime = newTime + 10;
					}
				}
				if (dis[newR][newC] == -1 ||
					dis[newR][newC] > newTime) {
					dis[newR][newC] = newTime;
					if (!inQueue[newR][newC]) {
						inQueue[newR][newC] = 1;
						queue[tail][0] = newR;
						queue[tail][1] = newC;
						tail++;
					}
				}
			}

			head++;
		}
		double ans = dis[nRow-1][nCol-1];
		printf ("Case #%d: %f\n", cId, ans);
	}
    return EXIT_SUCCESS;
}
