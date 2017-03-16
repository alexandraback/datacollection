#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cassert>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

const double epsilon = 1e-7;

int main(){
    int T;
    cin >> T;
    for (int t = 0; t < T; t++){
		int A, B, K, res = 0;
		cin >> A >> B >> K;
		for (int a = 0; a < A; a++)
			for (int b = 0; b < B; b++)
				if ((a & b) < K)
					++res;
		cout << "Case #" << t+1 << ": " << res << endl;
    }
    return 0;
}
