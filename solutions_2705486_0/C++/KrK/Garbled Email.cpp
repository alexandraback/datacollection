#include <fstream>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxw = 521200;
const int Maxn = 52;
const int Maxm = 5;

string w[Maxw];
int wlen;
int t;
string s;
int neigh[Maxn][Maxm][Maxn][Maxm];
int dp[Maxn][Maxm];

void Test(int p)
{
	for (int i = 0; i < wlen; i++) {
		int cnt = 0, firs, en, lst = p - 5;
		int j;
		for (j = 0; j < w[i].length() && p + j < s.length(); j++)
			if (s[p + j] != w[i][j])
				if (p + j - lst < 5) break;
				else {
					lst = p + j;
					if (cnt++ == 0) firs = j;
					en = j;
				}
		if (j < w[i].length()) continue;
		if (cnt == 0)
			for (int j = 0; j < Maxm; j++)
				neigh[p][j][p + w[i].length()][min(4, j + int(w[i].length()))] = 0;
		else {
			ii gt = ii(p + w[i].length(), min(4, int(w[i].length()) - 1 - en));
			for (int j = 0; j < Maxm; j++) 
				if (j + 1 + firs >= 5) neigh[p][j][gt.first][gt.second] = cnt;
		}
	}
}

int Get(int i, int j)
{
	if (i == s.length()) return 0;
	if (dp[i][j] == -1) {
		dp[i][j] = Inf;
		for (int k = 0; k < Maxn; k++)
			for (int l = 0; l < Maxm; l++)
				if (neigh[i][j][k][l] != -1) dp[i][j] = min(dp[i][j], Get(k, l) + neigh[i][j][k][l]);
	}
	return dp[i][j];
}

int main()
{
	ifstream dict("garbled_email_dictionary.txt");
	while (dict >> w[wlen]) wlen++;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin >> t;
	for (int tc = 1; tc <= t; tc++) {
		fin >> s;
		fill((int*)neigh, (int*)neigh + Maxn * Maxm * Maxn * Maxm, -1);
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < Maxm; j++) dp[i][j] = -1;
			Test(i);
		}
		fout << "Case #" << tc << ": " << Get(0, 4) << endl;
	}
	return 0;
}