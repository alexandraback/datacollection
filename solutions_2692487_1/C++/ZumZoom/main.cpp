#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int main(int argc, const char * argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		int A, N;
		cin >> A >> N;
		vector <int> M(N);
		for(int i = 0; i < N; ++i)
			cin >> M[i];

		if(A == 1) {
			cout << "Case #" << t + 1 << ": " << N << endl;
			continue;
		}

		sort(M.begin(), M.end());
		int ans = N, count = 0;
		for(int i = 0; i < N; ++i) {
			while(M[i] >= A) {
				A += A - 1;
				++count;
			}
			A += M[i];
			ans = min(ans, count + N - i - 1);
		}

		cout << "Case #" << t + 1 << ": " << ans << endl;
	}
    
    return 0;
}
