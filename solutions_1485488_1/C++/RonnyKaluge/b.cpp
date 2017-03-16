#include <iostream>
#include <stack>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

#define A first
#define B second

typedef struct
{
	int X, Y;
}
elmt;

double time_[100][100];
int C[100][100], F[100][100];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

class comp
{
	public:
	bool operator() (const elmt& a, const elmt& b) const
	{
		return time_[a.X][a.Y] > time_[b.X][b.Y];
	}
};

int main()
{
	priority_queue< elmt, vector<elmt>, comp > Q;
	int i, j, k, l, H, N, M, T;
	double h, temp1, temp2, temp3, res;
	elmt temp, temp_;
	cin >> T;
	for (int t=1; t<=T; ++t)
	{
		cin >> H >> N >> M;
		for (j=0; j<N; ++j)
			for (k=0; k<M; ++k)
			{
				scanf("%d", &F[j][k]);
				time_[j][k] = -1.0;
			}
		for (j=0; j<N; ++j)
			for (k=0; k<M; ++k)
				scanf("%d", &C[j][k]);
		temp.X = 0;
		temp.Y = 0;
		time_[0][0] = 0.0;
		Q.push(temp);
		res = -1;
		while (!Q.empty())
		{
			temp = Q.top();
			Q.pop();
			if (temp.X == N-1 && temp.Y == M-1)
			{
				res = time_[temp.X][temp.Y];
				while (!Q.empty())
					Q.pop();
			}
			else
			{
				for (i=0; i<4; ++i)
				{
					j = temp.X+dx[i];
					k = temp.Y+dy[i];
					if (j >= 0 && j <= N && k >= 0 && k <= M)
					{
						h = H-time_[temp.X][temp.Y]*10.0;
						temp1 = C[temp.X][temp.Y]+50;
						temp2 = C[j][k]+50;
						if (temp1 <= F[temp.X][temp.Y] && temp2 <= F[j][k] && temp2 <= F[temp.X][temp.Y] && temp1 <= F[j][k])
							if (h+50 <= F[temp.X][temp.Y] && h+50 <= F[j][k])
								if (time_[j][k] < 0 || time_[j][k] > temp3)
								{
									time_[j][k] = 0;
									temp_.X = j;
									temp_.Y = k;
									Q.push(temp_);
								}
					}
				}
			}
		}
		if (res < 0)
		{
			for (i=0; i<N; ++i)
				for (j=0; j<M; ++j)
					if (time_[i][j] >= 0)
					{
						temp.X = i;
						temp.Y = j;
						Q.push(temp);
					}
			while (!Q.empty())
			{
				temp = Q.top();
				Q.pop();
				if (temp.X == N-1 && temp.Y == M-1)
				{
					res = time_[temp.X][temp.Y];
					while (!Q.empty())
						Q.pop();
				}
				else
				{
					for (i=0; i<4; ++i)
					{
						j = temp.X+dx[i];
						k = temp.Y+dy[i];
						if (j >= 0 && j <= N && k >= 0 && k <= M)
						{
							h = H-time_[temp.X][temp.Y]*10.0;
							// if (h > C[temp.X][temp.Y])
								// temp1 = h+50;
							// else
							temp1 = C[temp.X][temp.Y]+50;
							// if (h > C[j][k])
								// temp2 = h+50;
							// else
							temp2 = C[j][k]+50;
							//cout << "X = " << j << " y = " << k << " " << h << " " << temp1 << " " << temp2 << " " << (temp1 <= F[temp.X][temp.Y] && temp2 <= F[j][k] && temp2 <= F[temp.X][temp.Y] && temp1 <= F[j][k]) << endl;
							if (temp1 <= F[temp.X][temp.Y] && temp2 <= F[j][k] && temp2 <= F[temp.X][temp.Y] && temp1 <= F[j][k])
							{
								if (h+50 <= F[temp.X][temp.Y] && h+50 <= F[j][k])
								{
									if (h-20 >= C[temp.X][temp.Y])
										temp3 = time_[temp.X][temp.Y]+1;
									else
										temp3 = time_[temp.X][temp.Y]+10;
									if (time_[j][k] < 0 || time_[j][k] > temp3)
									{
										time_[j][k] = temp3;
										temp_.X = j;
										temp_.Y = k;
										Q.push(temp_);
									}
								}
								else
								{
									if (F[j][k] > F[temp.X][temp.Y])
										l = F[temp.X][temp.Y];
									else
										l = F[j][k];
									temp3 = time_[temp.X][temp.Y] + (50-l+h)/10.0;
									h = H-temp3*10.0;
									if (h-20 >= C[temp.X][temp.Y])
										temp3 += 1;
									else
										temp3 += 10;
									if (time_[j][k] < 0 || time_[j][k] > temp3)
									{
										time_[j][k] = temp3;
										temp_.X = j;
										temp_.Y = k;
										Q.push(temp_);
									}
								}
							}
						}
					}
				}
			}
		}
		printf("Case #%d: %lf\n", t, res);
	}
	return 0;
}
