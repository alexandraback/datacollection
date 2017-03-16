#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;


int search(int init, int curChainLength, int cur, int prev, int pprev, int n, int f[], bool visited[]) {
    int ans = 0;
    if (visited[cur]) {
        if (cur == pprev) {
            // start a new chain
            for (int i = 0; i < n; ++i) {
                if (!visited[i])
                    ans = max(ans, search(init, 0, i, prev, pprev, n, f, visited));
            }
            ans += curChainLength;
        } else {
            if (cur == init)
                ans = curChainLength;
            else
                ans = 0;
        }
    } else {
        visited[cur] = true;
        ans = search(init, curChainLength + 1, f[cur], cur, prev, n, f, visited);
        visited[cur] = false;
    }
    return ans;
}

void work(ifstream & fin, ofstream & fout, int caseno) {
    int n;
    fin >> n;
    int f[n];
    for (int i = 0; i < n; ++i) {
        fin >> f[i];
        --f[i];
    }
    bool visited[n] = {};
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, search(i, 0, i, -1, -1, n, f, visited));
    fout << "Case #" << caseno << ": " << ans << endl;
}

int main() {
	ifstream fin;
	fin.open("input");
	ofstream fout;
	fout.open("output");
	int testcase;
	fin >> testcase;
	for (int i = 0; i < testcase; ++i) {
		work(fin, fout, i + 1);
	}
	fin.close();
	fout.close();
	return 0;
}
