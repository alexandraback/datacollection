#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <numeric>
#include <array>
#include <map>
#include <set>
#include <unordered_map>
#include <functional>
#include <iostream>
#include <thread>
#include <sstream>
#include <atomic>

using namespace std;


set<vector<long long> > S;


int main () {
	int T;
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		char S[1024];
		scanf("%s", S);

		string res;
		
		for (char *c=S; *c; c++) {
			res=max(*c+res, res+*c);
		}
		
		printf("Case #%d: %s\n", t, res.c_str());
	}
	return 0;
}
