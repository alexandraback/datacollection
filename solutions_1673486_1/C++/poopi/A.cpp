										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

ifstream fin ("A.in");
ofstream fout ("A.out");

#define cin fin
#define cout fout
#define int64 long long
#define P pair<int, int>

int n, m;
double p[100010];

int main(){
	int T, test = 0;
	for(cin >> T; T--; ){
		cin >> n >> m;
		double res = m + 2;
		for(int i = 0; i < n; i++){
			cin >> p[i];
			if(i > 0){
				p[i] *= p[i - 1];
				if(p[i] < 1e-15)
					p[i] = 0;
			}
			int bs = n - i - 1;
			int cnt = bs + m - n + bs + 1;
			double tmp = cnt + (1 - p[i]) * (m + 1);
			res = min(res, tmp);
		}
		cout.precision(6);
		cout.setf(ios::fixed | ios::showpoint);
		cout << "Case #" << ++test << ": " << res << endl;
	}
	return 0;
}
