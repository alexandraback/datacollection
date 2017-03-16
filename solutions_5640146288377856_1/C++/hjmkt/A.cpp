#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include <functional>

#define rep(i,n) for(long i=0;i<n;i++)

using namespace std;


ifstream ifs;
ofstream ofs;
string buf;

int log2(int n){
	int level = 0;
	while(n >>= 1){
		level++;
	}
	return level;
}

int main(int argc, char **argv){
    ifs.open("A-large.in");
    ofs.open("A-large.out");
    
	int T = 0;
    ifs >> T;

	rep(i, T){
        ofs << "Case #" << i + 1 << ": ";

		int R, C, W;
		ifs >> R >> C >> W;

		int rowMin = (C - W) / W + 1;
		int lastRowRem = (C - W + 1) - (rowMin - 1) * W;
		int res = R * rowMin + W;
		if(lastRowRem == 1 || W == C){
			res--;
		}
		

		ofs << res << endl;
	}
	

    ifs.close();
    ofs.close();
    return 0;
}
