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
	ifstream ifs;
	ofstream ofs;
	ifs.open("A-small-attempt1.in");
	ofs.open("output2.txt");
	
    long long int T,R,C,W;
    ifs >> T;
    for(int i=0;i<T;++i){
        ifs >> R >> C >> W;
        ofs << "Case #" << i+1 << ": " << (R*(C-1))/W+W << endl;
    }

	ifs.close();
	ofs.close();
 
	return 0;
}