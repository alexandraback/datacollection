#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>

using namespace std;


int B = 0;
int N,M,K;
int nbpierre;
int nbpierretemp;

void nextgrid(vector<vector<int > >& grid)
{
	int temp = N*M+1;
	while (temp > nbpierre & B < 1050000)
	{
		temp =0;
		B++;
		for (int i = 0; i < N*M; i += 1)
		{
			temp += (B>>i & 1);
		}
	}
	nbpierretemp = temp;
	for (int i = 0; i < N*M; i += 1)
	{
		grid[i/M][i%M] = (B>>i & 1);
	}
}

int result(vector<vector<int > > &grid)
{
	vector<vector<int > > mat(N,vector<int>(M,0));
	for (int i = 0; i < M; i += 1)
	{
		mat[0][i] = 1;
		mat[N-1][i] = 1;
	}
	for (int i = 0; i < N; i += 1)
	{
		mat[i][0] = 1;
		mat[i][M-1] = 1;
	}
	
	for (int i = 0; i < N; i += 1)
	{
		for (int j = 0; j < M; j += 1)
		{
			if (grid[i][j] == 1)
			{
				mat[i][j] =0;
			}
		}
	}
	
	for (int k = 0; k < 30; k += 1)
	{
		for (int i = 0; i < N; i += 1)
		{
			for (int j = 0; j < M; j += 1)
			{
				if (grid[i][j] == 0)
				{
					if (mat[max(0,i-1)][j] == 1)
					{
						mat[i][j] = 1;
					}
					if (mat[min(N-1,i+1)][j] == 1)
					{
						mat[i][j] = 1;
					}
					if (mat[i][max(0,j-1)] == 1)
					{
						mat[i][j] = 1;
					}
					if (mat[i][min(M-1,j+1)] == 1)
					{
						mat[i][j] = 1;
					}
				}
			}
		}
	}
	int res = 0;
	for (int i = 0; i < N; i += 1)
	{
		for (int j = 0; j < M; j += 1)
		{
			res += (0==mat[i][j]);
		}
	}
	return res;
}

int main (int argc, char* argv[])
{
	int T;
	cin >> T;
	for (int  cas = 0; cas < T; cas += 1)
	{
		B = 0;
		cout << "Case #" << cas+1 << ": ";
		cin >> N >> M >> K;
		vector<vector <int > > grid(N,(vector<int>(M,0)));
		int best = 0;		
		int temp;
		nbpierre = K;
		while (B < 1050000)
		{
			nextgrid(grid);
			temp = result(grid);
			if (temp == K)
			{
				nbpierre = nbpierretemp;
			}
		}
		cout << nbpierre << endl;
	}
	return 0;
}
