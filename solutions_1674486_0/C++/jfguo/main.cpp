#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
using namespace std;

typedef long long LL;
typedef unsigned int UINT32;

int g[1001][1001];

string calc()
{
    int N;
    cin >> N;

    memset(g, 0, sizeof(g));
    int i, j;
    for (i = 0; i < N; ++i) {
        int M;
        cin >> M;
        int a;
        for (j = 0; j < M; ++j) {
            cin >> a;
            g[a-1][i] = 1;
        }
    }


    vector<int> inorder(N, 0);
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            if (g[i][j]) inorder[j]++;
        }
    }

    queue<int> q;
    for (i = 0; i < N; ++i) {
        if (inorder[i] == 0) {
            q.push(i);
        }
    }

    vector<int> seq;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        seq.push_back(cur);
        for (i = 0; i < N; ++i) {
            if (g[cur][i]) {
                inorder[i]--;
                if (inorder[i] == 0) {
                    q.push(i);
                }
            }
        }
    }

    for (int k = 0; k < N; ++k) {
        vector<int> num(N, 0);
        num[k] = 1;

        for (i = 0; i < N; ++i) {
            int cur = seq[i];
            for (j =0; j<N; ++j) {
                if (g[cur][j]) {
                    num[j] += num[cur];
                    if (num[j] >= 2) {
                        return "Yes";
                    }
                }
            }
        }
    }

    return "No";
}

int main(void)
{
	int N;
	cin >> N;

    //string line;
    //getline(cin, line);
	for (int i=1; i<=N; ++i) {
		cout << "Case #" << i << ": " << calc() << endl;
	}

	return 0;
}
