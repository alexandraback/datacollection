#include <iostream>
#include <queue>


using namespace std;

const int inf = 100000000;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

double CanGo(int F1, int C1, int F2, int C2, int H)
{
	if (C2 - F2 < 50)
		return -1;
	if (C2 - F1 < 50 || C1 - F2 < 50)
		return -1;
	if (C2 - H >= 50)
		return 0;
	return (50 - (C2 - H))/10.0;
}

void PrintResult(int testNo, double res)
{
	cout<<"Case #"<<testNo<<": "<<res<<endl;
}

void Process(vector<vector<int> >&C, vector<vector<int> >&F, vector<vector<double> >& A, int H, int i, int j)
{
	int N = C.size(), M = C[0].size();
	int F1 = F[i][j], C1 = C[i][j];
	for (int k = 0; k < 4; ++k)
	{
		int x = i + dx[k], y = j + dy[k];
		if (x < 0 || y < 0 || x >= N || y >= M)
			continue;
		int F2 = F[x][y], C2 = C[x][y];
		double wait = CanGo(F1, C1, F2, C2, H);
		if (wait < 0)
			continue;
		wait = max(wait, A[i][j]);
		double waterLevel = H - wait*10;
		double bt = 0;
		if (waterLevel >= F1 + 20)
			bt = wait + 1;
		else	
			bt = wait + 10;
		A[x][y] = min(A[x][y], bt);
	}
}

int main()
{
	int T;
	cin >> T;
	for (int z = 1; z <= T; ++z)
	{
		int H, N, M;
		cin >> H >> N >> M;
		vector<vector<int> >C(N, vector<int>(M));
		vector<vector<int> >F(N, vector<int>(M));
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				cin>>C[i][j];
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				cin>>F[i][j];
		
		vector<vector<double> > A(N, vector<double>(M, inf));		
		A[0][0] = 0;
		queue<pair<int, int> >Q;
		Q.push(make_pair(0, 0));
		while (!Q.empty())
		{
			pair<int, int> p = Q.front();
			Q.pop();
			int F1 = F[p.first][p.second], C1 = C[p.first][p.second];
			for (int k = 0; k < 4; ++k)
			{
				int x = p.first + dx[k], y = p.second + dy[k];
				if (x < 0 || y < 0 || x >= N || y >= M || A[x][y] < inf)
					continue;
				int F2 = F[x][y], C2 = C[x][y];
				if (CanGo(F1, C1, F2, C2, H) != 0)
					continue;
				A[x][y] = 0;
				Q.push(make_pair(x, y));
			}
		}
		if (A[N-1][M-1] == 0)
		{
			PrintResult(z, 0);
			continue;
		}
		
		vector<vector<bool> >used(N, vector<bool>(M, false));
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
			{
				if (A[i][j] > 0)
					continue;
				Process(C, F, A, H, i, j);
				used[i][j] = true;
			}

		while (A[N-1][M-1] == inf)
		{
			int bi = -1, bj = -1, best = inf;
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < M; ++j)
				{
					if (!used[i][j] && A[i][j] < best)
					{
						best = A[i][j];
						bi = i, bj = j;
					}
				}
			Process(C, F, A, H, bi, bj);
			used[bi][bj] = true;
		}

		PrintResult(z, A[N-1][M-1]);
	}


	return 0;
}

