#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define INF 100000000

int wf[1000][1000], wf2[1000][1000];
int edge[1000][1000];

bool solve()
{
	int a, b, c, i, j, k, l, m, n, pt;
	cin >> n;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			edge[i][j] = INF;
	for(i = 0; i < n; i++) {
		cin >> m;
		for(j = 0; j < m; j++) {
			cin >> l;
			edge[i][l - 1] = 1;
		}
	}
	memcpy(wf, edge, sizeof(edge));
	for(i = 0; i < n; i++)
		wf[i][i] = 0;
	for(k = 0; k < n; k++)
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				wf[i][j] = min(wf[i][j], wf[i][k] + wf[k][j]);
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(i == j)
				continue;
			if(wf[i][j] < INF) {
				pt = j;
				while(true) {
					if(pt == i)
						break;
					for(k = 0; k < n; k++) {
						if(wf[i][k] + edge[k][pt] + wf[pt][j] == wf[i][j]) {
							edge[k][pt] = INF;
							memcpy(wf2, edge, sizeof(edge));
							for(a = 0; a < n; a++)
								wf2[a][a] = 0;
							for(a = 0; a < n; a++)
								for(b = 0; b < n; b++)
									for(c = 0; c < n; c++)
										wf2[b][c] = min(wf2[b][c], wf2[b][a] + wf2[a][c]);
							if(wf2[i][j] < INF)
								return true;
							edge[k][pt] = 1;
							pt = k;
							break;
						}
					}
				}
			}
		}
	}
	return false;
}

int main(void)
{
	int I, N;
	bool RES;
	cin >> N;
	for(I = 0; I < N; I++) {
		RES = solve();
		if(RES)
			cout << "Case #" << I + 1 << ": Yes" << endl;
		else
			cout << "Case #" << I + 1 << ": No" << endl;
	}
	return 0;
}
