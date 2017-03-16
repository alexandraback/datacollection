#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

int A[100][100];
int R[100];
int C[100];
int m, n;
bool can() {
    for (int i=0; i<m; ++i) {
        R[i] = 0;
        for (int j=0; j<n; ++j) {
            R[i] = max(R[i], A[i][j]);
        }
    }
    for (int j=0; j<n; ++j) {
        C[j] = 0;
        for (int i=0; i<m; ++i) {
            C[j] = max(C[j], A[i][j]);
        }
    }
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if (A[i][j]<R[i] && A[i][j]<C[j]) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    cin.sync_with_stdio(false);
    int ntests;
    scanf("%d", &ntests);
    for (int testcase=1; testcase<=ntests; ++testcase) {
        scanf("%d %d", &m, &n);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                scanf("%d", &A[i][j]);
            }
        }
        printf("Case #%d: %s\n", testcase, can() ? "YES" : "NO");
    }
	return 0;
}
