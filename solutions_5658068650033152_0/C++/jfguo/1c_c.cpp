#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

int N, M, K;
vector<vector<int> > grid;

int calc(int n, int need) {
    int a = 4;
    int b = 5;

    a += (n-3)*2;
    b += (n-3)*n;

    for (int i = 3; i <= M; ++i) {
        if (need <= b) {
            return a;
        } else if (need == b+1) {
            return a + 1;
        }

        a += 2;
        b += n;
    }

    a -= 2;
    b -= n;

    return a+need-b;
}

int calc()
{
    cin >> N >> M >> K;
    if (N > M) swap(N, M);
    if (N <= 2) return K;

    int ans = K;
    for (int i = 3; i <= N; ++i) {
        ans = min(ans, calc(i, K));
    }
    return ans;

    /*
    vector<int> selected(N*M, 0);
    for (int i = 1; i <= K; ++i) {
        selected[N*M-i] = 1;
    }

    grid.resize(N);
    for (int i = 0; i < N; ++i) {
        grid[i].resize(M);
    }


    int ans = K;
    do {
        for (int i = 0; i < N; ++i) for (int j = 0; j <= M; ++j) {
            grid[i][j] = selected[i*M+j];
        }
        
    } while (next_permutation(selected.begin(), selected.end()));
    */
}

int main(void)
{
	int T;
	cin >> T;
	//getline(cin, line);
	for (int ca=1; ca<=T; ++ca) {
		//getline(cin, line);
		cout << "Case #" << ca << ": " << calc() << endl;
	}
	return 0;
}
