#include <cstring>
#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <stack>
#include <fstream>

using namespace std;

#define PQ priority_queue
typedef long long LL;
typedef pair<LL,LL> pll;

int main() {
	int T,K,C,S;
	ifstream file_in ("D-small-attempt0.in");
	ofstream file_out ("D-small.txt");
	file_in>> T;
	for (int i=1;i<=T;i++) {
		file_in >> K >> C >> S;
		file_out << "Case #" << i << ":";

		// x = ceiling(K/C)
		int x = (K+C-1)/C;
		if (x>S) file_out << " IMPOSSIBLE";
		else {
			LL powK[101];
			powK[0] = 1;
			for (int j=1;j<=(C-1);j++)
				powK[j] = powK[j-1]*K;
			for (int j=1;j<=x;j++) {
				// ((j-1)*C)*K^(C-1) + ((j-1)*C+1)*K^(C-2) + ... + ((j-1)*C+C-1)*K^(0)
				LL tmp = 0;
				for (int k=0;k<=min(C-1,K-1);k++)
					tmp += min((j-1)*C+k,(K-1))*powK[C-1-k];
				tmp++; // convert from 0 to 1 indexing
				file_out << " " << tmp;
			}
		}
		file_out << endl;
	}
	return 0;

}
