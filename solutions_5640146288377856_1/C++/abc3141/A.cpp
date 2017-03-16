#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int T;
int R, C, W;
//R=1‚Ì‰ð
int Ans[21][21];
int main()
{
	ifstream fin("C:/Users/Toshifumi/A-large.txt");
	ofstream fout("C:/Users/Toshifumi/out.txt");
	fin >> T;
	for (int i = 1; i <= 20; i++){
		for (int j = 1; j <= i; j++){
			Ans[i][j] = j + (i + j - 1) / j - 1;
		}
	}
	for (int Case = 1; Case <= T; Case++){
		fin >> R >> C >> W;
		int ans = 0;
		ans += (R - 1)*(C / W);
		ans += Ans[C][W];
		fout << "Case #" << Case << ": " << ans << "\n";
	}
	return 0;
}