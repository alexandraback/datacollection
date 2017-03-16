#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
 
using namespace std;

int main() {
 
	int T, R, C, W;
	ifstream ifs;
	ofstream ofs;
	ifs.open("A-large.in");
	ofs.open("output.txt");
	ifs>>T;
	for (int i = 0; i<T; ++i){
		int ans = 0;
		ifs>>R>>C>>W;
 
		ans = C / W * R;
		ans += W - 1;

		if (C%W != 0)
			ans++;
		ofs << "Case #" << i + 1 << ": " << ans << endl;
	}

	ifs.close();
	ofs.close();
 
	return 0;
}

//(R*(C-1))/C+C