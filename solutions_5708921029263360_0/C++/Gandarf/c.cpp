#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;
#define M 3
int testn;
int j, p, s, k;
int res[100000][3];
int jps[M+1][M+1][M+1];
int jp[M+1][M+1], ps[M+1][M+1], js[M+1][M+1];

int main()
{
	ifstream in("C-small-attempt0.in");
	//ifstream in("input.txt");
	ofstream out("output.txt");

	in >> testn;
	for (int test = 1; test <= testn; ++test) 
	{
		in >> j >> p >> s >> k;

		for (int i = 0; i <= M; ++i)
			for (int j = 0; j <= M; ++j)
				for (int k = 0; k <= M; ++k)
					jps[i][j][k] = 0;
		for (int i = 0; i <= M; ++i)
			for (int j = 0; j <= M; ++j)
				jp[i][j] = ps[i][j] = js[i][j] = 0;
		
		// process
		int cnt = 0;
		for (int kk = 1; kk <= k; ++kk)
		{
			for (int a = 0; a < j; a++)
				for (int b = 0; b < p; b++)
					for (int c = 0; c < s; c++)
					{
						if (jp[a][b] < kk && ps[b][c] < kk && js[a][c] < kk && jps[a][b][c] <= 0)
						{
							jp[a][b]++;
							ps[b][c]++;
							js[a][c]++;
							jps[a][b][c]++;
							res[cnt][0] = a+1;
							res[cnt][1] = b+1;
							res[cnt][2] = c+1;
							cnt++;
						}
					}
		}

		out << "Case #" << test << ": " << cnt << endl;
		for (int i = 0; i < cnt; ++i)
		{
			out << res[i][0] << " " << res[i][1] << " " << res[i][2] << endl;
		}
	}

	in.close();
	out.close();
	return 0;
}