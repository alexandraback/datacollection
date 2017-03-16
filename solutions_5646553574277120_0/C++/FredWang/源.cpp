#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring> 
#include <algorithm>
using namespace std;
int n, m, T, dom[20], f[200];
int calc(){
	memset(f, 0, sizeof(f));
	f[0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = m; j >= dom[i]; --j)
			if(f[j - dom[i]] == 1)
				f[j] = 1;
	for (int i = 1; i <= m; ++i)
		if (!f[i])
			return i;
	return m + 1;
}
int main(){
	ifstream fin("C:\\Users\\ty\\Desktop\\codejam2015\\C-small-attempt3.in");
	ofstream fout("C:\\Users\\ty\\Desktop\\codejam2015\\B.txt");
	fin >> T;
	for (int tt = 1; tt <= T; ++tt){
		int c, ans = 0;
		fin >> c >> n >> m;
		for (int i = 1; i <= n; ++i)fin >> dom[i];
		while (calc() <= m){
			int max = calc();
			n++; ans++;
			dom[n] = max;
		}
		fout << "Case #" << tt << ": " << ans << endl;
	}
	fout.close();
	return 0;
}

