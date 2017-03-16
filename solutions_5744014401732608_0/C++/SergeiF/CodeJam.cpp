#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <random>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;
#define FOR(k,a,b) for(typeof(a) k=(a); k <= (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define REPD(k,a) for(int k=(a)-1; k >= 0; --k)
#define PB push_back 
#define MP make_pair

int main()
{
	int T;
	std::cin >> T;
	int matrix[51][51];
	for (int t = 0; t < T; ++t) {
		std::cout << "Case #" << (t + 1) << ": ";
		LL B, M;
		cin >> B >> M;
		vector<int> b2;
		auto m = M - 1;
		if (pow(2, B - 2) != M) m = m + 1;
		while (m > 0) {
			b2.push_back(m % 2);
			m = m / 2;
		}
		//1 0 1
		//1 2 3 ...
		int nn = b2.size();
		if (nn >= B - 1) {
			std::cout << "IMPOSSIBLE" << std::endl;
			continue;
		}
		//cout << "b2: " <<endl;
		//for (int i = 0; i < nn; ++i) cout << b2[i];
		//cout << endl;
		for (int i = 0; i < 51; ++i) memset(matrix[i], 0, sizeof(int) * 51);
		std::cout << "POSSIBLE" << std::endl;
		int pos = B - 1 - (B - nn - 1);
		for (int j = 0; j < nn && pos > 0; ++j, pos--){
			matrix[0][pos] = 1;
			for (int k = 0; k <= j; ++k){
				if (pos != B - k - 1)
					matrix[pos][B - k - 1] = b2[nn - k - 1];
			}
		}
		if (M > 0) matrix[0][B - 1] = 1;
		for (int i = 0; i < B; ++i){
			for (int j = 0; j < B; ++j) {
				std::cout << matrix[i][j];
			}
			std::cout << endl;
		}
	}
	return 0;
}
