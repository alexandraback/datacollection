#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <bitset>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

int main(){
	int T;
	cin >> T;

	for (int testcase = 0; testcase < T; testcase++){
		string C, J;
		cin >> C >> J;

		int cc, jj, diff = INT_MAX;
		for (int i = 0; i < pow(10, C.size()); i++)
			for (int j = 0; j < pow(10, J.size()); j++){
				bool ok = true;
				for (int k = 0; k < C.size(); k++)
					if (C[k] != '?' && C[k] - '0' != (i / (int)pow(10, C.size() - 1- k) % 10))
						ok = false;
				for (int k = 0; k < J.size(); k++)
					if (J[k] != '?' && J[k] - '0' != (j / (int)pow(10, J.size() - 1- k) % 10))
						ok = false;
				if (ok){
					if (abs(i - j) < diff || (abs(i - j) == diff && i < cc) || (abs(i - j) == diff && i == cc && j < jj)){
						cc = i;
						jj = j;
						diff = abs(i - j);
					}
				}
			}
		printf("Case #%d: %0*d %0*d\n", testcase + 1, C.size(), cc, J.size(), jj);
	}
	
	return 0;
}
