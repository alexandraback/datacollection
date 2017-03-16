#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <utility>
#include <cstring>
#include <list>
#include <stack>
#include <vector>
using namespace std;


typedef long long LL;



int main(){
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;
	cin >> T;
	for (int caseID = 1; caseID <= T; ++caseID) {
		printf("Case #%d: ", caseID);
		int J, P, S, K;
		cin >> J >> P >> S >> K;
		map<pair<int, int>, int> counting;
		vector<vector<int> > res;
		for (int i = 1; i <= J; ++i) {
			for (int j = 1; j <= P; ++j) {
				pair<int, int> p1(i, 100 + j);
				for (int k = 1; k <= S; ++k) {
					pair<int, int> p2(i, 10000 + k), p3(100 + j, 10000 + k);
					if (counting[p1] < K && counting[p2] < K && counting[p3] < K) {
						++counting[p1];
						++counting[p2];
						++counting[p3];
						vector<int> v(3);
						v[0] = i;
						v[1] = j;
						v[2] = k;
						res.push_back(v);
					}
				}
			}
		}
		printf("%d\n", res.size());
		for (int i = 0; i < res.size(); ++i) {
			printf("%d %d %d\n", res[i][0], res[i][1], res[i][2]);
		}
	}
}