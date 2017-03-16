#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100;
const int M = 100;
const double eps = 1e-9;

const int Diff = 50;
const double WarterDropRate = 10;
const int Remaining = 20;

struct Entry
{
	int r, c;
	double dist;
	bool operator<(Entry const& rhs) const
	{
		return dist > rhs.dist;
	}
};

double waterLevel;
int row, col;
int Ceil[N][M];
int Floor[N][M];
bool visited[N][M];
int Q[N * M][2];
int qe;
int Move[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
Entry heap[N * M * 4];
int nheap;
double dist[N][M];

void expand()
{
	memset(visited, 0, sizeof(*visited) * row);

	Q[0][0] = 0;
	Q[0][1] = 0;
	qe = 1;
	visited[0][0] = true;
	for (int q = 0; q < qe; q++)
	{
		int r = Q[q][0], c = Q[q][1];
		for (int i = 0; i < 4; i++)
		{
			int nr = r + Move[i][0];
			int nc = c + Move[i][1];
			if (nr < 0 || nr >= row || nc < 0 || nc >= col || visited[nr][nc]) continue;
			if (waterLevel < Ceil[nr][nc] - Diff + eps 
				&& Floor[r][c] <= Ceil[nr][nc] - Diff && 
				Floor[nr][nc] <= Ceil[nr][nc] - Diff && 
				Floor[nr][nc] <= Ceil[r][c] - Diff)
			{
				visited[nr][nc] = true;
				Q[qe][0] = nr;
				Q[qe][1] = nc;
				++qe;
			}
		}
	}
}

double shortestPath(int sr, int sc)
{
	memset(visited, 0, sizeof(*visited) * row);
	for (int i = 0; i < row; i++)
	for (int j = 0; j < col; j++)
		dist[i][j] = 1e100;
	heap[0].r = sr;
	heap[0].c = sc;
	heap[0].dist = 0;
	nheap = 1;
	dist[sr][sc] = 0;

	while (nheap > 0)
	{
		int r = heap[0].r, c = heap[0].c;
		double d = heap[0].dist;
		pop_heap(heap, heap + nheap--);

		if (r == row - 1 && c == col - 1)
		{
			return d;
		}

		if (visited[r][c]) continue;
		visited[r][c] = true;

		for (int i = 0; i < 4; i++)
		{
			int nr = r + Move[i][0];
			int nc = c + Move[i][1];

			if (nr < 0 || nr >= row || nc < 0 || nc >= col || visited[nr][nc]) continue;

			// hard constraints
			if (!(Floor[r][c] <= Ceil[nr][nc] - Diff && 
				Floor[nr][nc] <= Ceil[nr][nc] - Diff && 
				Floor[nr][nc] <= Ceil[r][c] - Diff))
				continue;

			double waitBeforeCanMove;
			double currentWaterLevel = waterLevel - WarterDropRate * d;
			if (currentWaterLevel < Ceil[nr][nc] - Diff + eps) 
				waitBeforeCanMove = 0;
			else
				waitBeforeCanMove = (currentWaterLevel - (Ceil[nr][nc] - Diff)) / WarterDropRate;

			double targetWaterLevel = currentWaterLevel - waitBeforeCanMove * WarterDropRate;

			double nd = d + waitBeforeCanMove;
			if (targetWaterLevel > Floor[r][c] + Remaining - eps)
				nd += 1;
			else
				nd += 10;

			if (nd < dist[nr][nc] - eps)
			{
				dist[nr][nc] = nd;
				heap[nheap].r = nr;
				heap[nheap].c = nc;
				heap[nheap].dist = nd;
				push_heap(heap, heap + ++nheap);
			}
		}
	}

	return 1e100;
}

void solve()
{
	expand();
	double answer = 1e100;
	for (int q = qe - 1; q >= 0; q--)
	{
		answer = min(answer, shortestPath(Q[q][0], Q[q][1]));
	}

	printf("%.7lf\n", answer);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		printf("Case #%d: ", t + 1);
		scanf("%lf %d %d", &waterLevel, &row, &col);
		for (int r = 0; r < row; r++)
		for (int c = 0; c < col; c++)
			scanf("%d", Ceil[r] + c);
		for (int r = 0; r < row; r++)
		for (int c = 0; c < col; c++)
			scanf("%d", Floor[r] + c);
		solve();
	}
}