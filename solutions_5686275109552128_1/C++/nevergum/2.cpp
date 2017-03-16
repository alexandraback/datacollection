#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>

#define N 1000

std::vector<int> a;
int dk[N+1][N+1];


void init_dk()
{
	const int n = a.size();
	
	for (int j = 0; j <= N; ++j) {
		dk[1][j] = (a[0] + j) / (j+1);
	}
	
	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j <= N; ++j) {
			dk[i][j] = -1;
		}
	}
}

int solve(int n, int k)
{
	if (dk[n][k] < 0) {
		int ans = a[n-1];
		for (int m = 1; m <=k; ++m) {
			int tmp = std::max((a[n-1] + m) / (m + 1), solve(n-1, k-m));
			ans = std::min(ans, tmp);
		}
		dk[n][k] = ans;
	}
		
	return dk[n][k];
}

int main()
{
	std::ifstream ifile("ifile");
	std::ofstream ofile("ofile");
	
	int T = 0;
	ifile >> T;
	
	for (int icase = 1; icase <= T; ++icase) {
		
		int D = 0;
		ifile >> D;
		
		a.clear();
		for (int i = 0; i < D; ++i) {
			int num = 0;
			ifile >> num;
			a.push_back(num);
		} 
		
		std::sort(a.begin(), a.end());
		
		init_dk();
		
		int ans = a.back();
		int split = 1;
		while(split < ans) {
			int tmp = solve(D, split);
			ans = std::min(tmp + split, ans);
			++split;
		}
		
		ofile << "Case #" << icase << ": " << ans << std::endl;
	}
//	system("pause");
}
