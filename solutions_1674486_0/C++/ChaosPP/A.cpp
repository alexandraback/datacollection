#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int visited[10000];
int cnt[10000];

bool DFS(int start, vector< vector<int> > G)
{
	visited[start] = 1;

	for (int i=0; i<G[start].size(); i++) {
		int v = G[start][i];

		if (visited[v] > 0)
			return true;

		if (DFS(v, G) == true)
			return true;
	}

	visited[start] = 2;

	return false;
}

int main()
{
	FILE *fp = fopen("A-small-attempt2.in", "r");
	FILE *fout = fopen("output.txt", "w");

	int T;

	fscanf(fp, "%d", &T);
	for (int w=0; w<T; w++) {
		int N;

		fscanf(fp, "%d", &N);
		vector< vector< int > > G;
		G.clear();
		G.resize(N);

		for (int i=0; i<N; i++) {
			int K;
			int A;

			fscanf(fp, "%d", &K);
			for (int m=0; m<K; m++) {
				fscanf(fp, "%d", &A);
				G[i].push_back(A-1);
			}
		}

		bool flag = false;
		for (int i=0; i<N; i++) {
			for (int m=0; m<N; m++)
				visited[m] = 0;

			if (DFS(i, G) == true) {
				flag = true;
				break;
			}
		}
		if (flag == false)
			fprintf(fout, "Case #%d: No\n", w+1);
		else
			fprintf(fout, "Case #%d: Yes\n", w+1);
	}

	return 0;
}


/*
1. 비행기 이티켓 pdf  

2. 여권 사본(도장 찍혀 있는 부분)

3. 카드 매출 전표 pdf

4. 비행기 매출 전표 pdf
*/